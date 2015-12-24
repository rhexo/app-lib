#include <boost/mpl/int.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/deref.hpp>

using namespace std;
using namespace boost::mpl::placeholders;
namespace mpl=boost::mpl;

// zip_iterator - iterator that operate on a sequence of iterators into those
// input sequences

template <class IteratorSeq>
struct zip_iterator
{
  typedef mpl::forward_iterator_tag category;
  
};


