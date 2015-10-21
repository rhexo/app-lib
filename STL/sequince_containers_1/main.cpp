#include <vector>
#include <array>
#include <list>
#include <iostream>
#include <cstdlib>


using namespace std;

int main ()
{

  /** VECTOR */

  vector<int> vec;

  // Добавляем элементы со значениями 1..6
  for (int i = 0; i < 6; i++) {
    vec.push_back(i+1);
  }

  // Выводим все элементы вектора через пробел
  for (int i=0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;


  /** ARRAY */

  array<string,5> ar  = {"hello", "world"};

  // Распечатываем массив
  for (int i = 0; i < ar.size() ; i++) {
    cout << i << ": "<< ar[i] << endl;
  }


  /** LIST */

  list<char> l;

  for (char c='a'; c <= 'z'; ++c) {
    l.push_back(c);
  }

  // Распечатываем список
  for(auto elem : l)
    cout << elem << ' ';
  cout << endl;

  exit(EXIT_SUCCESS);

}
