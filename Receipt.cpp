#include "Receipt.h"
string Receipt :: set_date()
{
 time_t now = time(NULL);
    tm* local_time = localtime(&now);
    ostringstream oss;
   // Format the date as a string
    oss << local_time->tm_mday << "-" << (local_time->tm_mon + 1) << "-" << (local_time->tm_year + 1900);

    // Get the string from the output string stream
    string date = oss.str();
 
   return date;
}
Receipt ::Receipt(){
  receiptno = 1;
  receiptdate = set_date();
  amount = 0;
};
Receipt ::Receipt(int no, double a) {
  receiptno = no;
  receiptdate = set_date();
  amount = a;
}
int Receipt :: get_receiptno(){return receiptno;}
string Receipt :: get_receiptdate(){return receiptdate;}
double Receipt :: get_amount(){return amount;}
void Receipt :: set_receiptno(int no){receiptno = no;}
void Receipt :: set_amount(double a){amount = a;}
void Receipt ::display() {
  cout << "receipt no: " << receiptno << endl;
  cout << "receipt date: " << receiptdate << endl;
  cout << "amount: " << amount << endl;
}