#include <set>
#include <iostream>

#include "include/runtimecmp.h"
#include "include/printer.h"

using namespace std;

// constructor implementation
RuntimeCmp::RuntimeCmp(cmp_mod m) : mode(m) {}

// comparsion of sorting criteria implementation
bool RuntimeCmp::operator==(const RuntimeCmp &rc) const {
  return mode == rc.mode;
}
