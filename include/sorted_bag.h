#ifndef _SORTED_BAG_H_
#define _SORTED_BAG_H_

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "safe_bag.h"

template <typename Item>
class SortedBag : public SafeBag<Item> {
  public:
  SortedBag() : SafeBag<Item>() {}
  SortedBag(int size) : SafeBag<Item>(size){}
  SortedBag(SortedBag<Item>& a) : SafeBag<Item>(a){}

  virtual void add(Item e) {
    if (Bag<Item>::sz == Bag<Item>::capacity) {
      Bag<Item>::expand();
    }
    if (Bag<Item>::sz > 0) {
      int current = 0;
      while (current < Bag<Item>::sz && e >= (*this)[current]) {
        current++;
      }
      Item in = e;
      Item out;
      while (current < Bag<Item>::sz) {
        out = (*this)[current];
        (*this)[current] = in;
        in = out;
        current++;
      }
      (*this)[Bag<Item>::sz++] = in;
    } else {
        (*this)[Bag<Item>::sz++] = e;
    }
  }

};

#endif