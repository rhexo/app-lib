#include <list>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "include/person.h"

using namespace std;

// function that prints the passed argument
void print(int elem) {
  cout << elem << ' ';
};

int square(int x){
  return x*x;
};

// predicate, which returns whetheran an integer ia a prime number
bool isPrime(int number) {
  // ignore negative signs
  number = abs(number);

  // 0 and 1 are no prime numbers
  if (number == 1 || number == 0)
    return false;

  // find divisor that divides without a remainder
  int divisor;
  for (divisor = number/2; number%divisor != 0; --divisor) {
    ;
  }

  // if no divisor greater than 1 is found, it is a prime number
  return divisor == 1;

};

int main() {

  /** Using functions as algorithm arguments */

  vector<int> i1_coll;

  // insert elements from 1 to 9
  for (int i = 1; i <= 9; ++i) {
    i1_coll.push_back(i);
  }

  // print all elements
  for_each(i1_coll.cbegin(), i1_coll.cend(),  // range
           print);                            // operation
  cout << endl;


  /** Transform collections */

  set<int> i2_coll1;
  vector<int> i2_coll2;

  // insert elements from 1 to 9
  for (int i = 1; i <= 9; ++i) {
    i2_coll1.insert(i);
  }

  // print initialized
  cout << "initialized: ";
  copy(i2_coll1.cbegin(),i2_coll1.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  // transform each element from coll1 to coll2
  // - square transformed values
  transform(i2_coll1.cbegin(), i2_coll1.cend(),
            back_inserter(i2_coll2),
            square);

  // print squared
  cout << "squared: ";
  copy(i2_coll2.cbegin(),i2_coll2.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;


  /** Unary predicates */

  list<int> i3_coll;

  // insert elements from 24 to 30
  for (int i=24; i <= 30; ++i) {
    i3_coll.push_back(i);
  }

  // search for prime number
  auto pos = find_if(i3_coll.cbegin(),i3_coll.cend(),  // range
                     isPrime);                         // predicate

  if (pos != i3_coll.end()) {
    // found
    cout << *pos << " is a first prime number found" << endl;
  } else {
    // not found
    cout << "no prime number found" << endl;
  }


  /** Binary predicates */
  vector<Person> i4_coll;
  // std::list doesn`t supported by std::sort

  i4_coll.push_back(Person("Jim", "Jimmy"));
  i4_coll.push_back(Person("Artie", "Black"));
  i4_coll.push_back(Person("John", "Davice"));
  i4_coll.push_back(Person("Zero", "Cool"));

  cout << "list of persons:" << endl;
  for (const auto& elem : i4_coll ) {
    elem.print();
  }

  // ctor test
  Person p1("Jaja", "Bings");
  Person p2("Enjy", "Sky");

  // print
  cout << "ctor test: " << endl;
  p1.print();
  p2.print();
  cout << boolalpha <<  Person::personSortCriterion(p1, p2) << endl;

  p2 = p1;
  cout << "copy Person result:";
  p2.print();

  // example of binary predicate
  sort(i4_coll.begin(), i4_coll.end(),    // range
       Person::personSortCriterion);              // binary predicateb

  exit(EXIT_SUCCESS);

};
