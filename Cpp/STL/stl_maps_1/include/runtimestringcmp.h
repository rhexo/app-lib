#ifndef _RUNTIMESTRINGCMP_H
#define _RUNTIMESTRINGCMP_H

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// function object to compare strings
// - allows you to set the comparsion criterion at runtime
// - allows you to compare case insensitive
class RuntimeStringCmp {
public:
  // constant for the comparsion criterion
  enum cmp_mode {normal, nocase};

private:
  // actual comparsion mode
  const cmp_mode mode;

  // auxiliary function to compare case insensitive
  static bool nocase_compare(char, char);

public:

  // constructor: initializes the comparsion criterion
  RuntimeStringCmp(cmp_mode = normal);

  // the comparsion
  bool operator() (const string&, const string&) const;

};

#endif
