/** Example of using MPL algorithms */
#include <iostream>
#include <cstdlib>
#include <string>
#include <type_traits>
#include <boost/static_assert.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>
#include "include/views.hpp"
#include "include/view_example.hpp"
#include "include/own_view.hpp"


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

  typedef mpl::vector<mpl::int_<0>, mpl::int_<1>, mpl::int_<2>>::type Val1;
  typedef mpl::vector<mpl::int_<1>, mpl::int_<2>, mpl::int_<3>>::type Val2;
  typedef mpl::vector<mpl::int_<4>, mpl::int_<3>, mpl::int_<2>>::type Val3;  

  typedef ugly_sum<Val1,Val2,Val3>::type sum;
  
  // In fact sum goes by column and result is : 5,6,7
  cout << "ugly_sum<0>: " << mpl::at<sum, mpl::int_<0>>::type::value << endl;
  cout << "ugly_sum<1>: " << mpl::at<sum, mpl::int_<1>>::type::value << endl;
  cout << "ugly_sum<2>: " << mpl::at<sum, mpl::int_<2>>::type::value << endl;

  
  typedef pretty_sum<Val1, Val2, Val3>::type sum2;
  
  // In fact sum goes by column and result is : 5,6,7
  cout << "pretty_sum<0>: " << mpl::at<sum2, mpl::int_<0>>::type::value << endl;
  cout << "pretty_sum<1>: " << mpl::at<sum2, mpl::int_<1>>::type::value << endl;
  cout << "pretty_sum<2>: " << mpl::at<sum2, mpl::int_<2>>::type::value << endl;

  typedef factorial<mpl::int_<5> >::type fact5;
  typedef factorial<mpl::int_<10> >::type fact10; 

  cout << "fact5 = " << fact5::value << endl;
  cout << "fact10 = " << fact10::value << endl;
  
  // print number_iter result
  cout << "number_iter: " << number_iter::type::value << endl;  // 3
  cout << "number_iter+1: " << mpl::deref< mpl::next<number_iter>::type >::type::value << endl;  // 4
  //sorting sequence example
  // print template result  
  cout  << "sorting_result: ";
  mpl::for_each<sorting_result>(seq_printer());
  cout << endl;
  

  exit(EXIT_SUCCESS);
}
