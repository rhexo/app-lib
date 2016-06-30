/** Example of using MPL numeric compute */
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cstdlib>

using namespace std;


// example of iter_swap
namespace my {

  template <class ForwardIterator1, class ForwardIterator2>
  void iter_swap(ForwardIterator1 i1, ForwardIterator2 i2)
  {
    // exchange interators
    typename iterator_traits<ForwardIterator1>::value_type tmp = *i1;  // using type traits of iterator template
    *i1 = *i2;
    *i2 = tmp;
  };

  /**
   * Declaring swap for iterators with different types
   */
  template <class T1, class T2>
  void swap(T1&a, T2&b)
  {
    T1 tmp = a;
    a = b;
    b = tmp;
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

  my::iter_swap(ii1, ii2);

  cout << "after swap" << endl;

  for(auto elem : i1)
    cout << elem << " ";
  cout << endl;

  for(auto elem : i2)
    cout << elem << " ";
  cout << endl;


  exit(EXIT_SUCCESS);
};
