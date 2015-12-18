#include <boost/mpl/int.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/lower_bound.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/mpl/less.hpp>

using namespace boost::mpl::placeholders;
namespace mpl = boost::mpl;

template <class Seq, class MinSize>
struct padded_size
  : mpl::deref<typename mpl::lower_bound<typename mpl::transform<Seq, mpl::sizeof_<_> >::type, MinSize, mpl::less<_,_> >::type >
{};
