/** implementing measures system in C++ */
#include <iostream>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/transform.hpp>

namespace measures{

  using namespace boost;
  using namespace std;

  // define dimentions
  typedef mpl::vector_c<int,1,0,0,0,0,0,0> mass;
  typedef mpl::vector_c<int,0,1,0,0,0,0,0> length;
  typedef mpl::vector_c<int,0,0,1,0,0,0,0> time;
  typedef mpl::vector_c<int,0,0,0,1,0,0,0> charge;
  typedef mpl::vector_c<int,0,0,0,0,1,0,0> temperature;
  typedef mpl::vector_c<int,0,0,0,0,0,1,0> intensity;
  typedef mpl::vector_c<int,0,0,0,0,0,0,1> angle;
  typedef mpl::vector_c<int,0,0,0,0,0,0,0> scalar;


  // composite dimentions
  typedef mpl::vector_c<int,0,1,-1,0,0,0,0> velocity;
  typedef mpl::vector_c<int,0,1,-2,0,0,0,0> acceleration;
  typedef mpl::vector_c<int,1,1,-1,0,0,0,0> momentum;
  typedef mpl::vector_c<int,1,1,-2,0,0,0,0> force;


  // quantity base class
  template <class T, class D>
  struct quantity
  {
    explicit quantity(T x) : m_value(x) {}
    T value() const {return m_value;}

  private:
    T m_value;

  };

  /** implementing +, valid for operation with the same types operands */
  template <class T, class D>
  quantity<T,D> operator+(quantity<T,D> x, quantity<T,D> y)
  {
    return quantity<T, D>(x.value() + y.value());
  };

  /** implementing -, valid for operation with the same types operands*/
  template <class T, class D>
  quantity<T,D> operator-(quantity<T,D> x, quantity<T,D> y)
  {
    return quantity<T, D>(x.value() - y.value());
  };

  // cout overloading
  template <class T, class D>
  ostream& operator<<( ostream& cout,  const quantity<T,D>& q)
  {
    return cout << q.value();
  };

  // metafunction class
  struct plus_f
  {
    template<class T1, class T2>
    struct apply
    {
      typedef typename mpl::plus<T1,T2>::type type;
    };
  };

  // overloading multiplity
  template <class T, class D1, class D2>
  quantity<T, typename mpl::transform<D1,D2,plus_f>::type>  // new dimensions of result
  operator*( quantity<T,D1> x, quantity<T,D2> y)
  {
    typedef typename mpl::transform<D1,D2,plus_f>::type dim;
    return quantity<T, dim>( x.value() * y.value() );
  };


};
