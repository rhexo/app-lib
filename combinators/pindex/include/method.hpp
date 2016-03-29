#ifndef _METHOD_HPP
#define _METHOD_HPP

#include "utility.hpp"
#include <vector>

namespace method {


  /** Метод получения факториального числа d[N] для m < n! */  
  template <int N>
  struct fdecomp {
        
    /** Получаем факториальное представление числа m в виде динамически
        выделяемого массива int* */
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
    
    /** Получаем факториальное представление d[N] для числа m */
    void data(int m, int (&d)[N]) {

      int n = N;
      
      if (n < 1)
        return;

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
      
    }
    
    /** Выполняем преобразование факториального числа d[N] в значение факториала m */
    int datad(int (&d)[N]) {
      
      if (N<1)
        return 0;
      
      int m = 0;
      for(int i=1;i<N;i++)
        m += d[i] * utility::factorial().data(i);
      
      return m;
    }
    
  };

  /** Вычисляем перестановку, которая соответствует факториальному представлению
      d[N]. Вычисляем как смещение относительно начальной перестановки a0 */

  template<int N>
  struct pconstrf {
    

    /** Прямое преобразование: факториальное представление -> перестановка */
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
        // Сдвигаем мощность множества влево
        --m; 
        // Сдвигаем индекс перебираемых элементов
        --k;        
      }
      
      return ak;
    }

    /** Прямое преобразование: факториальное представление числа -> перестановка */
    void data(int (&d)[N], int (&ak)[N]) {
      
      int n = N;
      int l = 0;
      // Инициализация начальной перестановки
      int a0[N];
      for (int k=0;k<N;k++)
        a0[k] = k;
      
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
      
    }
    
    /** Обратное преобразование: перестновка -> факториальное представление */
    void datad(int (&ak)[N], int (&d)[N]) {

      int i = 0;
      int j = 0;
      int l = N;
      int k = 0;
      
      // Инициализация начальной перестановки
      int a0[N];
      for (int k=0;k<N;k++)
        a0[k] = k;
      
      for (i=0;i<N;i++) {
        
        for (j=0;j<l;j++) {
          if (ak[i]==a0[j]) {
            d[N-i-1]=j;
            break;
          }
        }
        
        // Исключаем элемент из начальной перестановки
        --l;
        for (k=j;k<l;k++)
          a0[k] = a0[k+1];
       
      }
    }

  };

  /** Алгоритм вычисления перестановок для m < N! */
  template<int N>
  struct pindex {
    
    /** Получаем вектор с N! перестановками */
    std::vector<int*> data() {
      
      int n = N;      
      int *d = nullptr;
      int *ak = nullptr;
      std::vector<int*> list;
      
      list.clear();
      
      int nf = utility::factorial().data(n);

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
    
    /** Получаем перестановку по индексу */
    void get(int index, int (&ak)[N]) {

      int n = N;      
      int d[N];
                 
      // Вычисляем перестановки
      // Получаем факториальное представление по индексу
      method::fdecomp<N>().data(index,d);
      // факториальное представление в перестановку
      method::pconstrf<N>().data(d,ak);              
      
    }

    /** Получаем индекс на основе перестановки */
    int get(int (&ak)[N]) {
      
      int d[N];
      
      method::pconstrf<N>().datad(ak,d);      
      int k = method::fdecomp<N>().datad(d);

      return k;
    }

  };



}



#endif
