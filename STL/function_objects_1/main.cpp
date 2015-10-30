#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <deque>
#include <functional>
#include "include/printer.h"

using namespace std;

int main() {


  /** Definitions of function objects */

  vector<int> i1_coll;

  // insert elements from 1 to 9
  for(int i=1; i<=9; ++i){
    i1_coll.push_back(i);
  }

  // print all elements
  cout << "print all elements" << endl;
  for_each(i1_coll.cbegin(), i1_coll.cend(),  // range
           Printer());                        // operation ()
  cout << endl;

  // call with instance, i.e. add 10 for each element from collection
  Printer p(10);

  cout << "using instance for print" << endl;
  for_each(i1_coll.cbegin(), i1_coll.cend(),
           p );   // Printer(10) give the same result
  cout << endl;


  /** Predefined function objects */

  deque<int> i2_coll {1,2,3,5,7,11,13,17,19};

  cout << "src: ";
  // print collection of elements
  copy(i2_coll.cbegin(),i2_coll.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  // negate all value in i2_coll (unary form of transformation)
  transform(i2_coll.cbegin(), i2_coll.cend(),    // source
            i2_coll.begin(),                     // destination
            negate<int>());                      // operation

  cout << "negated: ";
  copy(i2_coll.cbegin(),i2_coll.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  // square all elements in i2_coll (binary form of transformation)
  transform(i2_coll.cbegin(), i2_coll.cend(),    // first source
            i2_coll.cbegin(),                    // second source (the same collection x*x logic)
            i2_coll.begin(),                     // the same collection as result of transform
            multiplies<int>());                  // operation - multiply

  cout << "squared: ";
  copy(i2_coll.cbegin(),i2_coll.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;


  /** Binders */



  exit(EXIT_SUCCESS);
};
