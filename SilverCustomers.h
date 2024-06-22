#pragma once
#include "Customer.h"
class SilverCustomers : public Customer {
public:
  SilverCustomers();
  SilverCustomers(string CNIC, string name, string email, string phone,
                  string type);
  void display();

  string get_name();
  string get_phone();
  string get_email();
  string get_type();
  double get_amountpayable();
  double get_saleslimit();
  void add_new_customer();
  void delete_customer();
  void display1();
  void search_customer();
  void display2();
  void update_customer();
  bool check_saleslimit(double total);
};