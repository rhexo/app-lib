/** Example of using sets and multisets */
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cstdlib>

#include "include/printer.h"
#include "include/runtimecmp.h"

using namespace std;

int main(){

  /** Some futures of sets and multisets */

  // type of the collection:
  // - no duplicates
  // - elements are integral values
  // - descending order
  set<int,greater<int>> i1_coll1;

  // insert elements in random order using different member functions
  i1_coll1.insert({4,3,5,1,6,2});
  i1_coll1.insert(5);

  // print all elements
  Printer().collection(i1_coll1, "set initialize: ", true);

  // insert 4 again and process return status
  auto status = i1_coll1.insert(4);
  if (status.second) {
    cout << "4 inserted as element "
         << distance(i1_coll1.cbegin(), status.first) + 1 << endl;
  } else {
    cout << "4 alrady exists" << endl;
  }

  // assign elemenst to another set with ascending order
  set<int> i1_coll2(i1_coll1.cbegin(),i1_coll1.cend());

  // print all elements
  Printer().collection(i1_coll2, "i1_coll2: ", true);

  // remove all elements up to element with value 3
  i1_coll2.erase(i1_coll2.begin(), i1_coll2.find(3));

  // remove all elements with value 5
  int num;
  num = i1_coll2.erase(5);
  cout << num << " element(s) removed" << endl;

  Printer().collection(i1_coll2, "i1_coll2 (result): ", true);


  /** Example the specifying the Sorting Criterion at Runtime */

  // set with custom sorting criterion
  typedef set<int,RuntimeCmp> IntSet;

  // create, fill and print set with normal element order
  // - uses default sorting criterion
  IntSet i2_coll1 {4,7,5,1,6,2,5};

  Printer().collection(i2_coll1,"IntSet initialize: ", true);

  // craeting sorting criterion with reverse element order
  RuntimeCmp reverse_order(RuntimeCmp::reverse);

  // create, fill and print set with reverse element order
  IntSet i2_coll2(reverse_order);
  i2_coll2 = {4,7,5,1,6,2,5};

  Printer().collection(i2_coll2,"IntSet reverse: ", true);

  // assign elements AND sorting criterion
  i2_coll1 = i2_coll2;
  i2_coll1.insert(3);

  Printer().collection(i2_coll1, "IntSet assign: ", true);

  // just to make sure ...
  if (i2_coll1.value_comp() == i2_coll2.value_comp()) {
    cout << "i2_coll1 and i2_coll2 have the same sorting criterion" << endl;
  } else {
    cout << "i2_coll1 and i2_coll2 have a different sorting criterion" << endl;
  }

  exit(EXIT_SUCCESS);
};
