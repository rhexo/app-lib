#ifndef _CATCH_ALL_HPP
#define _CATCH_ALL_HPP

#include <iostream>

// print_container(c) for all containers

/** this implementation will be usless for set or map container types */
/**
   template < template <typename, typename> class ContainerType, 
   typename ValueType,
   typename AllocType>
   void print_container(const ContainerType<ValueType, AllocType>& c)
   {
   for (const auto& v : c)
   std::cout << v << ' ';
   std::cout << std::endl;
   };
*/

/** variadic templates for a rescue */
template < template <typename, typename...> class ContainerType, 
           typename ValueType, typename ...Args>
void print_container(const ContainerType<ValueType, Args...>& c)
{
  for (const auto& v : c)
    std::cout << v << ' ';
  std::cout << std::endl;
};

namespace std {

  // Implement << for pairs: this is need to print out mappings where range
  // iteration goes over (key, value) pairs.
  template <typename T, typename U>
  std::ostream& operator<<(std::ostream& out, const std::pair<T,U>& p)
  {
    out << "[" << p.first << ", " << p.second << "]";
    return out;
  };

};

#endif
