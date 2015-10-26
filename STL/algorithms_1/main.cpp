#include <algorithm>
#include <vector>
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


};
