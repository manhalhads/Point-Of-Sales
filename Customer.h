#pragma once
#include <iostream>
#include <ctime>
#include <sstream>
#include "functions.h"
using namespace std;
class Customer {
protected:
  string CNIC;
  string name;
  string email;
  string phone;
  string type;
  double amountpayable;
  double saleslimit;

public:
  
  Customer(); //constructor
  Customer(string CNIC, string name, string email, string phone, string type); //overloaded constructor
  string get_CNIC();
  string get_name();
  string get_email();          //getters of Customer's attributes
  string get_phone();
  string get_type();
  double get_saleslimit ();
  double get_amountpayable();
 
  void set_CNIC(string cnic);
  void set_name(string n);
  void set_email(string e);
  void set_phone(string p);           //setters of Customer's attributes
  void set_type(string t);
  void set_saleslimit (string type);
  void set_amountpayable(double a);
  
  void display();   //displays all attributes
  void add_new_customer();   // adds customer info to file
  void delete_customer();   //deletes customer info from file
  void display1();           //displays customer info for modify function
  void search_customer();   //finds customer info from file
  void display2();      //displays customer info for find function
  void update_customer();   //updates customer info in file
  bool check_saleslimit(double total);  //returns true if total has not exceeded customer's saleslimit and false otherwise

};