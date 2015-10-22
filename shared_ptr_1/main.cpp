#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main () {

  // Shared pointers representing persons by their name
  shared_ptr<string> pNico(new string("nico"),
                           [] (string *p) {  // defining deleter
                             cout << "delete " << *p << endl;
                             delete p;
                           });

  shared_ptr<string> pJutta(new string("jutta"),
                            [] (string *p) {
                              cout << "Another deleter realization for " << *p << endl;
                              delete p;
                            });

  // get pointer by make_shared call
  shared_ptr<string> pSanta = make_shared<string>("santa");

  // get new assigning for nico
  pNico.reset(new string("nico 1"));   // Own deleter called and will be overwriten with std::default_delete<string>()

  // print reset results
  cout << "pNico.reset = " << *pNico << endl;

  // and another reset of nico
  pNico = make_shared<string>("nico 2");

  // print results
  cout << "pNico.reset with make_shared = " << *pNico << endl;

  // capitalize person names
  (*pNico)[0] = 'N';
  pJutta->replace(0,1,"J");
  (*pSanta)[0] = 'S';

  // put them multiple times in container
  vector<shared_ptr<string>> whoMadeCoffee;

  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pNico);
  whoMadeCoffee.push_back(pSanta);
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pNico);
  whoMadeCoffee.push_back(pSanta);

  // print all intems of vector
  for (auto ptr : whoMadeCoffee) {
    cout << *ptr << " ";
  }
  cout << endl;

  // overwrite a name assign
  *pNico = "Nicolai";


  // print all elements again
  for (auto ptr : whoMadeCoffee) {
    cout << *ptr << " ";
  }
  cout << endl;

  // print some internal data
  cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;

  // Arrays.
  // Creating shared_ptr for an array is possible but wrong. Mpre correct using unique_ptr for this goals.
  shared_ptr<int> p(new int[10],     // <int[]> is error for shared_ptr, but for unique_ptr is OK. i.e.>> unique_ptr<int[]> p(...)
                    [] (int *p) {    // as alternative can use officially provided deleter: std::default_delete<int[]>()
                      delete []p;    // For unique_ptr own deleter must be specified
                    });


  // assigning new values for an array
  p.get()[0] = 1;
  p.get()[1] = 2;
  p.get()[2] = 3;
  p.get()[3] = 4;
  p.get()[4] = 5;
  p.get()[5] = 6;
  p.get()[6] = 7;
  p.get()[7] = 8;
  p.get()[8] = 9;
  p.get()[9] = 10;

  cout << "Print values of array of shared_ptr" << endl;
  for(int i=0; i<10; i++)
    cout << p.get()[i] << endl;

}
