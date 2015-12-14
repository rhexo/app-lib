#include <type_traits>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/iterator_tags.hpp>
#include <boost/mpl/at.hpp>


namespace boost {
  namespace mpl {

    /**
     * Writing a tiny sequence
     */

    struct none {}; // tag type to denote no element

    // add ::tag to tiny

    struct tiny_tag {};

    template <class T0 = none, class T1 = none, class T2 = none>
    struct tiny {
      typedef tiny_tag tag;
      typedef tiny type;
      typedef T0 t0;
      typedef T1 t1;
      typedef T2 t2;
    };


    /**
     * The other three nested typedefs t0, t1 and t2, makeit easy for any metafunction to access a tiny sequences elements
     */

    // tiny elements class wrapper
    template <class Tiny>
    struct manipulate_tiny
    {
      // what`s T0?
      typedef typename Tiny::t0 t0;
    };

    /**
     * Implementing at for tiny
     */
    template <class Tiny, int N> struct tiny_at;

    // partially specialized accessors for each index
    template <class Tiny>
    struct tiny_at<Tiny,0>
    {
      typedef typename Tiny::t0 type;
    };

    template <class Tiny>
    struct tiny_at<Tiny, 1>
    {
      typedef typename Tiny::t1 type;
    };

    template <class Tiny>
    struct tiny_at<Tiny,2>
    {
      typedef typename Tiny::t2 type;
    };


    // own iterator metaclass
    template <class Tiny, class Pos>
    struct tiny_iterator
    {
      typedef random_access_iterator_tag category;
    };

    // own next/prior handlers

    // forward iterator requirement
    template <class Tiny, class Pos>
    struct next<tiny_iterator<Tiny, Pos> >
    {
      typedef tiny_iterator<
        Tiny,
        typename next<Pos>::type
        > type;
    };

    // bidirectional operator requirement
    template <class Tiny, class Pos>
    struct prior<tiny_iterator<Tiny,Pos> >
    {
      typedef tiny_iterator<
        Tiny,
        typename prior<Pos>::type
        > type;
    };


    // template <class T0, class T1, class T2, class Pos >
    // struct at<tiny<T0,T1,T2>,Pos >
    //   : tiny_at<tiny<T0,T1,T2>,Pos::value >
    // {};

    // write an explicit(full) specialization of mpl::at_impl
    template <>
    struct at_impl<tiny_tag>
    {
      template <class Tiny, class N >
      struct apply
        :tiny_at<Tiny, N::value >
      {};
    };


  }
}
