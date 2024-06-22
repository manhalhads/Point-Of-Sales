#include "Sales.h"

int Sales :: set_salesid()
{
  // Providing a seed value
	srand((int) time(NULL));

	// Get a random number
	int random = rand();

	return random;
}
string Sales :: set_date()
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
Sales ::Sales() {
  salesid = set_salesid();
  date = set_date();
  status = "Unpaid";
  sli = new Saleslineitem[1000];
}
void Sales ::display(int index) {
  cout << "Sales ID: " << salesid << endl;
  cout << "Sales Date: " << date << endl;
  cout << "Status: "<< status << endl;
  c1.display();
  for (int i = 0; i < index; i++)
    sli[i].display();

  r1.display();
}
Sales ::Sales(Customer c, Saleslineitem *s, int size = 10) : c1(c), sli(s) {

  salesid = set_salesid();
  date = set_date();
  status = "Unpaid";
  sli = new Saleslineitem[size];
  for (int i = 0; i < size; i++)
    sli[i] = s[i];
}
Customer Sales ::get_customer() { return c1; }
Saleslineitem Sales ::get_sli(int index) { return sli[index]; }
Receipt Sales ::get_receipt(){return r1;}
int Sales :: get_salesid(){return salesid;}
string Sales :: get_status(){return status;}
string Sales :: get_date(){return date;}
void Sales :: equate_salesid(int id){salesid = id;}
void Sales :: set_customer (Customer c2)
{
  c1.set_CNIC(c2.get_CNIC());
  c1.set_name(c2.get_name());
  c1.set_email(c2.get_email());
  c1.set_phone(c2.get_phone());
  c1.set_type(c2.get_type());
  c1.set_amountpayable(c2.get_amountpayable());
  c1.set_saleslimit(c2.get_type());
}
void Sales :: set_sli(int index, Saleslineitem* s)
{
 for (int i=0;i<index;i++)
   {
   Item item = s[i].get_item();
     sli[i].set_item(item);
   }
  for (int i=0;i<index;i++)
   {
   int qty = s[i].get_quantity();
     sli[i].set_quantity(qty);
   }
  for (int i=0;i<index;i++)
   {
   int lineno = s[i].get_lineno();
     sli[i].set_lineno(lineno);
   }
}
void Sales :: set_receipt (int no, double amount)
 {
  r1.set_receiptno(no);
  r1.set_amount(amount);
 }
void Sales :: set_status(string status){this->status = status;}
Sales ::~Sales() { delete[] sli; }
void Sales ::display_total(int index) {

  cout << "Price: " << sli[index].get_price() << endl;
  cout << "Quantity: " << sli[index].get_quantity() << endl;
  double subtotal = sli[index].get_price() * sli[index].get_quantity();
  cout << "Sub-Total: " << subtotal << endl;
}
void Sales :: display_bill(int size, double total) {
  cout << left << "Sales ID: " << setw(23) << salesid;
  cout << left << setw(23) << "\t" << endl;
  cout << left << "Sales date: " << setw(23) << date;
   cout << left << "\t";
  cout << left << "CNIC: " << setw(23) << c1.get_CNIC() << endl;
  cout << left << "Type: " << c1.get_type() << setw(23) << " Customer"
       << "\t";
  cout << left << "Name: " << c1.get_name() << endl;
  for (int i = 0; i < 66; i++)
    cout << "-";
  cout << endl;

  cout << left << setw(9) << "Item_SKU";
  cout << left << setw(40) << "Description";
  cout << left << setw(10) << "Quantity";
  cout << left << setw(7) << "Amount" << endl;
  for (int i = 0; i < 66; i++)
    cout << "-";
  cout << endl;

  for (int i = 0; i < size; i++)
    sli[i].display_bill();

  for (int i = 0; i < 66; i++)
    cout << "-";
  cout << endl;
  cout << right << setw(58) << "Total sales: Rs. " << total << endl;

  cout << endl;
}


