#pragma once
#include <iostream>
#include "functions.h"
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
class Item {
private:
  string itemsku;
  string description;
  string price;
  string availablequantity;
  string creationdate;

public:
 Item (); //constructor
 Item (string itemsku, string description,string price, string availablequantity); //overloaded constructor
 Item (const  Item &i1); //copy constructor
  void set_sku(string sku);
  void set_description(string des);
  void set_price(string p);            //setters 
  void set_availablequantity(string aq);
  void set_creationdate(string date);
  string get_sku();
  string get_description();
  string get_price();           //getters
  string get_availablequantity();
  string get_creation_date();
  
  void add_new_item ();   //adds item info to file
  void display ();        //displays all attributes of item class
  void delete_item();   //deletes item from file
  void update_item();   //updates item info in file
  void search_item();    //finds item from file
  void display1();       //displays item info
  void display2();        //displays item info 
  void display3();        //displays item info for find item
  void update_qty(double qty);    //updates qty of item in file after sale
  void add_back_qty(double qty);   //updates qty of item in file after sale
  double get_price1();       //gets price of item
};