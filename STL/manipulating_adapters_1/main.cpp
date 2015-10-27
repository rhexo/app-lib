#include <algorithm>
#include <iterator>
#include <list>
#include <iostream>
#include <cstdlib>

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

  exit(EXIT_SUCCESS);

};
