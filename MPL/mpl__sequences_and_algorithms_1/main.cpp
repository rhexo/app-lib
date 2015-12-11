/** Example of using MPL high order function */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <boost/static_assert.hpp>
#include "include/sequences.hpp"
#include "include/iterators.hpp"
#include "include/classes.hpp"
#include "include/integral_swrappers.hpp"

using namespace std;
namespace mpl=boost::mpl;

int main(){

  cout << boolalpha << endl;

  // deq data:
  // typedef mpl::vector<char,short,int,long,float,double> types;

  cout << "*Sequences and algorithms*" << endl;
  // Check iterator position
  BOOST_STATIC_ASSERT((!is_same<seq::long_pos,seq::finish>::value));
  cout << "long_pos and finish compare: " << is_same<seq::long_pos,seq::finish>::value << endl;
  cout << "long_pos and finish compare(2): " << is_same<seq::long_pos2,seq::finish2>::value << endl;

  cout << endl;
  cout << "*Iterators*" << endl;
  // check that we have expected result
  BOOST_STATIC_ASSERT((is_same<seq::x,long>::value));
  cout << "seq::x and long compare: " << is_same<seq::x,long>::value << endl;

  // check next
  BOOST_STATIC_ASSERT((is_same<seq::y,float>::value));
  cout << "seq::y and float compare: " << is_same<seq::y,float>::value << endl;

  exit(EXIT_SUCCESS);
};
