#include <chrono>
#include <ratio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <clock.h>
#include <ctime>

using namespace std;


/** ����������� �������������� ������� ������ */
template <typename V, typename R>
ostream& operator << (ostream&, const chrono::duration<V,R>&);

/** ���������� timepoint � ���� ������������ ������� */
string asString(const chrono::system_clock::time_point&);

/** ������� ����� ������� ��� ����� */
chrono::system_clock::time_point makeTimePoint(int, int, int, int, int, int=0);

int main () {

  auto system_start = chrono::system_clock::now();

  /** Durations */

  chrono::duration<int> twentySeconds(20);  // ������ �� - �������
  cout << twentySeconds.count() << endl;

  /** ���������� ������������ �����, � ����� ������������� �������� duration � ������ �� ������� */
  chrono::duration<double,ratio<60>> halfAMinute(0.5);    // 0.5 * ratio<60,1>
  cout << halfAMinute.count() << endl;

  chrono::duration<long,ratio<1,1000>> oneMillisecond(1);
  cout << oneMillisecond.count() << endl;

  // �����: 29999 ms
  cout << "diff: " << (halfAMinute - oneMillisecond).count() << " ms" << endl;


  /** �� �������� ��������� � ���� ������������ ���� chrono */
  /** ��������: typedef duration<signed int-type>=29 bits, ratio<60>> minutes; */
  chrono::minutes threeHours(180);  // ��� ����
  cout << chrono::duration_cast<chrono::hours>(threeHours).count() << "hours" << endl;

  // ��������� ������ � ������� ������������� �������
  chrono::hours hh = chrono::duration_cast<chrono::hours>(threeHours);
  cout << "180 minutes is = " << hh << endl;

  /** ���������� ������������ ��������� ��������� */
  chrono::seconds ss = chrono::duration_cast<chrono::seconds>(halfAMinute);
  cout << "half a minute is " << halfAMinute << endl;

  /** ���������� ��������� �� hh::mm::ss */
  chrono::milliseconds ms(7255101);

  chrono::hours h1 = chrono::duration_cast<chrono::hours>(ms);
  chrono::minutes m1 = chrono::duration_cast<chrono::minutes>(ms % chrono::hours(1));
  chrono::seconds s1 = chrono::duration_cast<chrono::seconds>(ms % chrono::minutes(1));
  chrono::milliseconds ms1 = chrono::duration_cast<chrono::milliseconds>(ms % chrono::seconds(1));

  cout << ms.count() << " ms is " << setfill('0')
       << setw(2) << h1.count() << "::"
       << setw(2) << m1.count() << "::"
       << setw(2) << s1.count() << "::"
       << setw(3) << ms1.count() << endl;



  /** Clocks and timepoints */
  cout << endl;
  cout << "\nsystem_clock: " << endl;
  printClockData<chrono::system_clock>();
  cout << "\nhigh_resolution_clock: " << endl;
  printClockData<chrono::high_resolution_clock>();
  cout << "\nsteady_clock: " << endl;
  printClockData<chrono::steady_clock>();


  // ���� ��������
  for (int i = 0; i < 10000000; i++) {
    continue;
  }


  // ����� ������������������ ������ ���������
  auto diff = chrono::system_clock::now() - system_start;
  auto sec = chrono::duration_cast<chrono::milliseconds>(diff);

  cout << "Program runs: " << sec.count() << " ms" << endl;


  /** Timepoints */

  // �������� ������ ������ ��� ��������� �����
  chrono::system_clock::time_point tp;
  cout << "epoch: " << asString(tp) << endl;

  // �������� ������� �����
  tp = chrono::system_clock::now();
  cout << "now: " << asString(tp) << endl;

  // �������� ������ ����� ��� ����� ���������� �������
  tp = chrono::system_clock::time_point::min();
  cout << "min: " << asString(tp) << endl;

  // �������� ������ ������ ��� ����� ���������� �������
  tp = chrono::system_clock::time_point::max();
  cout << "max: " << asString(tp) << endl;

  /** Timepoint arithmetics */

  // ���������� ������ ������ ������ ���
  typedef chrono::duration<int,ratio<24*3600>> Days;

  // ���������� �������� ������� �� ��������� �����
  chrono::time_point<chrono::system_clock> tp_1; // ������������ system_clock::time_point
  cout << "epoch: " << asString(tp_1) << endl;

  // ��������� ���� ���� 23 ���� � 55 ����
  tp_1 += Days(1) + chrono::hours(23) + chrono::minutes(55);
  cout << "later: "<< asString(tp_1) << endl;

  // ��������� ������� � ������� � ����
  diff = tp_1 - chrono::system_clock::time_point();
  cout << "diff: "
       << chrono::duration_cast<chrono::minutes>(diff).count()
       << " minutes." << endl;
  // ����������� ������������ ���������� ���� ���� ������
  Days days = chrono::duration_cast<Days>(diff);
  cout << "diff: " << days.count() << "day(s)" << endl;

  // �������� ���� ��� (���������������� ���������� ��� �������� ����������)
  tp_1 -= chrono::hours(24*365);
  cout << "-1 year: " << asString(tp_1) << endl;

  // ��������� 50 ��� (�������� � ������� ��� ������ 365 ����)
  tp_1 -= chrono::duration<int,ratio<3600*24*365>>(50);
  cout << "-50 years: " << asString(tp_1) << endl;

  // ��� ��� �������� 50 ���
  tp_1 -= chrono::duration<int,ratio<3600*24*365>>(50);
  cout << "-50 years: " << asString(tp_1) << endl;

  /** timepoint/calendar conversion */
  auto tp_m1 = makeTimePoint(2010,01,01,00,00);
  cout << "Make timepoint(1): " << asString(tp_m1) << endl;

  auto tp_m2 = makeTimePoint(2011,05,23,13,44);
  cout << "Make timepoint(2):" << asString(tp_m2) << endl;

  // ��������� 50 ��� � ��������� ����� �������
  tp_m1 += chrono::duration<int,ratio<3600*24*365>>(50);
  cout << "Add to timepoint(1) 50 years: " << asString(tp_m1) << endl;

  exit(EXIT_SUCCESS);

}

/** ����������� ����� ��� duration */
template <typename V, typename R>
ostream& operator << (ostream& s, const chrono::duration<V,R>& d)
{
  s << "[" << d.count() << " of " << R::num << "/" << R::den << "]";
  return s;
}

/** �������� timepoint */
string asString(const chrono::system_clock::time_point& tp)
{

  // ����������� � ���������� �������
  time_t t = chrono::system_clock::to_time_t(tp);
  string ts = ctime(&t);    // ��������� �������������� � ����������� �������
  ts.resize(ts.size()-1);   // �������� ����������� ������� ������
  return ts;
}

chrono::system_clock::time_point
makeTimePoint(int year, int mon, int day, int hour, int min, int sec)
{
  struct tm t;
  t.tm_sec = sec;
  t.tm_min = min;
  t.tm_hour = hour;
  t.tm_mday = day;
  t.tm_mon = mon - 1;
  t.tm_year = year - 1900;
  t.tm_isdst = -1; // ��������� � ������ �������� �������� �����
  time_t tt = mktime(&t);
  if (tt == -1 )
    throw "no valid system time";

  return chrono::system_clock::from_time_t(tt);

}
