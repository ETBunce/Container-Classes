#ifndef _SAFE_BAG_H_
#define _SAFE_BAG_H_

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "bag.h"

template <typename Item>
class SafeBag : public Bag<Item> {
  public:
  SafeBag() : Bag<Item>() {}
  SafeBag(int size) : Bag<Item>(size){}
  SafeBag(SafeBag<Item>& a) : Bag<Item>(a){}

  virtual SafeBag<Item>& remove() {
    if (Bag<Item>::sz == 0) {
      throw std::runtime_error("No elements to remove");
    }
    Bag<Item>::sz--;
    return *this;
  }

  Item operator[] (int ndx) const {
    if (ndx < 0 || ndx >= Bag<Item>::sz)
      throw std::runtime_error("Out of bounds");
    return Bag<Item>::elements[ndx];
  }
  Item& operator[] (int ndx) {
    if (ndx < 0 || ndx >= Bag<Item>::sz)
      throw std::runtime_error("Out of bounds");
    return Bag<Item>::elements[ndx];
  }

};

#endif