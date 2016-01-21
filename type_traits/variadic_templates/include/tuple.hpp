#ifndef _TUPLE_HPP
#define _TUPLE_HPP

#include <iostream>

namespace data {
  
  template <class ...Ts>
  struct tuple {};

  template <class T, class ...Ts>
  struct tuple<T, Ts...> : tuple<Ts...>
  {
    /** constructor */
    tuple(T t, Ts... ts) : tuple<Ts...>(ts...), tail(t) {}
    T tail;
  };


  /** helper type to access to tuple */
  template <size_t, class> struct elem_type_holder;

  template <class T, class ...Ts>
  struct elem_type_holder<0, tuple<T, Ts...> >
  {
    typedef T type;
  };

  template <size_t k, class T, class ...Ts>
  struct elem_type_holder<k, tuple<T, Ts...> >
  {
    typedef typename elem_type_holder<k-1, tuple<Ts...>>::type type;
  };

  template <size_t k, class ...Ts>
  typename std::enable_if<
    k == 0, typename elem_type_holder<0, tuple<Ts...> >::type&>::type
  get(tuple<Ts...>& t)
  {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return t.tail;
  };

  template <size_t k, class T, class ...Ts>
  typename std::enable_if<
    k != 0, typename elem_type_holder<k, tuple<T, Ts...> >::type& >::type
  get(tuple<T, Ts...>& t)
    {
      std::cout << __PRETTY_FUNCTION__ << std::endl;
      tuple<Ts...>& base = t;
      return get<k-1>(base);
    };

};


#endif
