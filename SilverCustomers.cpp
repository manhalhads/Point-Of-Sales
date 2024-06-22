#include "SilverCustomers.h"
SilverCustomers :: SilverCustomers() : Customer() {}
  SilverCustomers :: SilverCustomers (string CNIC, string name, string email, string phone, string type) : Customer(CNIC, name, email, phone, type)
{
    type = "Silver";
    amountpayable = 0;
    saleslimit = 40000;
  }
  void SilverCustomers ::  display() { Customer ::display(); }
  string SilverCustomers :: get_name() { return name; }
  string SilverCustomers :: get_phone() { return phone; }
  string SilverCustomers :: get_email() { return email; }
  string SilverCustomers :: get_type() { return type; }
double SilverCustomers :: get_amountpayable() { return amountpayable; }
double SilverCustomers :: get_saleslimit() { return saleslimit; }
void SilverCustomers :: add_new_customer() { Customer ::add_new_customer(); }
void SilverCustomers :: delete_customer() { Customer ::delete_customer(); }
void SilverCustomers :: display1() { Customer ::display1(); }
  void SilverCustomers :: search_customer(){Customer :: search_customer();}
void SilverCustomers:: display2(){Customer :: display();}
void SilverCustomers :: update_customer() {Customer :: update_customer();}
bool SilverCustomers :: check_saleslimit(double total){Customer :: check_saleslimit(total);}