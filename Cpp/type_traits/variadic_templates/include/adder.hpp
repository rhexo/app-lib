#ifndef _ADDER_HPP
#define _ADDER_HPP

#include <iostream>

/** add all arguments together */
template <typename T>
T adder (T v)
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return v;
};

template <typename T, typename ...Ts>
T adder (T t, Ts... ts)
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return t + adder(ts...);
};

#endif
