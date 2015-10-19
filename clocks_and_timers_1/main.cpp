#include <chrono>
#include <ratio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main () {

  /** Duration */
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

  exit(EXIT_SUCCESS);

}

/** Перегружаем вывод для duration */
