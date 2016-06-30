/** Example of using MPL algorithms */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <utility>


using namespace std;


struct _name{
  std::string _val;
  _name(std::string n) : _val(n) {}
  _name() {}
  std::string operator()() { return _val; }
};


// predefined prototype
template <typename T>
T ff(T&&);

template <typename T>
T kk(T&&);


void pr(_name&&);

int main(int argc, char* argv[])
{
  
  std::string text("some text");
  std::string res = ff(text);
  
  _name nn4("simple name 4");

  std::cout << "text: " << text << std::endl;
  std::cout << "res: " << res << std::endl;
  
  std::cout << "kk: " << kk(text) << std::endl;
  std::cout << "text: " << text << std::endl;
  
  std::cout << "nn:1: " << ff(_name(text))() << std::endl;
  std::cout << "nn:2: " << ff(_name("another text"))() << std::endl;
  std::cout << "nn:3: " << kk(_name(text))() << std::endl;
  std::cout << "nn:4: " << kk(_name("forward text"))() << std::endl;
  std::cout << "nn:5: " << ff(nn4)() << std::endl;
  std::cout << "nn:8: " << kk(nn4)() << std::endl;
  std::cout << "nn:end: " << nn4() << std::endl;
  
  pr(std::forward<_name&&>(nn4));
  std::cout << "after:pr: " << nn4() << std::endl;

  exit(EXIT_SUCCESS);
}

template <typename T>
T ff(T&& s) 
{  
  return T(s);
}

template <typename T>
T kk(T&& s) 
{  
  return T(std::forward<T>(s));
}

void pr(_name&& p)
{
  std::cout << "pr: " << p() << std::endl;
}
