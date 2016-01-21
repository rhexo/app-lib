#ifndef _PAIR_COMPARER_HPP
#define _PAIR_COMPARER_HPP

#include <iostream>

template <typename T>
bool pair_comparer(T a, T b)
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return a == b;
};

template <typename T>
bool pair_comparer(T a)
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return false;
};

template <typename T, typename ... Ts>
bool pair_comparer(T a, T b, Ts ...ts)
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return a == b && pair_comparer(ts...);
};


#endif
