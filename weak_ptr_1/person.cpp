#include <person.h>

using namespace std;

// constructor
Person:: Person(const string& n,
                shared_ptr<Person> m,
                shared_ptr<Person> f)
  : name(n), mother(m), father(f) {

};

Person::~Person() {
  cout << "delete " << name << endl;

}
