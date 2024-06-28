#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int count_lines();
string *splitstring(string str);
string *search_cnic(string cnic);
string *search_name(string name);
string *search_email(string email);
string *search_phone(string phone);
string *search_type(string type);
int no_of_occur_of_type(string type);
int no_of_same_price (string price);
int no_of_same_qty (string quantity);
string **all_entries_with_price(string price);
string **all_entries_with_qty(string quantity);
string **all_occur_of_type(string type);
string get_sales_limit(string type);
int count_entries();
string *splitstringitem(string str);
string *search_sku(string sku);
string *search_description(string description);
string *search_price(string price);
string *search_quantity(string quantity);
void display3(string **arr, int size);
void display_des_price(string sku);
