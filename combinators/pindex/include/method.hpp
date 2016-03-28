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
      
      while (i <= n) {
        d[i-1] = 0;
        ++i;
      }
            
      return d;
    }
    
  };

  template<int N>
  struct pconstrf {
    
    /** Вычисляем смещение d, относительно начальной перестановки a0 */
    int* data(int* d) {
      
      int n = N;
      int l = 0;
      // Инициализация начальной перестановки
      int a0[N];
      for (int k=0;k<N;k++)
        a0[k] = k;
      
      int *ak = new int[N];
      
      int k=n-1;
      int m=n-1;
      while (k>-1) {
        // Выполняем инициализацию элемента перестановки 0,1,...,l-1,l
        ak[l++]=a0[d[k]];
        // Исключаем элемент d[k] из множества d
        for(int j=d[k];j<m;j++)
          a0[j]=a0[j+1];
        // Сдвигаем общую можность множества влево
        --m; 
        // Сдвигаем индекс перебираемых элементов
        --k;        
      }
      
      return ak;
    }
  };

  template<int N>
  struct pindex {
    
    std::vector<int*> data() {
      
      int n = N;      
      int *d = nullptr;
      int *ak = nullptr;
      std::vector<int*> list;
      
      list.clear();
      
      int nf = 1;
      // Вычисляем факториал числа
      for (int k=2;k<=n;k++)
        nf *= k;

      // Вычисляем перестановки
      for (int k=0;k<nf;k++){
        // Получаем факториальное представление по индексу
        d = method::fdecomp<N>().data(k);
        // факториальное представление в перестановку
        ak = method::pconstrf<N>().data(d);        
        list.push_back(ak);
        delete d;
      }
      
      return list;
    }
  };



}



#endif
