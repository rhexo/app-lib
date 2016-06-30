#include <iostream>
#include <string>

#include "include/item.h"

using namespace std;

Item::Item(const string& n, float p): name(n), price(p) {}

string Item::getName() const
{
  return name;
}

float Item::getPrice() const
{
  return price;
}

void Item::setName(const string & n)
{
  name = n;
}

void Item::setPrice(float p)
{
  price = p;
}
