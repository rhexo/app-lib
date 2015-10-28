#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;

int main () {

  /** Removing elements */

  list<int> i1_coll;

  // insert elements from 6 to 1 and 1 to 6
  for (int i=1; i <= 6; ++i) {
    i1_coll.push_front(i);
    i1_coll.push_back(i);
  }

  // prints all elements of the collection
  cout << "pre: ";
  copy(i1_coll.cbegin(), i1_coll.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  // remove all elements with value 3
  // - retain new end
  list<int>::iterator end = remove(i1_coll.begin(), i1_coll.end(), 3);

  // print resulting elements of the collection
  copy(i1_coll.begin(), end,
       ostream_iterator<int>(cout, " "));
  cout << endl;

  // print number of removed elements
  cout << "number of removed elements: "
       << distance(end, i1_coll.end()) << endl;

  // remove "removed" elements
  i1_coll.erase(end, i1_coll.end());

  // print all elements of the modified collection
  copy(i1_coll.cbegin(), i1_coll.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;


  /** Manipulating associative and unordered containers */

  // unordered set with elements form 1 to 9
  set<int> i2_coll {1,2,3,4,5,6,7,8,9};

  cout << "Remove from associative container: " << endl;
  // print all elements of the collection
  copy(i2_coll.cbegin(), i2_coll.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  // Remove all elements with value 3
  // algorithm remove does not work
  // instead member function erase works
  int num = i2_coll.erase(3);

  // print number of removed elements
  cout << "number of removed elements: " << num << endl;

  // print all elements of the modified collection
  copy(i2_coll.cbegin(),i2_coll.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  /** Algorithm versus member function */

  list<int> i3_coll;

  // insert elements from 6 to 1 and 1 to 6
  for (int i=1; i <= 6; ++i) {
    i3_coll.push_front(i);
    i3_coll.push_back(i);
  }

  // remove all elements with value 3 (poor performance)
  i3_coll.erase(remove(i3_coll.begin(), i3_coll.end(), 3), i3_coll.end());

  // remove all elements with value 4 (good performance)
  i3_coll.remove(4);

  // We should always prefer a mamber function over an algorithm if
  // good performance is the goal.

  exit(EXIT_SUCCESS);

};
