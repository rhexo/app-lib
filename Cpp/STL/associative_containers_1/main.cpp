#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

int main ()
{

  /** SETs */
  multiset<string> cities {
    "Braunschwieg", "Hanover", "Frankfurt",
      "New York", "Chicago", "Toronto", "Paris", "Frankfurt"
      };


  // Print all elements
  for(const auto& elem : cities){
    cout << elem << " ";
  }
  cout << endl;

  // Add some extra cities
  cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

  // Print each element
  for(const auto& elem: cities)
    cout << elem << " ";
  cout << endl;

  /** MAPs */
  multimap<int,string> coll;

  // insert some elements in arbitary order
  //  - a value with key 1 gets inserted twice
  coll = { {5, "tagged"},
           {2, "a"},
           {1, "this"},
           {4, "of"},
           {6, "strings"},
           {3, "multimap"} };

  // add one new element (x2 with key 1)
  coll.insert(pair<int,string>(1,"is"));

  // Print all map elements
  //  - element mmber second is a value
  for( const auto& elem : coll)
    cout << elem.second << " ";
  cout << endl;

  /** Associative arrays */
  // type of container:
  //  - unordered_map: elements are key/value pairs
  //  - string: keys have type string
  //  - float: values have type float
  unordered_map<string,float> umap;

  // unordered map has a hash index access
  // On base of this using it as array with [] as access descriptor
  // insert some elements into the collection
  //  - using the syntax of an associative array
  umap["VAL1"] = 0.16f;
  umap["VAL2"] = 0.07f;
  umap["Pi"] = 3.1415f;
  umap["an arbitrary number"] = 4983.223f;
  umap["Null"] = 0.0f;

  // change value VAL1
  umap["VAL1"] += 0.03f;

  // print difference of VAL values
  cout << "VAL difference: " << umap["VAL1"] - umap["VAL2"] << endl;

  exit(EXIT_SUCCESS);

}
