#include <type_traits>
#include <boost/mpl/if.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/is_stateless.hpp>

namespace wrapper {

  using namespace std;
  using namespace boost::mpl::placeholders;

  namespace mpl = boost::mpl;

  /**
   * Definition of MPL type wrapper for bool values
   */

  template <bool X>
  struct bool_
  {
    static bool const value = X;  // 1
    typedef bool_<X> type;  // 2
    typedef bool value_type;  // 3
    operator bool() const {return X;}  // 4

    /**
     * description of lines above
     *  1. integral constant wrapper contains a ::value
     *  2. every integral constant wrapper is a nullary metafunction that returns itself.
     *  3. the wrapper`s ::value_type indicates the (cv-unqualified) type of its ::value
     *  4. each bool_<X> specialization is quite naturally conertible to a bool of value x
     */
  };


  // Define two convenient typedefs
  typedef bool_<false> false_;
  typedef bool_<true> true_;


  /**
   * Type selection
   */

  // Boost defines metafunction param_type<T>, that returns T when it is scalar, and T const& otherwise.

  template <class T>
  struct param_type
    : mpl::if_<
    typename is_scalar<T>::type,
    T,
    typename boost::add_reference<T const>::type
    >
  {};

  // Define holder type, definition basing on param_type metafunction

  template <class T>
  struct holder
  {
  public:
    holder(typename param_type<T>::type x);

  private:
    T x;

  };


  /**
   * Lazy type selection
   * define lazy evaluation of type_param
   */

  template <class T>
  struct param_type_lazy
    :mpl::if_<      // forwarding to selected transformation
    typename is_scalar<T>::type,
    mpl::identity<T>,  // missing ::type. Compilation begins when type is accessed
    boost::add_reference<T const> // missing ::type. Compilation begins when type is accessed
    >
  {};


  /**
   * Logical operators "or_". If T is scalar, stateless or alrady has reference than return self (i.e. T)
   */

  template <class T>
  struct param_type_logic
    : mpl::eval_if<
    mpl::or_<
      boost::is_stateless<T>,
      mpl::or_<
        is_scalar<T>,
        is_reference<T>
        >
      >,
    mpl::identity<T>,
    add_lvalue_reference<T const>
    >
  {};

};
