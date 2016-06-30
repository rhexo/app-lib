#include <algorithm>
#include <deque>
#include <set>
#include <iostream>
#include <string>
#include <cstdlib>
#include "include/person.h"

using namespace std;

int main() {

  /** Benifit of lambdas */

  deque<int> i1_list {1, 3, 19, 5, 13, 7, 11, 2, 17};

  // print all collection
  copy(i1_list.cbegin(),i1_list.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  // valid interval
  int x = 5;
  int y = 12;

  deque<int>::const_iterator pos = find_if(i1_list.cbegin(), i1_list.cend(),    // range
                                           [=] (int i) {                        // define predicate as lambda expression
                                             return i > 5 && i < 12;            // valid interval  (5,12)
                                           });

  cout << "first elem >5 and <12 is " << *pos << endl;


  /** Using std::sort with lambda */

  deque<Person> i2_list;
  // std::list doesn`t supported by std::sort

  i2_list.push_back(Person("Jim", "Jimmy"));
  i2_list.push_back(Person("Artie", "Black"));
  i2_list.push_back(Person("John", "Davice"));
  i2_list.push_back(Person("Zero", "Cool"));

  cout << "sorting deque: " << endl;
  sort(i2_list.begin(), i2_list.end(),
       [] (const Person& p1, const Person& p2){
         return (p1.lastname() < p2.lastname() ||
                 (p1.lastname() == p2.lastname() &&
                  p1.firstname() < p2.firstname()));
       });

  // print all collection
  copy(i2_list.cbegin(),i2_list.cend(),
       ostream_iterator<Person>(cout, "\n"));
  cout << endl;


  /** Sort criteria for associative container */
  auto cmp = [] (const Person& p1, const Person& p2)
    {
      return ( p1.lastname() < p2.lastname() ||
               (p1.firstname() < p2.firstname() &&
                p1.lastname() == p2.lastname()));
    };

  set<Person,decltype(cmp)> i3_coll(cmp);

  copy(i2_list.crbegin(), i2_list.crend(),
       inserter(i3_coll, i3_coll.begin()));

  cout << "sorted by custom lambda expression (cmp): " << endl;
  copy(i3_coll.cbegin(),i3_coll.cend(),
       ostream_iterator<Person>(cout, "\n"));
  cout << endl;

  exit(EXIT_SUCCESS);

};
