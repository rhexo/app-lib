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
  
  typedef IteratorSeq base;

  // wrap all sequence elements with deref metafunction
  typedef typename mpl::transform<
    IteratorSeq
    ,mpl::deref<_1>
    >::type type;
};

// to increment a zip iterator we need to increment each of its component iterators
namespace boost { 
  namespace mpl {
    
    // specialize next<...> for zip_iterator
    template <class IteratorSeq>
    struct next<::zip_iterator<IteratorSeq> >
    {
      typedef ::zip_iterator<
        typename transform<
          IteratorSeq,
          next<_1>
          >::type
        > type;
    };
  }};


// build zip_view
template <class Sequences>
struct zip_view
: mpl::iterator_range<
  zip_iterator<
    typename mpl::transform_view<
      Sequences, mpl::begin<_1> 
      >::type,
    >
  zip_iterator<
    typename mpl::transform_view<
      Sequences, mpl::end<_1>
      >::type
    >
  > 
{};

