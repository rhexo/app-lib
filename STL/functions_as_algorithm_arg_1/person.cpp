#include <algorithm>
#include <string>
#include <iostream>
#include "include/person.h"

using namespace std;

/** Person implementation section */

// constructor
Person::Person(string f, string l){
  this->_first = f;
  this->_last = l;
};

// ctor
Person::Person(const Person& p){

  cout << "ctor is active." << endl;

  _first = p.firstname();
  _last = p.lastname();
};

string Person::firstname() const {
  return _first;
};

string Person::lastname() const {
  return _last;
};

void Person::print() const {
  cout << "person: " << lastname() << " " << firstname() << endl;
}

// sort api for person
// binary function predicate
// - returns whether a person is less than another person
bool Person::personSortCriterion(const Person& p1, const Person& p2){

  // A person is less tha another person
  // - if the last name is less
  // - if the last name is equal and the firstname is less
  return ( p1.lastname() < p2.lastname()) ||
    (p1.lastname() == p2.lastname() &&
     p1.firstname() < p2.firstname());
};

ostream& operator<< (ostream& _cout, const Person& p){
  return _cout << "person: " << p.firstname() << " " << p.lastname() << endl;
}
