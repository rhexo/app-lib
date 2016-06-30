#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <deque>
#include <functional>
#include "include/printer.h"

using namespace std;
using namespace std::placeholders;

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

  Printer().collection<deque<int>>(i2_coll,"src: ");
  cout << endl;

  // negate all value in i2_coll (unary form of transformation)
  transform(i2_coll.cbegin(), i2_coll.cend(),    // source
            i2_coll.begin(),                     // destination
            negate<int>());                      // operation

  Printer().collection<deque<int>>(i2_coll,"negate: ");
  cout << endl;

  // square all elements in i2_coll (binary form of transformation)
  transform(i2_coll.cbegin(), i2_coll.cend(),    // first source
            i2_coll.cbegin(),                    // second source (the same collection x*x logic)
            i2_coll.begin(),                     // the same collection as result of transform
            multiplies<int>());                  //   operation - multiply

  Printer().collection<deque<int>>(i2_coll,"squared: ");
  cout << endl;


  /** Binders */

  set<int,greater<int>> i3_coll1 {1,2,3,4,5,6,7,8,9};
  deque<int> i3_coll2;

  // Note: due to the sorting criterion greater<>() elements have reverse order:
  Printer().collection<set<int,greater<int>>>(i3_coll1,"initialized: ");
  cout << endl;

  // transform all elements into i3_coll2 by multiplying them with 10
  transform(i3_coll1.cbegin(), i3_coll1.cend(),  // source
            back_inserter(i3_coll2),             // destination
            bind(multiplies<int>(),_1,10));      // operation

  Printer().collection<deque<int>>(i3_coll2, "transformed: ");
  cout << endl;

  // replace value equal to 70 with 42
  replace_if(i3_coll2.begin(), i3_coll2.end(),   // range
             bind(equal_to<int>(),_1,70),        // replace criterion
             42);                                // new value

  Printer().collection<deque<int>>(i3_coll2, "replaced: ");
  cout << endl;

  // remove all elements with values between 50 and 80
  i3_coll2.erase(remove_if(i3_coll2.begin(), i3_coll2.end(),
                           bind(logical_and<bool>(),
                                bind(greater_equal<int>(),_1,50),
                                bind(less_equal<int>(),_1,80))),
                 i3_coll2.end());

  Printer().collection<deque<int>>(i3_coll2, "removed:   ");
  cout << endl;

  exit(EXIT_SUCCESS);
};
