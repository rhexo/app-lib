#include <person.h>

using namespace std;

// constructor
Person:: Person(const string& n,
                shared_ptr<Person> m,
                shared_ptr<Person> f)
  : name(n), mother(m), father(f) {

};

// Misusing shared pointers implementation
void Person::setParentsAndTheirKids(shared_ptr<Person> m,
                                    shared_ptr<Person> f) {

  mother = m;
  father = f;

  if (m != nullptr)
    m->kids.push_back(shared_from_this());

  if (f != nullptr)
    f->kids.push_back(shared_from_this());
}

Person::~Person() {
  cout << "delete " << name << endl;

}
