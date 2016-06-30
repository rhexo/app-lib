#include <functional>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <job.h>

using namespace std;
using namespace std::placeholders;

template <typename T> void foo(T);

int main () {

  /**
   * reference wrappers
   */

  int x(99);

  // T becomes int&
  foo(ref(x));

  // T becomes const int&
  foo(cref(x));

  /**
   * function type wrappers
   */

  float fx = 1.07f;

  Job<float> jj_t;

  vector<reference_wrapper<Job<float>>> list_of_jobs;

  list_of_jobs.push_back(ref(jj_t));
  list_of_jobs.push_back(ref(jj_t));

  function<void(Job<float>&,float)> mf_t;

  mf_t = &Job<float>::run;
  // mf_t(ref(jj_t),1.02f);

  for(reference_wrapper<Job<float>> rjob : list_of_jobs){

    ++fx;
    mf_t(rjob,fx);

    const Job<float> &job = rjob;
    cout << "in loop const arg = " << job.arg << endl;
  }


  cout << "Total output(2): arg = " << jj_t.arg << ", res = " << jj_t.res << endl;

  exit(EXIT_SUCCESS);
};

template <typename T>
void foo(T val) {
  cout << val << endl;
};
