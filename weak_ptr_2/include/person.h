#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person : public enable_shared_from_this<Person>{
 public:

  string name;
  shared_ptr<Person> mother;
  shared_ptr<Person> father;
  vector<weak_ptr<Person>> kids;

  // constructor
  Person(const string&, shared_ptr<Person> = nullptr, shared_ptr<Person> = nullptr);

  // Misusing shared pointers
  void setParentsAndTheirKids(shared_ptr<Person> = nullptr, shared_ptr<Person> = nullptr);

  // Destructor
  ~Person();

};

#endif
