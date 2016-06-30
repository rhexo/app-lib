#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include "include/method.hpp"

using namespace std;

static constexpr int length = 5;

int main(int argc, char* argv[])
{  
  // Определяем перестановку
  int a[] = {0,1,2,3,4};
    
  // Получаем множество перестановок методом plex
  std::vector<int*> list = method::combinators<int,length>().plex(a);
  // Печатаем список перестановок
  for(auto e : list)
    utility::print<int,length>().data(e);

  exit(EXIT_SUCCESS);
};


