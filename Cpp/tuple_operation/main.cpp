#include <printtuple.h>
#include <vector>
#include <tuple>
#include <iostream>
#include <complex>
#include <string>
#include <cstdlib>

using namespace std;

// define function foo
tuple<int,int,int> foo();

int main () {

  // Create four element touple
  // elements initialized with defauld value (0 for fundamental types)
  tuple<string, int, int, complex<double>> t;

  // Create and initialize tuple explicitly
  tuple<int, float, string> t1(41, 6.3, "nico");

  // "iterate" over elements
  cout << get<0>(t1) << " ";
  cout << get<1>(t1) << " ";
  cout << get<2>(t1) << " ";
  cout << endl;

  // create tuple with make_tuple
  //  - auto declares t2 with type of right-hand side
  //  - thus, type of t2 is tuple
  auto t2 = make_tuple(22, 44, "nico");

  // assign second value in t2 to t1
  get<1>(t1) = get<1>(t2);

  // comparsion and assignment
  // - including type conversion from tuple<int, int, const char*>
  //   to tuple<int,float,string>
  if (t1 < t2) { // compares value for value
    t1 = t2;     // OK, assigns value for value
  }

  // use of tie() creates a tuple of references
  int i;
  float f;
  string s;
  // assigns first and third values of t2 to i, s
  tie(i,std::ignore,s) = t2;

  // For the tuples, you have to explicitly convert the initial values into a tuple (for example, by using a make_tuple)
  vector<pair<int,float>> v {  make_tuple(1,1.0), make_tuple(2,2.0) };  // OK

  tuple<int,int,int> t3;
  t3 = foo();

  cout << "Print output of foo function:" << endl;
  // cout << "(" << get<0>(t3) << ", " << get<1>(t3) << ", " << get<2>(t3) << ")" << endl;

  cout << t3 << endl;

  exit(EXIT_SUCCESS);
}

/**
 * foo function implementation
 */
tuple<int,int,int> foo (){
  // Make tuple as return parameter
  return make_tuple(1,2,3);
}
