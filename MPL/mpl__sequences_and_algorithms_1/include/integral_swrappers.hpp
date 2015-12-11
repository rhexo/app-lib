#include <type_traits>
#include <boost/mpl/vector/vector10_c.hpp>


namespace seq {

  using namespace std;
  using namespace boost::mpl::placeholders;

  namespace mpl = boost::mpl;


  // Integral sequence wrapper
  typedef mpl::vector10_c<int,1,2,3,4,5,6,7,8,9,10> v10;

  // Sequence derivation


};
