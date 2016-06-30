/** Example of using MPL numeric compute */
#include <iostream>

using namespace std;


template <unsigned long N>
struct binary{
  static unsigned const value = binary<N/10>::value << 1 | N % 10;
};

// terminate recursion
template <>
struct binary<0> {
  static unsigned const value = 0;
};

int main(){

  unsigned const five = binary<101>::value; // 5
  unsigned const sse = binary<1010100110>::value;  // 678

  cout << "\\5: "  << five << endl;
  cout << "\\678: " << sse << endl;

  exit(EXIT_SUCCESS);
};
