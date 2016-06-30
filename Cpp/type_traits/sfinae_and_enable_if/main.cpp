/** Example of using MPL algorithms */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <memory>


using namespace std;

// Eli Bendersky`s - Variadic templates tutorial
// dumping a c objects memory layout with clang : 
//   clang -c myfile.cpp -stc++11 -Xclang -fdump-record-layouts > dump.txt
// sometimes easy way is to be using preparsed sources:
//   clang -E [-I<path to include, usualy system includes>] [-std=c++11] myfile.cpp > myfile_pp.cpp

/** some helper structures for forwarding example */

int main()
{  
  cout << std::boolalpha << endl;


  exit(EXIT_SUCCESS);
}
