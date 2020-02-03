#ifndef _BAG_H_
#define _BAG_H_

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

template<typename Item>
class Bag {
public:
  Bag(): capacity(INITIAL_CAPACITY), sz(0), 
    elements(std::make_unique<Item[]>(capacity)) {}

  Bag(int size): capacity(size), sz(size), 
    elements(std::make_unique<Item[]>(capacity)){}
  Bag(Bag<Item>& a): capacity(a.capacity), sz(a.sz),
    elements(std::make_unique<Item[]>(capacity)) {
    for (int i = 0; i < a.sz; i++) elements[i] = a.elements[i];
  }

  virtual int size() { return sz; }
  virtual Item get(int ndx) const { return elements[ndx]; }
  virtual void add(Item e) {
    if (sz == capacity) {
      expand();
    }

    (*this)[sz++] = e;
  }
  virtual Bag<Item>& remove() {
    sz--;
    return *this;
  }

  virtual Item* begin() { return elements.get(); }
  virtual Item* end() { return elements.get() + sz; }

  virtual Bag<Item>& operator=(Bag<Item>& a) {
    auto newElements = std::make_unique<Item[]>(a.capacity);
    for (int i = 0; i < a.sz; i++) newElements[i] = a.elements[i];
    elements = move(newElements);
    capacity = a.capacity;
    sz = a.sz;

    return *this;
  }
  virtual Item operator[](int ndx) const { return elements[ndx]; }
  virtual Item& operator[](int ndx) { return elements[ndx]; }
  virtual Bag<Item>& operator<<(Item e) {
    add(e);
    return *this;
  }
  virtual ~Bag(){}

protected:
  int capacity;
  int sz;
  std::unique_ptr<Item[]> elements;
  static const int INITIAL_CAPACITY = 8;

  void expand() {
    auto newElements = std::make_unique<Item[]>(capacity * 2);
    for (int i = 0; i < capacity; i++) newElements[i] = elements[i];
    elements = std::move(newElements);

    capacity *= 2;
  }
};

#endif