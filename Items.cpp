#include "Items.h"
Item :: Item() {
    itemsku = "0";
    description = "nothing";
    price = "0";
    availablequantity = "0";
    creationdate = "20-4-2023";
  }
  Item :: Item (string itemsku, string description = "0", string price = "0",
       string availablequantity = "0") {
    this->itemsku = itemsku;
    this->description = description;
    this->price = price;
    this->availablequantity = availablequantity;
    creationdate = "20-4-2023";
  }
Item :: Item(const  Item &i1)
{
  itemsku = i1.itemsku;
  description = i1.description;
  price = i1.price;
  availablequantity = i1. availablequantity;

}
void Item ::  set_sku(string sku){itemsku = sku;}
void Item :: set_description(string des){description = des;}
void Item :: set_price(string p){price = p;}
void Item :: set_availablequantity(string aq){availablequantity = aq;}
void Item :: set_creationdate(string date) {creationdate = date;}
string Item :: get_sku(){return itemsku;}
string Item :: get_description(){return description;}
string Item :: get_price(){return price;}
string Item :: get_availablequantity(){return availablequantity;}
string Item :: get_creation_date() {return creationdate;}
void Item ::  display() {
    cout << "Item Number: " << itemsku << endl;
    cout << "Item Description: " << description << endl;
    cout << "Price: " << price << endl;
    cout << "Available Quantity: " << availablequantity << endl;
    cout << "Creation date: " << creationdate << endl;
  }
 void Item :: display3(){

   int des = description.size() + 6;

  int len = des + 34;
  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
  cout << left << setw(10) << "Item_SKU" << left << setw(des+6) << "Description";
  cout << left << setw(8)<< "Price" << left << setw(10) << "Quantity";
  cout << endl;

  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
  cout << left << setw(10) << itemsku << left << setw(des+6) << description;
  cout << left << setw(8) << price << left << setw(10) << availablequantity;
  cout << endl;

  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
 }
void Item :: add_new_item() {
    fstream fout;
    fout.open("Items.txt", ios::app);
    if (fout.is_open()) {
      fout << itemsku << ", " << description << ", " << price;
      fout << ", " << availablequantity << endl;
      cout << "Item information successfully saved." << endl;
      fout.close();
    }
  }
