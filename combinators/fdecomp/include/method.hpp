#ifndef _METHOD_HPP
#define _METHOD_HPP

#include "utility.hpp"
#include <vector>

namespace method {

  /** Метод получения представления числа m в виде факториала m < n! */  
  template <int N>
  struct fdecomp {

    int* data(int m) {
      
      int *d = new int[N];
      int n = N;
      
      if (n < 1)
        return nullptr;

      int i = 0;
      d[0] = 0;
      int q = m;
      
      while (q > 0) {
        ++i;
        d[i-1] = q % i;
        q = (int)(q / i);
      }
      ++i;
      
      while (i < n) {
        d[i-1] = 0;
        ++i;
      }
            
      return d;
    }
    
  };

}



#endif
