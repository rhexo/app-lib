#include <iostream>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

int main ()
{

  /** SETs */
  multiset<string> cities {
    "Braunschwieg", "Hanover", "Frankfurt",
      "New York", "Chicago", "Toronto", "Paris", "Frankfurt"
      };

  multimap<int,string> coll;
  coll.insert(pair<int,string>(100,"some info"));

  exit(EXIT_SUCCESS);

}
