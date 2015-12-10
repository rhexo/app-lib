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
   * Generic wrapper for any integral type
   */

  template <class T, T N>
  struct integral_c {
    static const T value = N;
    typedef integral_c<T,N> type;

    typedef T value_type;

    typedef integral_c<T,N+1> next;
    typedef integral_c<T,N-1> prior;

    operator T() const {return N;}
  };

  /**
   * boost equal_to copy
   */
  template <class T1, class T2>
  struct equal_to
    : mpl::bool_<(T1::value == T2::value)>
  {};

};
