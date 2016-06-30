/** koi8-r encoding */

#include <memory>
#include <functional>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

/** Определяем шаблон для процедуры печати */
template <typename V> void print(V&);

int main (){

  /*
   * Инициализация вектора случайными числами
   */
  std::vector<double> V(100);
  std::generate(V.begin(),V.end(), rand);

  // -- на печать
  cout << "Инициализация вектора<double>: " << endl;
  print(V);
  cout << endl;

  /**
   * Выполняем сортировку вектора по модулю
   * Роль функционала играет определенная нами структура с перегруженным оператором ()
   */
  struct less_mag : public binary_function<double, double, bool> {
    bool operator() (double x, double y) { return fabs(x) < fabs(y); }
  };

  sort(V.begin(), V.end(), less_mag());

  // -- на печать
  cout << "Результат сортировкаипо модулю(less_mag): " << endl;
  print(V);
  cout << endl;


  /**
   * Сумма элементов вектора
   * Роль функцинала опять играет определенный пользователем класс
   */
  struct adder: public unary_function<double, void> {
    adder() : sum(0) {}
    double sum;
    void operator () (double x) { sum += x; }
  };

  adder result = for_each(V.begin(), V.end(), adder());
  cout << "Сумма: " << result.sum << endl << endl;

  exit(EXIT_SUCCESS);
}

/** Реализация процедуры печати */
template<typename V>
void print(V& v) {
  for(typename V::iterator it = v.begin(); it != v.end(); ++it) {
    if (it == v.end())
      cout << *it << "." << endl;
    else
      cout << *it << ", ";
  }
}
