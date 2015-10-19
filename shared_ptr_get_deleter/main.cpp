#include <memory>

using namespace std;

int main (){

  auto del = [] (int* p){
    delete p;
  };

  shared_ptr<int> p(new int , del);
  decltype(del) *pd = get_deleter<decltype(del)>(p);

}
