#ifndef _METHOD_HPP
#define _METHOD_HPP

#include "utility.hpp"

namespace method {
  
  /** группа комбинаторов */
  template <typename T, int N>
  struct combinators;

  /** Метод получения перестановок PLex */
  template <int N>
  struct combinators<int,N>{

    void plex(int (&arr)[N]) {

      int i = 1;
      int j = 0;
      int k = 0;
      int m = 0;
      int n = N-1;
      int ord = 0;
  
      while (i != 0 ) {
        // Печатаем элемент перестановки
        utility::print<int,N>().data(arr, ord);    
        ++ord;
        i = n - 1;
        while(arr[i] > arr[i+1])
          --i;
        j = n;
        while(arr[j] < arr[i])
          --j;
        utility::swap<int,N>().data(arr,i,j);
        k = i + 1;
        m = i + (int)((n - i) / 2);
        while(k <= m){
          utility::swap<int,N>().data(arr,k,n-k+i+1);
          ++k;
        }          
      } 
    }
    
  };

}



#endif
