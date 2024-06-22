#include "Customer.h"
void Customer ::set_saleslimit (string type){
  if (type == "Silver")
   saleslimit = 40000;
  else if (type == "Gold")
   saleslimit = 100000;
  else if (type == "Platinum")
   saleslimit = 250000;
  }
Customer ::Customer() {
  CNIC = "0";
  name = "no name";
  phone = "0";
  email = "noemail@gmail.com";
  type = "no type";
  amountpayable = 0;
  saleslimit = 40000;
  
}
Customer ::Customer(string CNIC, string name, string email, string phone,
                    string type) {
  this->CNIC = CNIC;
  this->name = name;
  this->phone = phone;
  this->email = email;
  this->type = type;  
  this->amountpayable = 0;
  set_saleslimit(type);
  
}
string Customer ::get_CNIC() { return CNIC; }
string Customer ::get_name() { return name; }
string Customer ::get_email() { return email; }
string Customer ::get_phone() { return phone; }
string Customer ::get_type() { return type; }
double Customer ::get_amountpayable() { return amountpayable; }
double Customer ::get_saleslimit() { return saleslimit; }
void Customer :: set_CNIC(string cnic){CNIC = cnic;}
void Customer :: set_name(string n){name = n;}
void Customer :: set_email(string e){email = e;}
void Customer :: set_phone(string p){phone = p;}
void Customer :: set_type(string t){type = t;}
void Customer :: set_amountpayable (double a){amountpayable = a;}
void Customer :: display() {
  cout << "CNIC: " << CNIC << endl;
  cout << "Name: " << name << endl;
  cout << "Phone: " << phone << endl;
  cout << "Email: " << email << endl;
  cout << "Type: " << type << endl;
  cout << "Amount payable: " << amountpayable << endl;
  cout << "Sales limit: " << saleslimit << endl;
}
void Customer ::add_new_customer() {
  fstream fout;
  fout.open("Customers.txt", ios::app);

  if (fout.is_open()) {
    fout << CNIC << ", ";
    fout << name << ", " << email << ", " << phone << ", " << type << endl;
  }
  fout.close();
  cout << "Customer information successfully saved." << endl;
}
void Customer ::display1() {
  int size_email = email.size() + 2;
  int size_name = name.size() + 2;
  int len = size_email + size_name + 67;
  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
  cout << left << setw(17) << "CNIC" << left << setw(size_name) << "Name";
  cout << left << setw(size_email) << "Email" << left << setw(15) << "Phone";
  cout << left << setw(9) << "Type" << left << setw(16) << "Amount Payable";
  cout << setw(11) << "SalesLimit" << endl;

  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
  cout << left << setw(17) << CNIC << left << setw(size_name) << name;
  cout << left << setw(size_email) << email << left << setw(15) << phone;
  cout << left << setw(9) << type << left << setw(16) << amountpayable;
  cout << setw(11) << saleslimit << endl;
  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
}
void Customer ::delete_customer() {
  string a;
  string b;
  string c = ",";
  int lines = count_lines() - 2;
  string arr[lines];

  fstream fin;
  fin.open("Customers.txt");

  for (int i = 0; i < lines; i++) {
    getline(fin, a, ',');
    getline(fin, b);

    arr[i] = a + c + b;
    if (a == CNIC) {

      getline(fin, a, ',');
      getline(fin, b);
      arr[i] = a + c + b;
    }
  }

  fin.close();
  fstream fout;

  fout.open("Customers.txt", ios ::out);

  for (int i = 0; i < lines; i++)
    fout << arr[i] << endl;

  cout << "Customer removed successfully" << endl;
  fout.close();
}
void Customer ::update_customer() {
  string a, b;
  string c = ", ";
  int lines = count_lines() - 1;
  string arr[lines];

  fstream fin;
  fin.open("Customers.txt");

  for (int i = 0; i < lines; i++) {
    getline(fin, a, ',');
    getline(fin, b);

    arr[i] = a + ',' + b;
    if (a == CNIC) {
      arr[i] = CNIC + c + name + c + email + c + phone + c + type;
    }
  }
  fin.close();

  fstream fout;
  fout.open("Customers.txt", ios ::out);

  for (int i = 0; i < lines; i++) {
    fout << arr[i] << endl;
  }
  cout << "Customer information successfully saved. " << endl;
}
void Customer ::display2() {
  saleslimit = saleslimit;
  int size_email = email.size() + 2;
  int size_name = name.size() + 2;
  int len = size_email + size_name + 43;
  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
  cout << left << setw(17) << "CNIC" << left << setw(size_name) << "Name";
  cout << left << setw(size_email) << "Email" << left << setw(15) << "Phone";
  cout << setw(11) << "SalesLimit" << endl;

  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
  cout << left << setw(17) << CNIC << left << setw(size_name) << name;
  cout << left << setw(size_email) << email << left << setw(15) << phone;
  cout << setw(11) << saleslimit << endl;
  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
}
void Customer ::search_customer() {

  string *cnic = search_cnic(this->CNIC);
  string *name = search_name(this->name);
  string *email = search_email(this->email);
  string *phone = search_phone(this->phone);
  string *type = search_type(this->type);

  

  if (cnic[0] == "x") {
    if (name[0] == "x") {
      if (email[0] == "x") {
        if (phone[0] == "x") {
          if (type[0] == "x") {
            cout << "Customer not found." << endl;
          } else {
          
          }
        } else {
          Customer c1(phone[0], phone[1], phone[2], phone[3], phone[4]);
          c1.display2();
         
        }
      } else {
        Customer c1(email[0], email[1], email[2], email[3], email[4]);
        c1.display2();
       
      }
    } else {
      Customer c1(name[0], name[1], name[2], name[3], name[4]);
      c1.display2();
    
    }
  } else {
    Customer c1(cnic[0], cnic[1], cnic[2], cnic[3], cnic[4]);
    c1.display2();
    
  }

  

  delete[] cnic;
  delete[] name;
  delete[] email;
  delete[] phone;
  delete[] type;
}
bool Customer :: check_saleslimit(double total)
{
  if (type == "Silver" && total<=40000)
    return true;
 else if (type == "Gold" && total<=100000)
    return true;
 else if (type == "Gold" && total<=250000)
    return true;
  else
   return false;
    
}