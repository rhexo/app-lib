#ifndef _FORWARDING_HPP
#define _FORWARDING_HPP

#include <iostream>

/** forwarding with variadic templates */
namespace data {
  
  template <class T, class ...U>
  std::unique_ptr<T> make_unique(U&&... u)
  {
    return std::unique_ptr<T>( new T(std::forward<U>(u)... ));
  };


};

#endif
