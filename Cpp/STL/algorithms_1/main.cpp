#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>

using namespace std;


int main () {

  // create vector with elements 1 to 6 in arbitary order
  vector<int> vect = {2, 5, 4, 1, 6, 3};

  // find and print minimum and maximum elements
  auto minpos = min_element(vect.cbegin(), vect.cend());
  cout << "min: " << *minpos << endl;
  auto maxpos = max_element(vect.cbegin(), vect.cend());
  cout << "max: " << *maxpos << endl;

  // sort all elements
  sort(vect.begin(), vect.end());

  // find first element with value 3
  //  - no cbegin()/cend() because later we modify the elements pos3 refers to
  auto pos3 = find(vect.begin(), vect.end(), 3);

  // reverse the order of the found element with value 3 and all following elements
  reverse(pos3, vect.end());

  // print all elements
  for (auto elem : vect) {
    cout << elem << " ";
  }
  cout << endl;


  /** RANGEs */
  auto pos = find_if(vect.begin(), vect.end(),
                     [] (int i) {  // use lambda as criterion function
                       return i == 6 || i == 5;
                     });

  //cursor definition for ranges elements
  auto pos6 = pos;
  auto pos5 = pos;

  if (pos == vect.end()) {
    // no elements with value 6 or 5
  } else if (*pos == 6) {
    // element with value 6 comes first
    pos6 = pos;
    pos5 = find(++pos, vect.end(), 5);

    cout << "first " << *pos6 << " than " << *pos5 << endl; // this is selected
  } else {
    // element with value 5 comes first
    pos5 = pos;
    pos6 = find(++pos, vect.end(), 6);

    cout << "first " << *pos5 << " than " << *pos6 << endl;
  }

  /** Handling multiple ranges */
  list<decltype(vect)::value_type> lcop; // define list on decltype of vect::value_type

  /**
   * When call algorithms for multiple ranges, make sure that the second and
   * additional ranges have at least as many elements as the first range
   */
  lcop.resize(vect.size());

  // copy elements of one collection to another
  // - overwrite existing elements in destination
  copy(vect.cbegin(), vect.cend(), lcop.begin());

  // print copied elements
  cout << "print copied elements form vect: " << endl;
  for( const auto& elem : lcop){
    cout << elem << " ";
  }
  cout << endl;


  exit(EXIT_SUCCESS);

};
