#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <person.h>

using namespace std;


// functions definitions
shared_ptr<Person> initFamily(const string& );


int main (){

  shared_ptr<string> pName(new string("Paul"));
  shared_ptr<string> p;

  p = pName;   // add use_count + 1, result = 2

  if (!(p == nullptr))
    cout << "use_count = " << p.use_count() << endl;

  shared_ptr<Person> person = initFamily("nico");
  cout << endl;

  cout << "nico`s family exists " << endl;
  cout << "- nico is shared " << person.use_count() << "times" << endl;
  cout << "- name of 1st kid of nico`s mom: "
       << person->mother->kids[0].lock()->name << endl;   // using lock for access to weak_ptr reffered object

  person = initFamily("jim");
  cout << "jim`s family exists " << endl;
  cout << "- jim is shared " << person.use_count() << "times" << endl;
  cout << "- name of 1st kid of jim`s dad: "
       << person->father->kids[0].lock()->name << endl;


  return 0;
}

shared_ptr<Person> initFamily(const string& name ){

  shared_ptr<Person> mom (new Person(name + "`s mom"));
  shared_ptr<Person> dad (new Person(name + "`s dad"));

  // link to mom and dad with shared_ptr.
  shared_ptr<Person> kid (new Person(name, mom, dad));

  // i suppose it`s useful for reflection links to the objects
  // share_ptr link are stored in previous code line
  // for correct releasing mom and dad objects we have to use a weak_ptr`s in
  // refletion link of mom and dad objects
  mom->kids.push_back(kid);
  dad->kids.push_back(kid);

  return kid;
}
