#include "PlatinumCustomers.h"
  PlatinumCustomers :: PlatinumCustomers() : Customer() { discount = 5; }
  PlatinumCustomers :: PlatinumCustomers(string CNIC, string name, string email, string phone, string type)
      : Customer(CNIC, name, email, phone, type) {
    type = "Platinum";
    amountpayable = 0;
    saleslimit = 250,000;
    discount = 5;
  }
  void PlatinumCustomers :: display() {
    Customer ::display();
    cout << "Discount: " << discount << endl;
  }
  string PlatinumCustomers :: get_CNIC() { return this->CNIC; }
  string PlatinumCustomers :: get_name() { return name; }
  string PlatinumCustomers :: get_phone() { return phone; }
  string PlatinumCustomers :: get_email() { return email; }
  string PlatinumCustomers :: get_type() { return type; }
  double PlatinumCustomers :: get_amountpayable() { return amountpayable; }
  double PlatinumCustomers :: get_saleslimit() { return saleslimit; }
  void PlatinumCustomers ::add_new_customer() { Customer::add_new_customer(); }
  void PlatinumCustomers :: delete_customer() { Customer :: delete_customer();}
  void PlatinumCustomers :: display1() { Customer :: display1(); }
  void PlatinumCustomers :: search_customer(){Customer :: search_customer();}
  void PlatinumCustomers:: display2(){Customer :: display();}
  void PlatinumCustomers :: update_customer() {Customer :: update_customer();}
  bool PlatinumCustomers :: check_saleslimit(double total){Customer :: check_saleslimit(total);}