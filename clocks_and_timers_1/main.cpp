#include <chrono>
#include <ratio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <clock.h>
#include <ctime>

using namespace std;


/** Определение перегруженного шаблона печати */
template <typename V, typename R>
ostream& operator << (ostream&, const chrono::duration<V,R>&);

/** Приведение timepoint к виду календарного времени */
string asString(const chrono::system_clock::time_point&);

/** Создаем точку отсчета для часов */
chrono::system_clock::time_point makeTimePoint(int, int, int, int, int, int=0);

int main () {

  auto system_start = chrono::system_clock::now();

  /** Durations */

  chrono::duration<int> twentySeconds(20);  // Базова ЕИ - секунда
  cout << twentySeconds.count() << endl;

  /** Используем рациональные числа, с целью представления значений duration в других ЕИ времени */
  chrono::duration<double,ratio<60>> halfAMinute(0.5);    // 0.5 * ratio<60,1>
  cout << halfAMinute.count() << endl;

  chrono::duration<long,ratio<1,1000>> oneMillisecond(1);
  cout << oneMillisecond.count() << endl;

  // Вывод: 29999 ms
  cout << "diff: " << (halfAMinute - oneMillisecond).count() << " ms" << endl;


  /** По аналогии опредеены и типы пространства имен chrono */
  /** Например: typedef duration<signed int-type>=29 bits, ratio<60>> minutes; */
  chrono::minutes threeHours(180);  // Три часа
  cout << chrono::duration_cast<chrono::hours>(threeHours).count() << "hours" << endl;

  // Выполняем печать с помощью перегруженной функции
  chrono::hours hh = chrono::duration_cast<chrono::hours>(threeHours);
  cout << "180 minutes is = " << hh << endl;

  /** Приведение вещественных значенией интервала */
  chrono::seconds ss = chrono::duration_cast<chrono::seconds>(halfAMinute);
  cout << "half a minute is " << halfAMinute << endl;

  /** Разложение интервала на hh::mm::ss */
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


  // Даем нагрузку
  for (int i = 0; i < 10000000; i++) {
    continue;
  }


  // Время провдолжительности работы программы
  auto diff = chrono::system_clock::now() - system_start;
  auto sec = chrono::duration_cast<chrono::milliseconds>(diff);

  cout << "Program runs: " << sec.count() << " ms" << endl;


  /** Timepoints */

  // Печатаем начало времен для системных часов
  chrono::system_clock::time_point tp;
  cout << "epoch: " << asString(tp) << endl;

  // Печатаем текущее время
  tp = chrono::system_clock::now();
  cout << "now: " << asString(tp) << endl;

  // Печатаем предел слева для часов системного времени
  tp = chrono::system_clock::time_point::min();
  cout << "min: " << asString(tp) << endl;

  // Печатаем предел справа для часов системного времени
  tp = chrono::system_clock::time_point::max();
  cout << "max: " << asString(tp) << endl;

  /** Timepoint arithmetics */

  // Определяем период равный одному дню
  typedef chrono::duration<int,ratio<24*3600>> Days;

  // Определяем значение времени по системным часам
  chrono::time_point<chrono::system_clock> tp_1; // Эквивалентно system_clock::time_point
  cout << "epoch: " << asString(tp_1) << endl;

  // Добавляем один день 23 часа и 55 миут
  tp_1 += Days(1) + chrono::hours(23) + chrono::minutes(55);
  cout << "later: "<< asString(tp_1) << endl;

  // Вычисляем разницу в минутах и днях
  diff = tp_1 - chrono::system_clock::time_point();
  cout << "diff: "
       << chrono::duration_cast<chrono::minutes>(diff).count()
       << " minutes." << endl;
  // Преобразуем относительно введенного нами типа данных
  Days days = chrono::duration_cast<Days>(diff);
  cout << "diff: " << days.count() << "day(s)" << endl;

  // Вычитаем один год (предположительно вычитаемый год является высокосным)
  tp_1 -= chrono::hours(24*365);
  cout << "-1 year: " << asString(tp_1) << endl;

  // Вычисляем 50 лет (утрируем и считаем год равным 365 дням)
  tp_1 -= chrono::duration<int,ratio<3600*24*365>>(50);
  cout << "-50 years: " << asString(tp_1) << endl;

  // Еще раз вычитаем 50 лет
  tp_1 -= chrono::duration<int,ratio<3600*24*365>>(50);
  cout << "-50 years: " << asString(tp_1) << endl;

  /** timepoint/calendar conversion */
  auto tp_m1 = makeTimePoint(2010,01,01,00,00);
  cout << "Make timepoint(1): " << asString(tp_m1) << endl;

  auto tp_m2 = makeTimePoint(2011,05,23,13,44);
  cout << "Make timepoint(2):" << asString(tp_m2) << endl;

  // Добавляем 50 лет к созданной точке времени
  tp_m1 += chrono::duration<int,ratio<3600*24*365>>(50);
  cout << "Add to timepoint(1) 50 years: " << asString(tp_m1) << endl;

  exit(EXIT_SUCCESS);

}

/** Перегружаем вывод для duration */
template <typename V, typename R>
ostream& operator << (ostream& s, const chrono::duration<V,R>& d)
{
  s << "[" << d.count() << " of " << R::num << "/" << R::den << "]";
  return s;
}

/** Печатаем timepoint */
string asString(const chrono::system_clock::time_point& tp)
{

  // Преобразуем к системному времени
  time_t t = chrono::system_clock::to_time_t(tp);
  string ts = ctime(&t);    // Выполняем преобразование к лаендарному времени
  ts.resize(ts.size()-1);   // Обрезаем последующий перенос строки
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
  t.tm_isdst = -1; // вычислять с учетом перевода часового пояса
  time_t tt = mktime(&t);
  if (tt == -1 )
    throw "no valid system time";

  return chrono::system_clock::from_time_t(tt);

}
