#include <memory>
#include <iostream>

using namespace std;

int main (){

  shared_ptr<void> sp(new int{10});

  // undefined bihavior for next expression
  // shared_ptr<int> sp1 = shared_ptr<int>(static_cast<int*>(sp.get()))
  shared_ptr<int> sp1 = static_pointer_cast<int>(sp);
  cout << "Cast value: " << *sp1 << endl;

}
