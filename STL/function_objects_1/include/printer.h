#ifndef _PRINTER_H
#define _PRINTER_H

class Printer {
public:

  int _int_adaptor;
  // Constructor
  Printer(int = 0);
  // Function object
  void operator() (int) const;

};

#endif
