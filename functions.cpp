
#include "functions.h"
int count_lines() {        //counts number of lines in customers file
  int count = 0;
  string a;
  fstream fin;
  fin.open("Customers.txt");
  while (!(fin.eof())) {
    getline(fin, a);
    count++;
  }

  return count;
}
string *splitstring(string str) {           //This function takes a string that contains four commas.
                                           //It then returns an array of size 4 which contains the words in
                                           //the original string without commas or spaces.

  string *arr = new string[5];
  string email_phone;

  int size = str.size();
  int a = str.find(',');
  arr[0] = str.substr(1, a - 1);
  int b = str.rfind(',');
  arr[3] = str.substr(b + 2, size);
  int emailphone = size - arr[0].size() - arr[3].size() - 4;

  email_phone = str.substr(a + 2, emailphone);

  a = email_phone.find(',');
  arr[1] = email_phone.substr(0, a);
  int typesize = emailphone - arr[1].size();
  arr[2] = email_phone.substr(a + 2, typesize - 3);

  return arr;
}
string *search_cnic(string cnic) {         //This function takes a cnic and searches the customer file for that cnic.
                                          //If found,it returns an array containing the information of the customer with that cnic.


  string *arr = new string[5];
  string *temp = new string[4];
  string a;
  string b;
  string c = ",";
  fstream fin;
  fin.open("Customers.txt");
  while (!fin.eof()) {
    getline(fin, a, ',');
    getline(fin, b);

    if (a == cnic) {
      arr[0] = a;
      temp = splitstring(b);

      for (int i = 1; i < 5; i++)
        arr[i] = temp[i - 1];

      delete[] temp;
      fin.close();

      return arr;
    }
  }
  delete[] temp;
  for (int i = 0; i < 5; i++)
    arr[i] = "x";

  return arr;
}
string *search_name(string name) {       //This function takes a name and searches the customer file for that name.
                                          //If found,it returns an array containing the information of the customer with that name.
  string *arr = new string[5];
  string *temp = new string[4];
  string a;
  string b;
  string c = ",";
  fstream fin;
  fin.open("Customers.txt");
  while (!fin.eof()) {
    getline(fin, a, ',');
    getline(fin, b);
    temp = splitstring(b);
    if (temp[0] == name) {
      arr[0] = a;

      temp = splitstring(b);
      for (int i = 1; i < 5; i++)
        arr[i] = temp[i - 1];

      delete[] temp;
      fin.close();
      return arr;
    }
  }
  delete[] temp;
  for (int i = 0; i < 5; i++)
    arr[i] = "x";

  return arr;
}
string *search_email(string email) {     //This function takes an email and searches the customer file for that email.
                                          //If found,it returns an array containing the information of the customer with that email.
  string *arr = new string[5];
  string *temp = new string[4];
  string a;
  string b;
  string c = ",";
  fstream fin;
  fin.open("Customers.txt");
  while (!fin.eof()) {
    getline(fin, a, ',');
    getline(fin, b);
    temp = splitstring(b);
    if (temp[1] == email) {
      arr[0] = a;
      temp = splitstring(b);
      for (int i = 1; i < 5; i++)
        arr[i] = temp[i - 1];

      delete[] temp;
      fin.close();
      return arr;
    }
  }
  delete[] temp;
  for (int i = 0; i < 5; i++)
    arr[i] = "x";

  return arr;
}
string *search_phone(string phone) {     //This function takes a phone no and searches the customer file for that phone no.
                                          //If found,it returns an array containing the information of the customer with that phone no.
  string *arr = new string[5];
  string *temp = new string[4];
  string a;
  string b;
  string c = ",";
  fstream fin;
  fin.open("Customers.txt");
  while (!fin.eof()) {
    getline(fin, a, ',');
    getline(fin, b);
    temp = splitstring(b);
    if (temp[2] == phone) {
      arr[0] = a;
      temp = splitstring(b);
      for (int i = 1; i < 5; i++)
        arr[i] = temp[i - 1];

      delete[] temp;
      fin.close();
      return arr;
    }
  }
  delete[] temp;
  for (int i = 0; i < 5; i++)
    arr[i] = "x";

  return arr;
}
string *search_type(string type) {      //This function takes a type and searches the customer file for that type.
                                          //If found,it returns an array containing the information of the customer with that type
  string *arr = new string[5];
  string *temp = new string[4];
  string a;
  string b;
  string c = ",";
  fstream fin;
  fin.open("Customers.txt");
  while (!fin.eof()) {
    getline(fin, a, ',');
    getline(fin, b);
    temp = splitstring(b);
    if (temp[3] == type) {
      arr[0] = a;
      temp = splitstring(b);
      for (int i = 1; i < 5; i++)
        arr[i] = temp[i - 1];

      delete[] temp;
      fin.close();
      return arr;
    }
  }
  delete[] temp;
  for (int i = 0; i < 5; i++)
    arr[i] = "x";

  return arr;
}
int no_of_occur_of_type(string type) {   //returns no. of customers with type passed
  string a, b;
  int count = 0;
  fstream fin;
  fin.open("Customers.txt");
  string *temp;
  for (int i = 0; i < count_lines() - 1; i++) {
    getline(fin, a, ',');
    getline(fin, b);

    temp = splitstring(b);

    if (temp[3] == type) {
      count++;
    }
  }
  delete[] temp;
  return count;
}
string get_sales_limit(string type) {   //gets saleslimit for a customer type
  string saleslimit;
  if (type == "Silver")
    saleslimit = "40,000";
  else if (type == "Gold")
    saleslimit = "100,000";
  else if (type == "Platinum")
    saleslimit = "100,000";
  else
    saleslimit = "x";
  return saleslimit;
}
int count_entries() {           //Counts the number of lines in items file
  int count = 0;
  string a;
  fstream fin;
  fin.open("Items.txt");
  while (!fin.eof()) {
    getline(fin, a);
    count++;
  }
  fin.close();
  return count;
}
string *splitstringitem(string str) {     //This function takes a string with three phrases separated by commas. It returns an array of those three phrases separated without commas or spaces

  string *arr = new string[3];
  string price;
  int size = str.size();
  int a = str.find(',');
  arr[0] = str.substr(1, a - 1);
  int b = str.rfind(',');
  arr[2] = str.substr(b + 2, size);
  int price_size = size - arr[0].size() - arr[2].size() - 5;
  arr[1] = str.substr(a + 2, price_size);

  return arr;
  return arr;
}
string *search_sku(string sku) {        //This function takes an itemsku and searches the items file for that type.
                                          //If found,it returns an array containing the information of the item with that sku


  string *arr = new string[4];
  string *temp = new string[3];
  string a;
  string b;
  string c = ",";
  fstream fin;
  fin.open("Items.txt");
  while (!fin.eof()) {
    getline(fin, a, ',');
    getline(fin, b);

    if (a == sku) {
      arr[0] = a;
      temp = splitstringitem(b);
      

      for (int i = 1; i < 4; i++)
        arr[i] = temp[i - 1];

      delete[] temp;
      fin.close();

      return arr;
    }
  }
  delete[] temp;
  
  for (int i = 0; i < 4; i++)
    arr[i] = "x";
  return arr;
}
string *search_description(string description) {    //This function takes an item's description and searches the items file for that description.
                                          //If found,it returns an array containing the information of the item with that description

  string *arr = new string[4];
  string *temp;
  string a;
  string b;
  string c = ",";
  fstream fin;
  fin.open("Items.txt");
  while (!fin.eof()) {
    getline(fin, a, ',');
    getline(fin, b);
    temp = splitstringitem(b);
    if (temp[0] == description) {
      arr[0] = a;
       
      temp = splitstringitem(b);
      for (int i = 1; i < 4; i++)
        arr[i] = temp[i - 1];

      delete[] temp;
      fin.close();
      return arr;
    }
  }
  delete[] temp;
  for (int i = 0; i < 4; i++)
    arr[i] = "x";

  return arr;
}
string *search_price(string price) {     //This function takes an item's price and searches the items file for that price.
                                          //If found,it returns an array containing the information of the item with that price
  string *arr = new string[4];
  string *temp;
  string a;
  string b;
  string c = ",";
  fstream fin;
  fin.open("Items.txt");
  while (!fin.eof()) {
    getline(fin, a, ',');
    getline(fin, b);
    temp = splitstringitem(b);
    if (temp[1] == price) {
      arr[0] = a;
     // temp = splitstringitem(b);
      for (int i = 1; i < 4; i++)
        arr[i] = temp[i - 1];

      delete[] temp;
      fin.close();
      return arr;
    }
  }
  delete[] temp;
  for (int i = 0; i < 4; i++)
    arr[i] = "x";

  return arr;
}
string *search_quantity(string quantity) {   //This function takes an item's quantity and searches the items file for that quantity.
                                          //If found,it returns an array containing the information of the item with that quantity
  string *arr = new string[4];
  string *temp = new string[3];
  string a;
  string b;
  string c = ",";
  fstream fin;
  fin.open("Items.txt");
  while (!fin.eof()) {
    getline(fin, a, ',');
    getline(fin, b);
    temp = splitstringitem(b);
    if (temp[2] == quantity) {
      arr[0] = a;
      temp = splitstringitem(b);
      for (int i = 1; i < 4; i++)
        arr[i] = temp[i - 1];

      delete[] temp;
      fin.close();
      return arr;
    }
  }
  delete[] temp;
  for (int i = 0; i < 4; i++)
    arr[i] = "x";

  return arr;
}
void display_des_price (string sku)   //displays description and price of item with passed item sku
{
  string *temp = search_sku(sku);
  cout << "Description: "<< temp[1] << endl;
  cout << "Price: "<< temp[2] << endl;

  delete [] temp;
}
