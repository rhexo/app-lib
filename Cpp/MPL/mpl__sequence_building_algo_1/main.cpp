/** Example of using MPL algorithms */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <boost/static_assert.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/type_traits/is_same.hpp>
#include "include/sbuilding.hpp"

using namespace std;
namespace mpl = boost::mpl;

// Sequence printer
struct seq_printer
{
  template <typename T>
  void operator()(T t)
  {
    cout << t << " ";
  }
};

int main()
{

  BOOST_STATIC_ASSERT((boost::is_same<_l678::type, __l678::type>::value));

  cout << "_v678:" << endl;
  cout << "at_c(0): " << mpl::at_c<_v678,0>::type::value << endl;
  cout << "at_c(1): " << mpl::at_c<_v678,1>::type::value << endl;
  cout << "at_c(2): " << mpl::at_c<_v678,2>::type::value << endl;


  cout << "_l678:" << endl;
  cout << "at_c(0): " << mpl::at_c<_l678,0>::type::value << endl;
  cout << "at_c(1): " << mpl::at_c<_l678,1>::type::value << endl;
  cout << "at_c(2): " << mpl::at_c<_l678,2>::type::value << endl;

  cout << "__l678:" << endl;
  cout << "at_c(0): " << mpl::at_c<__l678,0>::type::value << endl;
  cout << "at_c(1): " << mpl::at_c<__l678,1>::type::value << endl;
  cout << "at_c(2): " << mpl::at_c<__l678,2>::type::value << endl;

  mpl::for_each<__l678>(seq_printer());


  exit(EXIT_SUCCESS);
}
