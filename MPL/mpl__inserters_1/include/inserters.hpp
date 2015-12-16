#include <boost/mpl/int.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/inserter.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/placeholders.hpp>

using namespace std;
using namespace boost::mpl::placeholders;
namespace mpl = boost::mpl;

typedef mpl::copy<
  mpl::list<int,char,float>,
  mpl::back_inserter<mpl::vector<> >
  >::type result_vec;

/**
 * An inserter is nothing more than a type with two type members
 *  - ::state, a representation of information being carried through the algorithm
 *  - ::operation, a binary operation used to build new ::state from an output sequence element and the existing ::state
 */

// using inserter in calculations
typedef mpl::vector<
  mpl::vector_c<int, 1,2,3>,
  mpl::vector_c<int, 4,5,6>,
  mpl::vector_c<int, 7,8,9>
  > S;

typedef mpl::transform<
  S,  // inpus sequence
  mpl::front<_>,  // transformation selects front element
  mpl::inserter<
    mpl::int_<0>,  // results start with 0
  mpl::plus<_,_>  // and adds each output element
  >
  >::type sum; // 0+1+4+7 == 12
