#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include "include/method.hpp"

using namespace std;

// static constexpr int length = 5; 

int main(int argc, char* argv[])
{  
    
  // Получаем множество перестановок методом plex
  std::vector<int*> list = method::pindex<12>().data();
  // Печатаем список перестановок
  // for(auto e : list)
  //   utility::print<int,8>().data(e);

  exit(EXIT_SUCCESS);
};


