/** Example of using MPL algorithms */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>

#include "include/adder.hpp"
#include "include/pair_comparer.hpp"
#include "include/tuple.hpp"

using namespace std;

// Eli Bendersky`s - Variadic templates tutorial
// dumping a c objects memory layout with clang : 
//   clang -c myfile.cpp -stc++11 -Xclang -fdump-record-layouts > dump.txt
// sometimes easy way is to be using preparsed sources:
//   clang -E [-I<path to include, usualy system includes>] [-std=c++11] myfile.cpp > myfile_pp.cpp

int main()
{  
  cout << std::boolalpha << endl;

  cout << "adder function results:" << endl;
  // tests adder algorithm
  long sum = adder(1, 2, 3, 7, 8);
    
  cout << "pair_comparer function results:" << endl;
  // tests pair_comparer algorithm
  cout << pair_comparer(1.5, 1.5, 2, 2, 6, 6) << endl;
  cout << pair_comparer(1.5, 1.5, 2, 2, 6, 6, 7) << endl;
  
  cout << "tuple struct definition:" << endl;
  // tests tuple data structure
  data::tuple<double, uint64_t, const char *> t1(12.2, 42, "big");
  
  cout << "0th elem is " << data::get<0>(t1) << endl;
  cout << "1th elem is " << data::get<1>(t1) << endl;
  cout << "2th elem is " << data::get<2>(t1) << endl;
  
  get<1>(t1) = 103;
  cout << "1th elem is " << data::get<1>(t1) << endl;

  exit(EXIT_SUCCESS);
}
