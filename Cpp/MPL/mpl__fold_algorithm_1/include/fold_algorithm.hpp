#include <boost/mpl/int.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/clear.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/push_front.hpp>

using namespace std;
using namespace boost::mpl::placeholders;
namespace mpl = boost::mpl;


/**
 * Example of reverse algorithm
 */
template <class Seq>
struct fold_reverse
  : mpl::fold<
  Seq,
  typename mpl::clear<Seq>::type,  // initial type
  mpl::push_front<_,_>  //binary operation
  >
{};
