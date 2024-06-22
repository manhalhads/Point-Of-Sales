#pragma once
#include "Sales.h"
class POS
{
private:
Sales sales;
public:
POS();
Customer get_customer();
Saleslineitem get_sli(int index);
Receipt get_receipt();
int get_salesid();
string get_status();
string get_date();
void set_customer (Customer c);
void set_sli(int index, Saleslineitem* s);
void set_receipt(int no, double amount);
void set_salesid(int id);
void set_date();
void set_status(string status);
POS(Sales s1, int size);
void display(int size);
void make_payment();
};