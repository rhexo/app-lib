#include <type_traits>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
//#include <boost/mpl/vector/vector10.hpp>
#include <boost/mpl/vector/vector20.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/map.hpp>

namespace seq {

  using namespace std;
  using namespace boost::mpl::placeholders;

  namespace mpl = boost::mpl;

  // list


  // vector
  typedef mpl::vector9<int[1],int[2],int[3],int[4],int[5],int[6],int[7],int[8],int[9]> s9;

  typedef mpl::push_back<s9,int[10]>::type s10; // OK
  typedef mpl::push_back<s10,int[11]>::type s11;  // Error, work only with vector20.hpp

  // range_c
  typedef mpl::range_c<long,10,20> r10;

  // map
  typedef mpl::map<
    mpl::pair<bool, unsigned char>,
    mpl::pair<unsigned char, unsigned short>,
    mpl::pair<unsigned short, unsigned int>,
    mpl::pair<unsigned int, unsigned long>,
    mpl::pair<signed char, signed short>,
    mpl::pair<signed short, signed int>,
    mpl::pair<signed int, signed long>
    >::type to_larger;




};
