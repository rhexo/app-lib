/** Example of using MPL high order function */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <boost/static_assert.hpp>
#include "include/bool_wrapper.hpp"
#include "include/integer_wrapper.hpp"


using namespace std;
namespace mpl=boost::mpl;

int main(){

  cout << boolalpha << endl;


  cout << "*Integral wrappers section*" << endl;
  cout << "is_same: " << is_same<mpl::int_<11>, wrapper::integral_c<int, 11>>::value << endl;
  cout << "equal_to: " << wrapper:: equal_to<mpl::int_<11>, wrapper::integral_c<int, 11>>() << endl;

  exit(EXIT_SUCCESS);
};
