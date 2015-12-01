/** Example of using MPL numeric compute */
#include <iostream>
#include <cstdlib>
#include <string>
#include "include/measures.h"

using namespace std;
using namespace measures;


int main(){


  // define quanriry measure
  quantity<float, length> l(1.0f);
  quantity<float, length> l2(3.0f);
  quantity<float, mass> m(2.0f);


  // some simple manipulation with quantities
  l = l + l2;
  cout << "length: 1+3 -> " << l << endl;

  // G
  cout << "G: 10*9.8 -> " << quantity<float,mass>(10.0f) * quantity<float, acceleration>(9.8f) << endl;

  quantity<float,acceleration> a(9.8f);
  // quantity<float,mass> bogus = m * a;  // Compiling error

  quantity<float,force> f(78.0f);
  quantity<float,mass> m2 = f / a;  // m = F/a

  cout << "m:f/a -> " << m2 << endl;

  exit(EXIT_SUCCESS);
};
