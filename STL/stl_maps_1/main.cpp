/** Using map and multimap examples */

#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <utility>

#include "include/printer.h"
#include "include/runtimestringcmp.h"

using namespace std;

// container type:
// - map with:
//  - string keys
//  - string values
//  - the special comparsion object type
typedef map<string,string, RuntimeStringCmp> StringStringMap;

// function that fills and prints such containers (StringStringMap)
void fillAndPrint(StringStringMap& );

int main () {

  /** Using Algorithms and Lambdas with Maps/Multimaps */
  cout << "Example 1:" << endl;

  map<string,double> i1_coll
  {
    {"tim", 9.9},
      {"struppi", 11.7}
  };


  // square the value of each element:
  for_each(i1_coll.begin(), i1_coll.end(),
           [] (pair<const string, double>& elem){
             elem.second *= elem.second;
           });

  // print each element
  for_each(i1_coll.begin(), i1_coll.end(),
           [] (const map<string,double>::value_type& elem) {
             cout << elem.first << ": " << elem.second << endl;
           });


  /** Using a Map as an Associative Array */
  cout << "Example 2:" << endl;
  // Create map / associative array
  // - keys are strings
  // - values are floats
  typedef map<string,float> StringFloatMap;

  // create empty container
  StringFloatMap stocks;

  // insert some elements
  stocks["BASF"] = 369.50;
  stocks["VW"] = 413.50;
  stocks["Diamler"] = 819.00;
  stocks["BMW"] = 834.00;
  stocks["Simens"] = 842.20;

  // print all elements
  StringFloatMap::iterator pos;

  // left-adjust values
  cout << left;

  for (pos = stocks.begin(); pos != stocks.end(); ++pos){
    cout << "stock: " << setw(12) << pos->first
         << "price: " << pos->second << endl;
  }
  cout << endl;

  // boom (all prices doubled)
  for (pos=stocks.begin(); pos != stocks.end(); ++ pos){
    pos->second *= 2;
  }

  // print all elements
  for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
    cout << "stock: " << setw(12) << pos->first
         << "price: " << pos->second << endl;
  }
  cout << endl;

  // rename key from "VW" to "Volkswagen"
  // - provided only by exchanging element

  stocks["Volkswagen"] = stocks["VW"];
  stocks.erase("VW");

  // print all elements
  for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
    cout << "stock: " << setw(12) << pos->first
         << "price: " << pos->second << endl;
  }
  cout << endl;


  /** Using multimap as dictionary */
  cout << "Example 3:" << endl;

  // create multimap as string/string bictionary
  multimap<string, string> dict;

  // insert some elements in random order
  dict.insert( {
      {"day", "Tag"},
        {"stange", "fremd"},
          {"car", "Auto "},
            {"smart", "elegant"},
              {"trait", "Merkmal"},
                {"strange", "seltsam"},
                  {"smart", "raffiniert"},
                    {"smart", "klug"},
                      {"clever", "raffiniert"}
    });

  // print all elements
  cout.setf(ios::left, ios::adjustfield);
  cout << ' ' << setw(10) << "english "
       << "german " << endl;
  cout << setfill('-') << setw(20) << ""
       << setfill(' ') << endl;
  for (const auto& elem : dict)
    cout << ' ' << setw(10) << elem.first
         << elem.second << endl;

  // pritn all values for key "smart"
  string word("smart");
  cout << word << ": " << endl;
  for (auto pos = dict.lower_bound(word); pos != dict.upper_bound(word); ++pos){
    cout << "      " << pos->second << endl;
  }

  // print allkeys with value "raffiniert"
  word = ("raffiniert");
  cout << word << ": " << endl;
  for(const auto& elem : dict) {
    if (elem.second == word){
      cout << "      " << elem.first << endl;
    }
  }


  /** Finding elements with certain values */
  cout << "Example 4:" << endl;
  // map with floats as key and value
  // - initializing keys and values are automatically converted to float
  map<float,float> i4_coll
  {
    {1,7}, {2,4}, {3,2}, {4,3}, {5,6}, {6,1}, {7,3}
  };

  // search an element with KEY 3.0 (logarithmic omplexity)
  auto posKey = i4_coll.find(3.0);
  if (posKey != i4_coll.end()) {
    cout << "key 3.0 found ("
         << posKey->first << ":"
         << posKey->second << ")" << endl;
  }


  // search an element with VALUE 3.0 (linear complexity)
  auto posVal = find_if(i4_coll.begin(),i4_coll.end(),
                        [] (const pair<float,float>& elem) {
                          return elem.second == 3.0;
                        });

  if (posVal != i4_coll.end()) {
    cout << "Value 3.0 found ("
         << posVal->first << ":"
         << posVal->second << ")" << endl;
  }


  /** Maps, Strings and sorting Criterion at runtime */
  cout << "Example 5:" << endl;
  // create a container with the default comparsion criterion
  StringStringMap i5_coll;
  fillAndPrint(i5_coll);

  // create object for case-insensitive comparsions
  RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);

  // create a container with the case-insensitive comparsions criterion
  StringStringMap i5_coll_ins(ignorecase);
  fillAndPrint(i5_coll_ins);


  exit(EXIT_SUCCESS);
};

void fillAndPrint(StringStringMap& coll)
{
  // insert elements in random order
  coll["Deutschland"] = "Germany";
  coll["deutch"] = "German";
  coll["Haken"] = "snag";
  coll["arbeiten"] = "work";
  coll["Hund"] = "dog";
  coll["gehen"] = "go";
  coll["Unternehmen"] = "enterprise";
  coll["unternehmen"] = "undertake";
  coll["gehen"] = "walk";
  coll["Bestatter"] = "undertaker";

  // print elements
  cout.setf(ios::left, ios::adjustfield);
  for (const auto& elem : coll) {
    cout << setw(15) << elem.first << " " << elem.second << endl;
  }
  cout << endl;
}
