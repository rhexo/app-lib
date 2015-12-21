#include <boost/mpl/int.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/lower_bound.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/mpl/less.hpp>
#include <boost/mpl/zip_view.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/unpack_args.hpp>

using namespace boost::mpl::placeholders;
namespace mpl = boost::mpl;

template <class Seq, class MinSize>
struct padded_size
  : mpl::deref<typename mpl::lower_bound<typename mpl::transform<Seq, mpl::sizeof_<_> >::type, MinSize, mpl::less<_,_> >::type >
{};

/**
 * Greedy size computation into a lazy one with transform_view
 * transform_view<S,P> is a sequence whose elements are identical to the elements
 * of transform<S,P>, but with two important differences
 *  1. Its elements are computed ony "on demand", in other words, it`s lazy sequence
 *  2. Through the ::base member of any of its iterators, we can get an iterator
 *     to the corresponding position in S
 */
template <class Seq, class MinSize>
struct first_size_larger_than
  :mpl::deref<
  typename mpl::lower_bound<
    mpl::transform_view<Seq,mpl::sizeof_<_> >, MinSize >::type >
{};

/**
 * Combining multiple seequences
 */

// elements of zip_view<vector<S,T,U> are [[s1,t1,u1], [s2,t2,u2], [s3,t3,u3]]
// Elementwise some of vectorss might be written:
template <class V1, class V2, class V3>
struct ugly_sum
  :mpl::transform_view<
  mpl::zip_view<mpl::vector<V1,V2,V3> >,
  mpl::plus<
    mpl::at<_,mpl::int_<0> >,
    mpl::at<_,mpl::int_<1> >,
    mpl::at<_,mpl::int_<2> >
    >
  >
{};


// We can clean the code up using MPL`s unpack_args wrapper, which transform an
// N-argument lambda expression like mpl::plus<_,_,_> into a unary
// lambda expression when applied to a sequence of N elements.

template <class V1, class V2, class V3>
struct pretty_sum
  :mpl::transform_view<
  mpl::zip_view<mpl::vector<V1,V2,V3> >,
  mpl::unpack_args<mpl::plus<_,_,_> >
  >
{};
