/** STL containers implementing with reference semantics */

#include <iostream>
#include <memory>
#include <string>
#include <set>
#include <deque>
#include <algorithm>
#include <cstdlib>

#include "include/item.h"

using namespace std;

int main ()
{

  // type of implementing with reference semantics
  typedef shared_ptr<Item> ItemPtr;

  set<ItemPtr> allItems;
  deque<ItemPtr> bestsellers;

  // insert objects into collections
  // - bestsellers are in both collections
  bestsellers = {
    ItemPtr(new Item("Kong Yize",20.10)),
    ItemPtr(new Item("A Midsummer Night`s Dream", 14.99)),
    ItemPtr(new Item("The Maltese Falcon", 9.88))
  };

  allItems = {
    ItemPtr(new Item("Water", 0.44)),
    ItemPtr(new Item("Pizza", 2.22))
  };

  allItems.insert(bestsellers.begin(), bestsellers.end());

  // print contents of both collections
  printItems("bestsellers: ", bestsellers);
  printItems("all: ", allItems);
  cout << endl;

  exit(EXIT_SUCCESS);
}
