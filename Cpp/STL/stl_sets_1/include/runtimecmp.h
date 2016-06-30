#ifndef RUNTIMECMP_H
#define RUNTIMECMP_H

#include <iostream>
#include <set>

#include "printer.h"


using namespace std;

// type for runtime sorting criterion
class RuntimeCmp {

public:
  enum cmp_mod {normal, reverse};

private:
  cmp_mod mode;

public:

  // constructor for sorting criterion
  // - default criterion uses value normal
  RuntimeCmp (cmp_mod = normal);

  //comparion of elements
  // - member function for any element type
  template <typename T>
  bool operator() (const T& t1, const T& t2) const {
    return mode == normal ? t1 < t2 : t2 < t1;
  }

  // comparsion of sorting criteria
  bool operator== (const RuntimeCmp& ) const;

};

#endif
