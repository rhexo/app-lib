/** Example of using arrays */
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include "include/printer.h"
#include <cstdlib>

using namespace std;

int main() {

  // create array with 10 ints
  array<int,10> a{11, 22, 33, 44};

  // print
  Printer().collection<array<int,10>>(a, "Initialized a with: ", true);

  // modify last two elements
  a.back() = 9999999;
  a[a.size()-2] = 42;

  // print
  Printer().collection<array<int,10>>(a, "Midify last two elem: ", true);

  // process summ of all elements
  cout << "sum: "
       << accumulate(a.begin(), a.end(), 0)
       << endl;

  // negate all elements
  transform(a.begin(), a.end(),     // source
            a.begin(),              // destination
            negate<int>());         // operation

  // print
  Printer().collection<array<int,10>>(a, "Transform array: ", true);

  exit(EXIT_SUCCESS);

};
