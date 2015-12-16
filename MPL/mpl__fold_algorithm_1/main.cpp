/** Example of using MPL algorithms */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <boost/static_assert.hpp>
#include "include/fold_algorithm.hpp"

using namespace std;
namespace mpl = boost::mpl;

int main()
{

  typedef mpl::vector<mpl::int_<10>,mpl::int_<20>, mpl::int_<30>> S;
  typedef fold_reverse<S>::type rev;

  cout << "front<reverse> = " << mpl::front<rev>::type::value << endl;

  exit(EXIT_SUCCESS);
}
