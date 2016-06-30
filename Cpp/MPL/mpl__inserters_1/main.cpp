/** Example of using MPL algorithms */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <boost/static_assert.hpp>
#include "include/inserters.hpp"

using namespace std;
namespace mpl = boost::mpl;

int main()
{

  cout << "sum = " << sum::value << endl;
  exit(EXIT_SUCCESS);
}
