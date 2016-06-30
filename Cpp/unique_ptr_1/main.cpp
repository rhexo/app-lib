#include <memory>
#include <iostream>
#include <string>
#include <dirent.h>
#include <cstring>
#include <cerrno>
#include <cstdlib>


using namespace std;


// example of own dleter
class DirCloser{
public:
  void operator () (DIR*dp) {
    if (closedir(dp) != 0) {
      cerr << "OOPS: close dir failed." << endl;
      return;
    }
    cout << "dir closed." << endl;
  }
};


int main (){

  /**
   * Basic operations
   */

  // create and initialize pointer to string
  unique_ptr<string> up(new string("nico"));

  (*up)[0] = 'N';

  up->append("lai");
  // print changes


  if (up)   // the same result gets: if (up != nullptr) or if (up.get() != nullptr)
    cout << *up << endl;

  // up = nullptr;  OK
  // up.reset();    OK

  string *sp = up.release();


  /**
   * Transfer owner of unique_ptr
   */

  unique_ptr<int> up1(new int{100});
  unique_ptr<int> up2;


  up2 = move(up1);   // other variants gets error

  if (up2)
    cout << "up2 after moving is " << *up2 << endl;


  /**
   * Example with own deleter
   */

  // open current directory
  unique_ptr<DIR,DirCloser> pDir(opendir("."));

  // process each direcotry entry
  struct dirent *dp;
  while ((dp = readdir(pDir.get())) != nullptr) {
    string filename(dp->d_name);
    cout << "process " << filename << endl;
  }

  pDir.reset();

  exit(EXIT_SUCCESS);

}
