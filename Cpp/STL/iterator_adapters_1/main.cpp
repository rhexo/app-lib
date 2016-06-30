#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

  /**
   * introduce the following iterator adapters:
   * 1. Insert iterators
   * 2. Stream iterators
   * 3. Reverse iterators
   * 4. Move iterators
   */


  /** Insert iterators */

  list<int> i1_coll1{1,2,3,4,5,6,7,8,9};

  // copy elements of coll1 into coll2 by appending them
  vector<int> i1_coll2;
  copy(i1_coll1.cbegin(), i1_coll1.cend(),   // source
       back_inserter(i1_coll2));          // destinatio

  cout << "print i1_coll2: " << endl;
  for(const auto& elem : i1_coll2)
    cout << elem << " ";
  cout << endl;

  // copy elements of coll1 into coll3 by inserting them at the front
  // - reverse the order of the elements
  deque<int> i1_coll3;
  copy(i1_coll1.cbegin(), i1_coll1.cend(),   // source
       front_inserter(i1_coll3));         // destination

  cout << "print i1_coll3: " << endl;
  for(const auto& elem : i1_coll3)
    cout << elem << " ";
  cout << endl;

  // copy elements of coll1 into coll4
  // - only inserter that works for associative collections
  set<int> i1_coll4;
  copy(i1_coll1.cbegin(), i1_coll1.cend(),   // source
       inserter(i1_coll4,i1_coll4.begin())); // destination

  cout << "print i1_coll4: " << endl;
  for(const auto& elem : i1_coll4)
    cout << elem << " ";
  cout << endl;


  /** Stream iterators */

  vector<string> i2_coll;

  cout << "input words for stream iterator tests:" << endl;
  // read all words from standard input
  // - source: all strings until end-of-file (or error)
  // - destination: coll(inserting)
  copy(istream_iterator<string>(cin),    // start of source
       istream_iterator<string>(),       // end of source
       back_inserter(i2_coll));          // destination

  // sort elements
  sort(i2_coll.begin(), i2_coll.end());

  cout << endl;  // little tune

  // print all elements without duplicates
  // - source: coll
  // - destination: standard output(with newline between elements)
  unique_copy(i2_coll.cbegin(),                       // source: start
              i2_coll.cend(),                         // source: end
              ostream_iterator<string>(cout, "\n"));  // destination


  /** Reverse iterators */

  vector<int> i3_coll;

  // insert elements from 1 to 9
  for (int i=1; i <= 9; ++i) {
    i3_coll.push_back(i);
  }

  // print all elements in reverse order
  copy(i3_coll.crbegin(),i3_coll.crend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;


  /** Move iterators */

  vector<string> i4_coll {"some", "application", "example", "words"};
  vector<string> i4_coll_move;

  // initialize vector size for valid copy process
  i4_coll_move.resize(i4_coll.size());

  // print state of vectors befor move
  cout << endl << "i4_coll contents: ";
  copy(i4_coll.cbegin(),i4_coll.cend(),
       ostream_iterator<string>(cout, " "));
  cout << endl << "i4_coll_move contents: ";
  copy(i4_coll_move.cbegin(),i4_coll_move.cend(),
       ostream_iterator<string>(cout, " "));

  // move elements of vector i4_coll into vector i4_coll_move
  copy(make_move_iterator(i4_coll.begin()),
       make_move_iterator(i4_coll.end()),
       i4_coll_move.begin());

  cout << endl << "after move:";
  cout << endl << "i4_coll result: ";
  copy(i4_coll.cbegin(),i4_coll.cend(),
       ostream_iterator<string>(cout, " "));
  cout << endl << "i4_coll_move result: ";
  copy(i4_coll_move.cbegin(),i4_coll_move.cend(),
       ostream_iterator<string>(cout, " "));

  exit(EXIT_SUCCESS);

};
