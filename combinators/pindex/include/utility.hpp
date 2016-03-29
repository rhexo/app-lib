#ifndef _UTILITY_HPP
#define _UTILITY_HPP

namespace utility {

  /** Печать некоторого типа (Шаблон) */
  template <typename T, int N >
  struct print;

  /** Печатаем значение перестановки для int[] */
  template<int N> 
  struct print<int,N>
  {  
    void data(int (&arr)[N], int ord) 
    {
      std::cout << ord << ": ";
      for( int i=0; i<N; i++)
        std::cout << arr[i] << std::string(" ");
      std::cout << std::endl;
    }

    void data(int *arr) 
    {
      for( int i=0; i<N; i++)
        std::cout << arr[i] << std::string(" ");
      std::cout << std::endl;
    }
  };

  /** Меняем местами i,j элементы массива A, длиной length */
  template<typename T, int N>
  struct swap;
  
  /** Меняем местами элементы массива int[] */
  template <int N>
  struct swap<int,N> {

    bool data(int (&arr)[N], int i, int j) {
        
      if (i > N || j > N)
        return false;

      if (i == j)
        return true;

      // if (is_array<A>::value == false) {
      //   return false;
      // }
      // // Получаем тип элемента массива
      // typedef typename std::remove_extent<A>::type tt_a;
    
      // tt_a p;
    
      int p;

      p = arr[i];
      arr[i] = arr[j];
      arr[j] = p;

      return true;
    
    }
  };
  
  // Копируем один массив в другой
  template <typename T, int N>
  struct copy;

  template <int N>
  struct copy<int,N> {
    
    int* data(int (&arr)[N]){
      int *c = new int[N];
      for (int i=0; i<N; i++)
        c[i] = arr[i];
      return c;
    }
  };

  struct factorial {
    int data(int n) {
      
      int nf = 1;
      // Вычисляем факториал числа
      for (int k=2;k<=n;k++)
        nf *= k;
      
      return nf;
    }
    
  };


};


#endif
