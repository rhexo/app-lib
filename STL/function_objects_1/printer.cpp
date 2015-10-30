#include <iostream>
#include "include/printer.h"

using namespace std;

Printer::Printer(int _ia){
  _int_adaptor = _ia;
}

void Printer::operator()(int elem) const {
  // Print elem corrected by _int_adaptor
  cout << (elem + _int_adaptor) << ' ';
}
