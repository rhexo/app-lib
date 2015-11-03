/** Example of using vectors */
#include <list>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cstdlib>

#include "include/printer.h"

using namespace std;

int main() {

  // create two empty lists
  list<int> list1, list2;

  // fill both lists with elements
  for (int i=0; i<6; ++i){
    list1.push_back(i);
    list2.push_front(i);
  }

  Printer().collection(list1, "list1: ", true);
  Printer().collection(list2, "list2: ", true);

  // insert all elements of list1 before the first element with value 3 of list2
  // - find() returns an iterator to the first element with value 3

  list2.splice(find(list2.begin(), list2.end(),   // destination position
                    3),
               list1);                            // source list

  Printer().collection(list1, "list1(1):", true);
  Printer().collection(list2, "list2(1):", true);

  // move first element of list2 to the end
  list2.splice(list2.end(),                       // destination position
               list2,                             // source list
               list2.begin());                    // source position

  Printer().collection(list1, "list1(2):", true);
  Printer().collection(list2, "list2(2):", true);

  // sort second list, assign to list1 and remove duplicates
  list2.sort();
  list1 = list2;
  list2.unique();

  Printer().collection(list1, "list1(3):", true);
  Printer().collection(list2, "list2(3):", true);

  // merge both sorted lists into the first list (merge with sort criteria)
  list1.merge(list2);

  Printer().collection(list1, "list1(4):", true);
  Printer().collection(list2, "list2(4):", true);

  exit(EXIT_SUCCESS);
};
