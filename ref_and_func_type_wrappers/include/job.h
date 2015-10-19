#ifndef JOB_H
#define JOB_H

#include <iostream>

using namespace std;


/** Специализация шаблона */
template<class T>
class Job {
 public:

  // конструктор + деструктор
 Job():res(0) {}
  ~Job(){};

  T arg;
  int res;


  void run(T arg) {
    // assign job parameter
    this->arg = arg;
    res += 1;

    cout << "arg = " << arg << ", res = " << this->res << endl;
  }

};


#endif
