#pragma once
#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;
class Receipt
{
private:
int receiptno;
string receiptdate;
double amount;
public:
string set_date();
Receipt ();
Receipt (int no, double a);
int get_receiptno();
string get_receiptdate();
double get_amount();
void set_receiptno(int no);
void set_amount(double a);
void display ();
};