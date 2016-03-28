#ifndef _METHOD_HPP
#define _METHOD_HPP

#include "utility.hpp"
#include <vector>

namespace method {
  
  /** группа комбинаторов */
  template <typename T, int N>
  struct combinators;

  /** Метод получения перестановок PLex */
  template <int N>
  struct combinators<int,N>{

    std::vector<int*> plex(int (&arr)[N]) {
      
      std::vector<int*> list;

      int i = 1;
      int j = 0;
      int k = 0;
      int m = 0;
      int n = N-1;
      
      list.clear();

      while (i != 0 ) {

        int *entry = utility::copy<int,N>().data(arr);                
        list.push_back(entry);

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
      
      return list;
    }
    
  };

}



#endif
