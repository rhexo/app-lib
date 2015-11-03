#ifndef _PRINTER_H
#define _PRINTER_H

#include <list>
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

  // print
  template<template<class E, class All = allocator<E> > class C, typename T>
  void collection( const C<T>& coll, const string& head, bool lf) {

    // print head of print sentence
    cout << head;
    // print elements
    copy(coll.cbegin(), coll.cend(),
         ostream_iterator<T>(cout, " "));
    //new line at end of sentence?
    if (lf == true)
      cout << endl;
  }


  // template <typename T>
  // void collection(const T& coll, const string& head, bool lf) const {

  //   // print head of print sentence
  //   cout << head;
  //   // print elements
  //   for(const auto& elem : coll)
  //     cout << elem;
  //   //new line at end of sentence?
  //   if (lf == true)
  //     cout << endl;
  // }


};

#endif
