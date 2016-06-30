#ifndef _PERSON_H
#define _PERSON_H

#include <string>

using namespace std;

class Person {
public:

  static bool personSortCriterion(const Person&, const Person&);

  Person(string, string);
  Person(const Person& p);

  string firstname() const;
  string lastname() const;

  void print() const;


private:

  string _first;
  string _last;
};

// overload << operator for Person class
ostream& operator<< (ostream &, const Person&);


#endif
