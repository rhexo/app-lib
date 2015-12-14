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
#include "include/own_sequences.hpp"

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


  /**
   * Own sequences section
   */

  typedef mpl::tiny<mpl::int_<10>,mpl::int_<20>,mpl::int_<30> > S;

  // pop front element of S, unless it`s empty
  typedef mpl::eval_if<
    mpl::empty<S>,
    mpl::identity<S>,
    mpl::pop_front<S>
    >::type r1;

  // likewise
  typedef mpl::eval_if<
    mpl::empty<S>,
    S,  // when invoked, S return S
    mpl::pop_front<S>
    >::type r2;


  cout << "Tiny.at<2> = " << mpl::at<S,mpl::int_<2> >::type::value << endl;

  exit(EXIT_SUCCESS);
};
