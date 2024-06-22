#pragma once
#include "Item.h"
#include <iostream>
using namespace std;
class Saleslineitem {
private:
  int lineno;
  Item i1;
  int quantity;

public:
  Saleslineitem();
  Saleslineitem(int l, Item i2, int q);
  void set_item(Item i2);
  void set_lineno(int l);
  void set_quantity(int q);
  Saleslineitem(const Saleslineitem &s1);
  void display();
  int get_quantity();
  int get_lineno();
  double get_price();
  Item get_item();
  void display_bill();
};