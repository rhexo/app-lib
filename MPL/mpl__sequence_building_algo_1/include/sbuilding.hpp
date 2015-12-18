#include <boost/mpl/int.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/transform.hpp>
// #include <boost/mpl/reverse_transform.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/front_inserter.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/vector.hpp>

using namespace boost::mpl::placeholders;
namespace mpl = boost::mpl;

// starting sequences
typedef mpl::vector_c<int,1,2,3> v123;
typedef mpl::list_c<int,1,2,3> l123;

//transformation
typedef mpl::plus<_1,mpl::int_<5> >add5;

// using the default inserters
typedef mpl::transform<v123,add5>::type v678;
typedef mpl::transform<l123,add5>::type l678;
typedef mpl::reverse_transform<v123,add5>::type v876;
typedef mpl::reverse_transform<l123,add5>::type l876;

// this inserter is equivalent to the default
typedef mpl::transform<v123, add5, mpl::back_inserter<mpl::vector<> > >::type _v678;
// also equivalent to the default
typedef mpl::reverse_transform<l123, add5, mpl::front_inserter<mpl::list<> > >::type _l678;
// properties of input sequence don`t affect the result
typedef mpl::reverse_transform<v123, add5, mpl::front_inserter<mpl::list<> > >::type __l678;
