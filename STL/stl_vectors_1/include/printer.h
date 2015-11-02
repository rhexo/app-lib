#ifndef _PRINTER_H
#define _PRINTER_H

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

  // Print collection template
  template <class C>
  void collection(const C& coll, const string& head, bool lf) const
  {
    cout << head;

    //print collection
    for (const auto& elem : coll) {
      cout << elem << " ";
    }

    if (lf == true)
      cout << endl;
  }

};

#endif
