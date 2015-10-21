#include <chrono>
#include <ratio>
#include <iostream>
#include <iomanip>

template <typename C>
void printClockData()
{
  using namespace std;

  cout << " - precision: ";
  // ���� ������� ��������� ����� ������ ��� ����� ����� �����������
  typedef typename C::period P;  // ��� ������� ��������� �������
  if (ratio_less_equal<P,milli>::value) {
    // ��������� �������������� � ������ � ������������
    typedef typename ratio_multiply<P,kilo>::type TT;
    cout << fixed << double(TT::num) / TT::den << " ms" << endl;
  } else {
    // �������� � ��������
    cout << fixed << double(P::num) / P::den << " sec" << endl;
  }
  cout << " - is_steady: " << boolalpha << C::is_steady << endl;
}
