#include <list>
#include <iostream>

using namespace std;

int main ()
{

  /** List container for character elements */
  list<char> list_1;

  // append elements from 'a' to 'z'
  for (char c='a'; c<='z'; ++c){
    list_1.push_back(c);
  }

  // print all elements:
  // - iterate all elements
  list<char>::iterator pos;
  for(pos = list_1.begin(); pos != list_1.end(); ++pos){
    /**
     * ++pos versus pos++
     *
     * ++pos has a better perfomance than pos++
     * Prefer to use ++pos
     */
    cout << *pos << ' ';
  }
  cout << endl;

  /** cbegin() and cend() */
  /** Since C++11 we can use keyword auto to specify the exact type of the iterator.
   * Thus, by initializing the iterator directly with begin(), we can use auto to
   * declare its type.
   *
   * auto pos = coll.begin()
   * pos becomes a nonconstant iterator because begin() returns an object of type cont::iterator.
   * To ensure that constant iterators are still used, cbegin() and cend() are provided as
   * container fuctions since C++11. They return an object of type cont::const_iterator.
   */
  for (auto pos = list_1.cbegin(); pos != list_1.cend(); ++pos) {
    cout << *pos << ' ';
  }
  cout << endl;

  /**
   * Range based for loops versus iterators
   *
   * Thus
   * for (auto elem : list_1){
   *   ...
   * }
   *
   * is enterpreted as
   *
   * for (auto pos=list_1.begin(), end = list_1.end(); pos != end; ++pos {
   *   type elem = *pos;
   *  ...
   * }
   * Thats why we should declare elem to be a constant reference to avoid unnecessary copies.
   * Otherwise, elem will be initialize as a copy of *pos.
   */



}
