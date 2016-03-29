#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <type_traits>
#include "include/method.hpp"

using namespace std;

static constexpr int N = 4; 

int main(int argc, char* argv[])
{  
  
  std::cout << "Store in memory." << std::endl;

  // Получаем множество перестановок методом pindex
    
  cout << "max(int): " << numeric_limits<int>::max() << endl;
  cout << "max(size_t): " << numeric_limits<std::size_t>::max() << endl;
  cout << "max(uint64_t): " << numeric_limits<std::uint64_t>::max() << endl;

  typedef typename std::uint64_t index_t;

  // 12! это максимально допустимый диапазон для типа данных int

  /** Получаем перестановки и храним их в векторе */
  std::vector<int*> list = method::pindex<std::size_t,N,int>().data();
  // Печатаем список перестановок
   for(auto e : list)
     utility::print<int,N>().data(e);

  std::cout << "Calculate at runtime." << std::endl;

  /** Хранение массива для N=12 будет занимать память порядка 21Гб, поэтому хранение
      перестановок с большим числом элементов в памяти не является эффективным,
      следует использовать вычисление перестановки на каждом шаге иттерации */
  
  index_t nf = utility::factorial<index_t>().data(N);
  for (index_t i=0;i<nf;i++) {

    index_t k;
    int ak[N];

    // Прямое преобразование: индекс -> перестановка
    method::pindex<index_t,N,int>().get(i,ak);
    // Обратное преобразование: перестновка -> индекс
    k = method::pindex<index_t,N,int>().get(ak);
    
    // Маленькая проверочка
    if (k != i)
      std::cout << "k= " << k << "<> i= " << i << ". CONVERSION FAILED!" << std::endl;

    // Печатаем перестановку, найденную по индекс i
    std::cout << "k= " << k << " / ";
    utility::print<int,N>().data(ak);

  }
    
  /** Пример с большими числами */

  {
    int ak[20]; // 20! - масксимально адресуемый диапазон для uint64_t
    index_t k;

    method::pindex<index_t,20,int>().get(2432902008176639999,ak);
    std::cout << "ak = ";
    utility::print<int,20>().data(ak);

    k = method::pindex<index_t,20,int>().get(ak);
    std::cout << "k = " << k << std::endl;
  }

  exit(EXIT_SUCCESS);
};


