/** Example of using MPL algorithms */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <boost/static_assert.hpp>
// #include <boost/mpl/vector/vector10.hpp>
#include <boost/mpl/vector.hpp>
// #include <boost/mpl/is_same.hpp>
#include "include/algorithms.hpp"


using namespace std;
namespace mpl = boost::mpl;

int main()
{

  typedef mpl::vector<int,char,float,float,long,long double> S;
  typedef seq::biggest_float_as_double<S>::type result;

  cout << boolalpha;
  // result is: true
  cout << "Is result type is long double? " << is_same<result,long double>::value << endl;

  exit(EXIT_SUCCESS);
}
