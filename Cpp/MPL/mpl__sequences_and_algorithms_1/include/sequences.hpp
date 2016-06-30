#include <type_traits>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/end.hpp>

namespace seq {

  using namespace std;
  using namespace boost::mpl::placeholders;

  namespace mpl = boost::mpl;

  // vector of types
  typedef mpl::vector<char,short,int,long,float,double> types;

  typedef mpl::vector<char,short,int,double,float,long> types2;

  // locate a position of long in types
  typedef mpl::find<types, long>::type long_pos;

  typedef mpl::find<types2, long>::type long_pos2;

  // end mpl iterator
  typedef mpl::end<types>::type finish;

  typedef mpl::end<types2>::type finish2;

}
