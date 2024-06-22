#pragma once
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "Customer.h"
#include "Receipt.h"
#include "Saleslineitem.h"
class Sales {
protected:
  int salesid;
  Customer c1;
  Saleslineitem *sli;
  Receipt r1;
  string date;
  string status;

public:
  int set_salesid();                 //sets saledid to a random unique no.
  void equate_salesid(int id);      //equates one salesid to other salesid
  string set_date();               //sets date based on current time
  Sales();                         //default constructor
  Sales(Customer c, Saleslineitem *s, int size); //parametrized constructor
  ~Sales();                              //destructor
  void display(int index);         //displays sales id, date and status of sale
  void display_total(int index);   //displays price, quantity and subtotal of sale
  void display_bill(int size, double total); // displays bill for end sale functionality
  Customer get_customer();    //returns customer attribute of sales
  Saleslineitem get_sli(int index); //returns saleslineitem attribute of sales at index index
  Receipt get_receipt();   //returns receipt attribute of sales class
  int get_salesid();        //returns salesid
  string get_status();   //returns status
  string get_date();     //returns date of sale
  void set_customer (Customer c1);  //sets customer attribute of sales
  void set_sli(int index, Saleslineitem* s);  //sets salelineitem attribute of sales at index no
  void set_receipt (int no, double amount); //sets receipt attribute
  void set_status(string status);   //sets status of sale

};