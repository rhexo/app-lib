#include <ratio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main ( ){

  cout << boolalpha;

  typedef ratio<5,3> FiveThirds;
  cout << FiveThirds::num << "/" << FiveThirds::den << endl;

  typedef ratio<25,15> AlsoFiveThirds;
  cout << AlsoFiveThirds::num << "/" << AlsoFiveThirds::den << endl;

  ratio<42,42> one;
  cout << one.num << "/" << one.den << endl;

  ratio<0> zero;
  cout << zero.num << "/" << zero.den << endl;

  typedef ratio<7,-3> Neg;
  cout << Neg::num << "/" << Neg::den << endl;

  typedef ratio_equal<FiveThirds, AlsoFiveThirds> equal_result;
  cout << "equal (5/3, 25/15) ? " << equal_result::value << endl;

  typedef ratio_divide<FiveThirds, AlsoFiveThirds> divide_result;
  cout << "divide (5/3, 25/15) ? " << divide_result::num << "/" << divide_result::den << endl;

  typedef ratio_multiply<FiveThirds, AlsoFiveThirds> multiply_result;
  cout << "multiply (5/3, 25/15) ? " << multiply_result::num << "/" << multiply_result::den << endl;

  exit(EXIT_SUCCESS);
}
