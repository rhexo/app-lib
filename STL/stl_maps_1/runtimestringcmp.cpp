#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include "include/runtimestringcmp.h"

using namespace std;

// --
RuntimeStringCmp::RuntimeStringCmp(cmp_mode m): mode(m) {}

// --
bool RuntimeStringCmp::nocase_compare(char c1, char c2)
{
  return toupper(c1) < toupper(c2);
}

// --
bool RuntimeStringCmp::operator()(const string & s1, const string & s2) const
{
  if (mode == normal) {
    return s1<s2;
  }
  else {
    return lexicographical_compare(s1.begin(), s1.end(),
                                   s2.begin(), s2.end(),
                                   nocase_compare
                                   );
  }
}
