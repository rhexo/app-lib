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
  // Длина массива int[]
    
  // Получаем множество перестановок методом plex
   method::combinators<int,length>().plex(a);

  exit(EXIT_SUCCESS);
};


