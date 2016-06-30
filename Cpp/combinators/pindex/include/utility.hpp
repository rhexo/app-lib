#ifndef _UTILITY_HPP
#define _UTILITY_HPP

namespace utility {

  /** Печать некоторого типа (Шаблон) */
  template <typename T, int N >
  struct print {

    void data(T (&arr)[N], int ord) 
    {
      std::cout << ord << ": ";
      for( int i=0; i<N; i++)
        std::cout << arr[i] << std::string(" ");
      std::cout << std::endl;
    }

    void data(T *arr) 
    {
      for( int i=0; i<N; i++)
        std::cout << arr[i] << std::string(" ");
      std::cout << std::endl;
    }
  };

  
  /** Меняем местами элементы массива int[] */
  template <typename T, int N>
  struct swap {

    bool data(T (&arr)[N], int i, int j) {
        
      if (i > N || j > N)
        return false;

      if (i == j)
        return true;
    
      T p;

      p = arr[i];
      arr[i] = arr[j];
      arr[j] = p;

      return true;
    
    }
  };
  
  /** Копируем один массив в другой */
  template <typename T,int N>
  struct copy {
    
    T* data(T (&arr)[N]){
      T *c = new T[N];
      for (int i=0; i<N; i++)
        c[i] = arr[i];
      return c;
    }
  };
  
  /** Вычисляем факториал числа */
  template <typename I>
  struct factorial {
    I data(int n) {
      
      I nf = 1;
      // Вычисляем факториал числа
      for (int k=2;k<=n;k++)
        nf *= k;
      
      return nf;
    }
    
  };


};


#endif
