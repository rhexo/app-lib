/** Example of using MPL numeric compute */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <boost/static_assert.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/lambda.hpp>

using namespace std;
using namespace boost::mpl::placeholders;
using namespace boost::mpl;

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
  typename lambda<F>::type,
  typename apply1<
    typename lambda<F>::type, X
    >::type
  >
{};



int main(){

  // twice with add_pointer_f to build pointers-to-pointers
  BOOST_STATIC_ASSERT((is_same<twice<add_pointer_f, int>::type,int**>::value));
  BOOST_STATIC_ASSERT((is_same<twice_2<add_pointer_f, int>::type,int**>::value));


  //  BOOST_STATIC_ASSERT((is_same<twice<add_pointer<_1>, int>::type,int**>::value)); // gets compilation error. To solve this add_pointer<X> should be wrapped in class wrapper
  // For generatiing metafunction class (class wrapepr) from add_pointer<_1> we can use lambda metafunction

  BOOST_STATIC_ASSERT((is_same<twice<lambda<add_pointer<_1>>::type, int>::type,int**>::value));

  // try twice_3 with implementing lamda metafunction wrapper
  BOOST_STATIC_ASSERT((is_same<twice_3<add_pointer<_1>, int>::type,int**>::value));


  exit(EXIT_SUCCESS);
};
