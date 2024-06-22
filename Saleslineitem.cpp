#include "Saleslineitem.h"
Saleslineitem ::Saleslineitem() {
  lineno = 1;
  quantity = 0;
};
Saleslineitem::Saleslineitem(int l, Item i2, int q)
    : i1(i2), quantity(q), lineno(l) {}
void Saleslineitem :: display() {
  cout << "receipt no: " << lineno << endl;
  cout << "quantity: " << quantity << endl;
  i1.display();
}
void Saleslineitem :: set_item(Item i2) { i1 = i2; }
void Saleslineitem :: set_lineno(int l) { lineno = l; }
void Saleslineitem :: set_quantity(int q) { quantity = q; }
Saleslineitem :: Saleslineitem(const Saleslineitem &s1) {
  lineno = s1.lineno;
  quantity = s1.quantity;
  set_item(s1.i1);
}
int Saleslineitem :: get_quantity() { return quantity; }
double Saleslineitem :: get_price() {
  string price = i1.get_price();
  double p = stod(price);
  return p;
}
Item Saleslineitem :: get_item(){return i1;}
int Saleslineitem :: get_lineno(){return lineno;}
void Saleslineitem:: display_bill() {
  
  double amount = quantity * i1.get_price1();
  
  cout << left << setw(9) << i1.get_sku();
  cout << left << setw(40) << i1.get_description();
  cout << left << setw(10) << quantity;
  cout << left << setw(7) << amount;
  cout << endl;
}