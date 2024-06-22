#include "GoldCustomers.h"
  GoldCustomers :: GoldCustomers() : Customer() { discount = 3; }
  GoldCustomers :: GoldCustomers(string CNIC, string name, string email, string phone, string type)
      : Customer(CNIC, name, email, phone, type) {
    type = "Gold";
    amountpayable = 0;
    saleslimit = 100000;
    discount = 3;
  }
  void GoldCustomers :: display() {
    Customer ::display();
    cout << "Discount: " << discount << endl;
  }
  string GoldCustomers :: get_CNIC() { return this->CNIC; }
  string GoldCustomers :: get_name() { return name; }
  string GoldCustomers :: get_phone() { return phone; }
  string GoldCustomers :: get_email() { return email; }
  string GoldCustomers :: get_type() { return type; }
  double GoldCustomers :: get_amountpayable() { return amountpayable; }
  double GoldCustomers :: get_saleslimit() { return saleslimit; }
  void GoldCustomers ::add_new_customer() { Customer::add_new_customer(); }
  void GoldCustomers :: delete_customer() { Customer :: delete_customer();}
  void GoldCustomers :: display1() { Customer :: display1(); }
  void GoldCustomers :: search_customer(){Customer :: search_customer();}
  void GoldCustomers:: display2(){Customer :: display();}
  void GoldCustomers :: update_customer() {Customer :: update_customer();}
  bool GoldCustomers :: check_saleslimit(double total){Customer :: check_saleslimit(total);}