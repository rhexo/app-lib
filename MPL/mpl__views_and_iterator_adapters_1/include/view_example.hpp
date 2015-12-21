#include <type_traits>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/mpl/lower_bound.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/multiplies.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/sort.hpp>


using namespace std;
using namespace boost::mpl::placeholders;

namespace mpl=boost::mpl;

// Example 1
// does seq contain int, int&, int const&, int volatile&,
// or int const volatile&?

typedef mpl::vector<double, float, int volatile&, char>::type Seq;

typedef mpl::contains<
  mpl::transform_view<
    Seq,
    remove_cv<remove_reference<_> >
    >,
  int
  >::type found;

// Example 2
// find the position of the least integer whose factorial >= n

template <class N>
struct factorial
  :mpl::eval_if<
  mpl::equal_to<
    N,
    mpl::int_<0> 
    >,
  mpl::int_<1>, 
  mpl::multiplies<
    N, 
    factorial< 
      mpl::minus<
        N, 
        mpl::int_<1> 
        > 
      > 
    > 
  >::type 
{};

typedef mpl::lower_bound<
  mpl::transform_view< 
    mpl::range_c<int,0,13>,
    factorial<_1> >,
  mpl::int_<5>
  >::type::base number_iter;

// Example 3
// return a sorted vector of all the elements from seq1 and seq2

typedef mpl::range_c<int,14,17>::type seq1;
typedef mpl::vector_c<int,7,4,2,1,10>::type seq2;

typedef mpl::sort<
  mpl::copy<
    mpl::joint_view<seq1, seq2>,
    mpl::back_inserter< mpl::vector<> >
  >::type
>::type sorting_result;
