/** Example of using arrays */
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <cstdlib>

#include "include/printer.h"

using namespace std;

int main() {

  // create empty vector for strings
  vector<string> sentence;

  // reserve memory for five elements to avoid reallocation
  sentence.reserve(5);

  // append some elements
  sentence.push_back("Hello,");
  sentence.insert(sentence.end(), {"how", "are", "you", "?"});

  // print
  Printer().collection<vector<string>>(sentence, "Print elements: ", true);


  // print technical data
  cout << "  max_size(): " << sentence.max_size() << endl;
  cout << "  size(): " << sentence.size() << endl;
  cout << "  capacity(): " << sentence.capacity() << endl;

  // swap second and fourth elements
  swap(sentence[1], sentence[3]);

  // insert element "always" before element "?"
  sentence.insert(find(sentence.cbegin(),sentence.cend(),"?"),"always");

  // assign "!" to the last element
  sentence.back() = "!";

  // print
  Printer().collection<vector<string>>(sentence, "Somthing changed: ", true);

  // print some technical data again
  cout << "  size(): " << sentence.size() << endl;
  cout << "  capacity(): " << sentence.capacity() << endl;

  // delete last two elements
  sentence.pop_back();
  sentence.pop_back();

  // shrink capacity (since C++11)
  sentence.shrink_to_fit();

  // print some technical data again
  cout << "  size(): " << sentence.size() << endl;
  cout << "  capacity(): " << sentence.capacity() << endl;

  exit(EXIT_SUCCESS);
};
