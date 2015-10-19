#include <type_traits>
#include <iostream>
#include <typeinfo>
#include <cstdlib>

using namespace std;

int main () {

  cout << boolalpha;


  /**
   * Type traits
   */
  cout << "is_const<int>: " << is_const<int>::value << endl;
  cout << "is_const<const int>: " << is_const<const int>::value << endl;
  cout << "is_const<int* const>: " << is_const<int* const>::value << endl;
  cout << "is_const<const int*>::value: " << is_const<const int*>::value << endl;
  cout << "is_const<const int&>::value: " << is_const<const int&>::value << endl;
  cout << "is_const<int[]>::value: " << is_const<int []>::value << endl;
  cout << "is_const<const int[]>::value" << is_const<const int[]>::value << endl;

  /**
   * Type relations
   */
  cout << "is_assignable<int,int>::value: " << is_assignable<int,int>::value << endl;
  cout << "is_assignable<int&,int>::value: " << is_assignable<int&,int>::value << endl;
  cout << "is_assignable<int&&,int>::value: " << is_assignable<int&&,int>::value << endl;
  cout << "is_assignable<long&,int>::value: " << is_assignable<long&,int>::value << endl;
  cout << "is_assignable<const char*,string>::value: " << is_assignable<const char*,string>::value << endl;
  cout << "is_assignable<string,const char*>::value: " << is_assignable<string,const char*>::value << endl;

  /**
   * Type modifers
   */
  typedef int T;
  cout << "add_const<T>::type: " << typeid(add_const<T>::type()).name() << endl;
  // cout << "add_lvalue_reference<T>::type: " << add_lvalue_reference<T>::type() << endl;
  // cout << "add_rvalue_reference<T>::type: " << add_rvalue_reference<T>::type() << endl;
  cout << "add_pointer<T>::type: " << typeid(add_pointer<T>::type()).name() << endl;
  cout << "make_unsigned<T>::type: " << typeid(make_unsigned<T>::type()).name() << endl;
  cout << "remove_const<T>::type: " << typeid(remove_const<T>::type()).name() << endl;
  cout << "remove_reference<T>::type: " << typeid(remove_reference<T>::type()).name() << endl;
  cout << "remove_pointer<T>::type: " << typeid(remove_pointer<T>::type()).name() << endl;

  exit(EXIT_SUCCESS);
}
