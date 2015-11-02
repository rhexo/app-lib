#ifndef _PRINTER_H
#define _PRINTER_H


#include <deque>
#include <vector>
#include <array>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;


class Printer {
public:

  // int adaptor (add value to printed int values)
  int _int_adaptor;

  // Constructor
  Printer(int = 0);

  // Function object
  void operator()(int) const;

  // deque print
  template <class T> void collection( const deque<T>& coll, const string& head, bool lf) const {

    // print head of print sentence
    cout << head;
    // print elements
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<T>(cout, " "));
    //new line at end of sentence?
    if (lf == true)
      cout << endl;
  }

  // vector print
  template <class T> void collection( const vector<T>& coll, const string& head, bool lf) const {

    // print head of print sentence
    cout << head;
    // print elements
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<T>(cout, " "));
    //new line at end of sentence?
    if (lf == true)
      cout << endl;
  }

  // array print
  template <class T, int N> void collection( const array<T,N>& coll, const string& head, bool lf) const {

    // print head of print sentence
    cout << head;
    // print elements
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<T>(cout, " "));
    //new line at end of sentence?
    if (lf == true)
      cout << endl;
  }


};

#endif
