#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include "include/method.hpp"

using namespace std;

static constexpr int N = 4; 

int main(int argc, char* argv[])
{  
  
  std::cout << "Store in memory." << std::endl;

  // Получаем множество перестановок методом pindex
  
  /** Получаем перестановки и храним их в векторе */
  std::vector<int*> list = method::pindex<N>().data();
  // Печатаем список перестановок
   for(auto e : list)
     utility::print<int,N>().data(e);

  std::cout << "Calculate at runtime." << std::endl;

  /** Хранение массива для N=12 будет занимать память порядка 21Гб, поэтому хранение
      перестановок с большим числом элементов в памяти не является эффективным,
      следует использовать вычисление перестановки на каждом шаге иттерации */
  
  int nf = utility::factorial().data(N);
  for (int i=0;i<nf;i++) {

    int k;
    int ak[N];

    // Прямое преобразование: индекс -> перестановка
    method::pindex<N>().get(i,ak);
    // Обратное преобразование: перестновка -> индекс
    k = method::pindex<N>().get(ak);
    
    // Маленькая проверочка
    if (k != i)
      std::cout << "k= " << k << "<> i= " << i << ". CONVERSION FAILED!" << std::endl;

    // Печатаем перестановку, найденную по индекс i
    std::cout << "k= " << k << " / ";
    utility::print<int,N>().data(ak);

  }
    

  exit(EXIT_SUCCESS);
};


