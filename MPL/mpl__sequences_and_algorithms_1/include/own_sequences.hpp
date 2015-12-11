#include <type_traits>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/pop_front.hpp>

namespace seq {

  using namespace std;
  using namespace boost::mpl::placeholders;

  namespace mpl = boost::mpl;

  /**
   * Writing a tiny sequence
   */

  struct none {}; // tag type to denote no element

  template <class T0 = none, class T1 = none, class T2 = none>
  struct tiny {
    typedef tiny type;
    typedef T0 t0;
    typedef T1 t1;
    typedef T2 t2;
  };

  // pop front element of S, unless it`s empty
  typedef mpl::eval_if<
    mpl::empty<S>,
    mpl::identity<S>,
    mpl::pop_front<S>
    >::type r1;

  // likewise
  typedef mpl::eval_if<
    mpl::empty<S>,
    S,  // when invoked, S return S
    mpl::pop_front<S>
    >::type r2;

  /**
   * The other three nested typedefs, t0, t1 and t2, makeit easy for any metafunction to access a tiny sequences elements
   */

  // tiny elements class wrapper
  template <class Tiny>
  struct manipulate_tiny
  {
    // what`s T0?
    typedef typename Tiny::t0 t0;
  };

};