void Item ::search_item() {
if (itemsku.empty())
  itemsku = "N/A";
if (description.empty())
    description = "N/A";
if (price.empty())
    price = "N/A";
if (availablequantity.empty())
   availablequantity = "N/A";
  
  string *sku = search_sku(this->itemsku);
  string *description = search_description(this->description);
  string *price = search_price(this->price);
  string *quantity = search_quantity(this->availablequantity);


  if (sku[0] != "x")
  {
    Item i1(sku[0], sku[1], sku[2], sku[3]);
    i1.display3();
  }
  else if (description[0] != "x")
  {
     Item i1(description[0], description[1], description[2], description[3]);
     i1.display3();
  }
  else if (price[0] != "x")
  {
    int no_items_same_price = no_of_same_price (price[2]);
     if (no_items_same_price > 1)
     {
       cout << "hallo"<< endl;
     //  cout << "There are " << no_items_same_price << " items with the same price." << endl;
      string ** all_items = all_entries_with_price(price[2]);


      Item j[no_items_same_price];
      for (int i = 0; i < no_items_same_price; i++)
        {
          j[i].set_sku(all_items[i][0]);
          j[i].set_description(all_items[i][1]);
          j[i].set_price(all_items[i][2]);
          j[i].set_availablequantity(all_items[i][3]);
        }
        for (int i = 0; i < no_items_same_price; i++)
          j[i].display3();
     }
    else
    {
      Item i1(price[0], price[1], price[2], price[3]);
      i1.display3();
    }
  }
  else
  {
    cout << "No item found with enterred details. " << endl << endl;
  }
  cout << endl;
  delete[] sku;
  delete[] description;
  delete[] price;
  delete[] quantity;

}
void Item :: delete_item() {
  string a;
  string b;
  string c = ",";
  int lines = count_entries() - 2;
  string arr[lines];

  fstream fin;
  fin.open("Items.txt");

  for (int i = 0; i < lines; i++) {
    getline(fin, a, ',');
    getline(fin, b);

    arr[i] = a + c + b;
    if (a == itemsku) {

      getline(fin, a, ',');
      getline(fin, b);

      arr[i] = a + c + b;
    }
  }

  fin.close();
  fstream fout;

  fout.open("Items.txt", ios ::out);

  for (int i = 0; i < lines; i++)
    fout << arr[i] << endl;

  cout << "Item removed successfully." << endl;
  fout.close();
}
void Item :: display1() {

  int size_des = description.size() + 2;
  int len = size_des + 42;
  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
  cout << left << setw(10) << "Item_SKU" << left << setw(size_des + 5)
       << "Description";
  cout << left << setw(10) << "Price";
  cout << left << setw(17) << "Available Quantity" << endl;

  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
  cout << left << setw(10) << itemsku << left << setw(size_des + 5) << description;
  cout << left << setw(10) << price;
  cout << left << setw(17) << availablequantity << endl;
  for (int i = 0; i < len; i++)
    cout << "-";
  cout << endl;
}
void Item :: update_item() {
  string a, b;
  string c = ", ";
  int lines = count_entries() - 1;
  string arr[lines];

  fstream fin;
  fin.open("Items.txt");

  for (int i = 0; i < lines; i++) {
    getline(fin, a, ',');
    getline(fin, b);

    arr[i] = a + ',' + b;
    if (a == itemsku) {
      arr[i] = itemsku + c + description + c + price + c + availablequantity;

    }
  }
  fin.close();

  fstream fout;
  fout.open("Items.txt", ios ::out);

  for (int i = 0; i < lines; i++) {
    fout << arr[i] << endl;

  }
  cout << "Item information successfully saved. " << endl;
}
void Item :: display2()
{
  string *temp = search_sku(itemsku);
  cout << "Item_SKU: "<< temp[0] << endl;
  cout << "Description: "<< temp[1] << endl;
  delete [] temp;
}
void Item :: update_qty(double qty) {
  string a, b;
  string c = ", ";
  int lines = count_entries() - 1;
  string arr[lines];
  string *temp;
  fstream fin;
  fin.open("Items.txt");

  for (int i = 0; i < lines; i++) {
    getline(fin, a, ',');
    getline(fin, b);
    temp = splitstringitem(b);
    arr[i] = a + ',' + b;
    if (a == itemsku) {
      int oldqty = stoi(temp[2]);
      int newqty = oldqty - qty;
      string quantity = to_string(newqty);

      arr[i] = itemsku + c + description + c + price + c + quantity;

    }
  }
  fin.close();

  fstream fout;
  fout.open("Items.txt", ios ::out);

  for (int i = 0; i < lines; i++) {
    fout << arr[i] << endl;

  }
  delete [] temp;

}
void Item :: add_back_qty(double qty){
  string a, b;
  string c = ", ";
  int lines = count_entries() - 1;
  string arr[lines];
  string *temp;
  fstream fin;
  fin.open("Items.txt");

  for (int i = 0; i < lines; i++) {
    getline(fin, a, ',');
    getline(fin, b);
    temp = splitstringitem(b);
    arr[i] = a + ',' + b;
    if (a == itemsku) {
      int oldqty = stoi(temp[2]);
      int newqty = oldqty + qty;
      string quantity = to_string(newqty);

      arr[i] = itemsku + c + description + c + price + c + quantity;

    }
  }
  fin.close();

  fstream fout;
  fout.open("Items.txt", ios ::out);

  for (int i = 0; i < lines; i++) {
    fout << arr[i] << endl;

  }
  delete [] temp;
  fout.close ();

}
double Item :: get_price1() { return stod(price);}
