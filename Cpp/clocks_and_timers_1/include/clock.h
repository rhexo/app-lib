#include <chrono>
#include <ratio>
#include <iostream>
#include <iomanip>

template <typename C>
void printClockData()
{
  using namespace std;

  cout << " - precision: ";
  // Если единица изменения часов меньше или равна одной милисекунде
  typedef typename C::period P;  // тип единицы измерения времени
  if (ratio_less_equal<P,milli>::value) {
    // Выполняем преобразование и печать в милисекундах
    typedef typename ratio_multiply<P,kilo>::type TT;
    cout << fixed << double(TT::num) / TT::den << " ms" << endl;
  } else {
    // Печатаем в секундах
    cout << fixed << double(P::num) / P::den << " sec" << endl;
  }
  cout << " - is_steady: " << boolalpha << C::is_steady << endl;
}
