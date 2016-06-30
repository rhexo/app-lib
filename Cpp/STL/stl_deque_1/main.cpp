/** Example of using vectors */
#include <deque>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cstdlib>

#include "include/printer.h"

using namespace std;

int main () {

  // create empty deque of strings
  deque<string> coll;

  // insert several elements
  coll.assign(3, string("string"));
  coll.push_back("last string");
  coll.push_front("first string");

  // print elements separated by newlines
  Printer().collection(coll, string("Print deque: "), true);

  // remove first and last element
  coll.pop_front();
  coll.pop_back();

  // insert 'another' into every element but the first
  for (unsigned i=1; i<coll.size(); ++i){
    coll[i] = "another " + coll[i];
  }

  // change size to four elements
  coll.resize(4, "resize string");

  Printer().collection(coll, "print result: ", true);

  exit(EXIT_SUCCESS);

};
