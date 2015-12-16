#include <boost/mpl/int.hpp>
#include <boost/mpl/max_element.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/mpl/replace.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/placeholders.hpp>

namespace mpl = boost::mpl;

namespace seq {

  /**
   * Given a nonempty sequence Seq, returns the largest type in an
   * identical sequence where all instances of float have been replaced by
   * double
   */

  template <class Seq>
  struct biggest_float_as_double
    :mpl::deref<
    typename mpl::max_element<
      typename mpl::replace<
        Seq,
        float,
        double
        >::type,
      mpl::less<mpl::sizeof_<mpl::_1>, mpl::sizeof_<mpl::_2> >
      >::type
    >{};

};

// namespace iter {

//   // an iterator manner
//   // define as metafunction
//   template <class Seq>
//   struct biggest_float_as_double
//   {
//     typedef typename mpl::replace<
//       typename mpl::begin<Seq>::type,
//       typename mpl::end<Seq>::type,
//       float,
//       double
//       >::type replaced;

//     typedef typename mpl::max_element<
//       typename mpl::begin<replaced>::type,
//       typename mpl::end<replaced>::type,
//       mpl::less<mpl::sizeof_<mpl::_1>,mpl::sizeof_<mpl::_2> >
//       >::type max_pos;

//     typedef typename mpl::deref<max_pos>::type type;

//   };

// };
