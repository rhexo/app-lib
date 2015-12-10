#include <type_traits>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>

namespace seq {

  using namespace std;
  using namespace boost::mpl::placeholders;

  namespace mpl = boost::mpl;

  // dereference the iterator
  typedef mpl::deref<long_pos>::type x;

  // next++
  typedef mpl::next<long_pos>::type float_pos;
  typedef mpl::deref<float_pos>::type y;

}
