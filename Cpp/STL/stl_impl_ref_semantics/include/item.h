#ifndef _ITEM_H
#define _ITEM_H

#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <algorithm>
#include <memory>

using namespace std;

class Item {

private:
  string name;
  float price;

public:

  // constructor
  Item (const string&, float = 0);

  // Getter
  string getName() const;
  float getPrice() const;
  // Setter
  void setName(const string&);
  void setPrice(float);

};

template <typename Coll>
void printItems(const string& msg, const Coll& coll)
{
  // print collection
  cout << msg << endl;
  for(const auto& elem : coll){
    cout << ' '<< elem->getName() << ": "
         << elem->getPrice() << endl;
  }
};

#endif
