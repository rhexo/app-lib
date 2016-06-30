/** Example of using MPL numeric compute */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <utility>
#include <cstdlib>
#include <string>

using namespace std;

// example of iter_swap
namespace my {

  template <bool use_swap> struct iter_swap_impl;

  template <class ForwardIterator1, class ForwardIterator2>
  void iter_swap(ForwardIterator1 i1, ForwardIterator2 i2)
  {
    typedef iterator_traits<ForwardIterator1> traits1;
    typedef typename traits1::value_type v1;
    typedef typename traits1::reference r1;

    typedef iterator_traits<ForwardIterator2> traits2;
    typedef typename traits1::value_type v2;
    typedef typename traits1::reference r2;


    bool const use_swap = is_same<v1, v2>::value
      && is_reference<v1>::value
      && is_reference<v2>::value;

    std::cout << std::boolalpha;
    std::cout << "is_same<v1, v2>: " << is_same<v1, v2>::value << std::endl;
    std::cout << "is_reference<v1>: " << is_reference<v1>::value << std::endl;
    std::cout << "is_reference<v2>: " << is_reference<v2>::value << std::endl;

    iter_swap_impl<use_swap>::do_it(i1, i2);
  };


  // template specialization for <true>
  template <>
  struct iter_swap_impl<true> // the fast one
  {
    template <class ForwardIterator1, class ForwardIterator2>
    static void do_it(ForwardIterator1 i1, ForwardIterator2 i2)
    {
      std::swap(*i1,*i2);
      std::cout << "iter_swap_impl<true>" << std::endl;
    }
  };

  // template specialization for <false>
  template <>
  struct iter_swap_impl<false>  // the one that always work
  {
    template <class ForwardIterator1, class ForwardIterator2>
    static void do_it(ForwardIterator1 i1, ForwardIterator2 i2)
    {
      typename std::iterator_traits<ForwardIterator1>::value_type tmp = *i1;
      *i1 = *i2;
      *i2 = tmp;

      std::cout << "iter_swap_impl<false>" << std::endl;
    }
  };

};

int main(){

  vector<int> i1({1,2,3,10});
  vector<int> i2({11,12,13,20});

  for(auto elem : i1)
    cout << elem << " ";
  cout << endl;

  for(auto elem : i2)
    cout << elem << " ";
  cout << endl;


  vector<int>::iterator ii1 = i1.begin()+1;
  vector<int>::iterator ii2 = i2.begin()+2;

  cout << endl << "Meta:" << endl;
  my::iter_swap(ii1, ii2);

  cout << endl << "after swap" << endl;

  for(auto elem : i1)
    cout << elem << " ";
  cout << endl;

  for(auto elem : i2)
    cout << elem << " ";
  cout << endl;


  // with reference swap

  vector<bool> b1({true,true,false});
  vector<bool> b2({false,false,true});

  cout << endl << "with reference swap:" << endl;
  my::iter_swap(b1.begin()+2,b2.begin()+2 );
  cout << endl << "after swap:" << endl;
  cout << boolalpha;

  for(auto elem : b1)
    cout << elem << " ";
  cout << endl;

  for(auto elem : b2)
    cout << elem << " ";
  cout << endl;


  exit(EXIT_SUCCESS);
};
