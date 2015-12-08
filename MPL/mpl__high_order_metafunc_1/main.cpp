/** Example of using MPL high order function */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <boost/static_assert.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/multiplies.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/apply.hpp>


using namespace std;
using namespace boost::mpl::placeholders;

//using namespace boost;
namespace mpl  = boost::mpl;

// definition of high order metafunction (metafunction class)
template <class F, class X>
struct twice
{
  typedef typename F::template apply<X>::type once;    // f(x)
  typedef typename F::template apply<once>::type type;   // f(f(x))
};

// defining the same high order metafunction by metafunction forwarding
template <class F, class X>
struct twice_2 : F::template apply<typename F::template apply<X>::type> {};


// class wrapper for add_pointer
struct add_pointer_f
{
  template <class T>
  struct apply : add_pointer<T> {};
};

template <class UnaryMetaFunctionClass, class Arg>
struct apply1
  : UnaryMetaFunctionClass::template apply<Arg>
{};

template <class F, class X>
struct twice_3
  : apply1<
  typename mpl::lambda<F>::type,
  typename apply1<
    typename mpl::lambda<F>::type, X
    >::type
  >
{};

// Some metafunction classes
template <class A, class B>
struct plus_
  : mpl::apply<
  mpl::plus<_1,_2>,
  A,
  B
  >

{};

template <class A, class B>
struct plus2_
  : mpl::lambda <
  typename mpl::plus<A,B>::type
  >

{};

template <class A, class B>
struct metafunc_comp_1
  : mpl::apply<
  mpl::multiplies<
    mpl::plus<_1, _2>,
    mpl::minus<_1, _2>
    >,
  A,
  B
  >
{};

/**
 * Definition of lazy evaluation. A C++ template is not instantiated until we actualy "look inside it"
 * Just naming calc_ptr_seq does not cause it to be evaluated, since we haven't accessed int type yet.
 */

typedef mpl::vector<int, char*, double&> seq;
typedef mpl::transform<seq, add_pointer<_1>> calc_ptr_seq;


int main(){

  // twice with add_pointer_f to build pointers-to-pointers
  BOOST_STATIC_ASSERT((is_same<twice<add_pointer_f, int>::type,int**>::value));
  BOOST_STATIC_ASSERT((is_same<twice_2<add_pointer_f, int>::type,int**>::value));


  //  BOOST_STATIC_ASSERT((is_same<twice<add_pointer<_1>, int>::type,int**>::value)); // gets compilation error. To solve this add_pointer<X> should be wrapped in class wrapper
  // For generatiing metafunction class (class wrapepr) from add_pointer<_1> we can use lambda metafunction

  BOOST_STATIC_ASSERT((is_same<twice<mpl::lambda<add_pointer<_1>>::type, int>::type,int**>::value));

  // try twice_3 with implementing lamda metafunction wrapper
  BOOST_STATIC_ASSERT((is_same<twice_3<add_pointer<_1>, int>::type,int**>::value));


  cout << "mpl::plus_ <5>, <10>: " << plus_<mpl::int_<5>,mpl::int_<10>>::type::value << endl;

  // try metafunction composition
  cout << "mult<plus<_,_>,minus<_,_>,<5>,<10>>: " << metafunc_comp_1<mpl::int_<5>, mpl::int_<10> >::type::value << endl;

  exit(EXIT_SUCCESS);
};
