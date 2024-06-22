#include "POS.h"
using namespace std;
int main_menu()
{
  int option;
  cout << "1. Manage Items"<< endl;
  cout << "2. Manage Customers."<< endl;
  cout << "3. Make New Sale."<< endl;
  cout << "4. Make Payment."<< endl;
  cout << "5. Exit."<< endl;
  cin >> option;
   while (option < 1 || option > 5) {
    cout << "Invalid option. Press 1 to 5 to select an option." << endl;
    cin >> option;
    cin.get();
    
  }
  return option;
}
void return_to_main_menu();
int return_main_menu();
void items_menu(int choice);
int items_menu();
void customers_menu(int choice);
int customer_menu();
void modify_customer() {
  string cnic;
  string name;
  string email;
  string phone;
  string type;
  string *temp;

  
  cout << "Enter CNIC: ";
  cin.get();
  getline(cin, cnic);
  temp = search_cnic(cnic);
  if (temp[0] == "x") {
    while (temp[0] == "x") {
      cout << "Customer not found." << endl;
      cout << "You have entered the CNIC of a customer that doesn't exist in "
              "the database. Please enter an existing customer's CNIC: ";
      getline(cin, cnic);
      temp = search_cnic(cnic);
    }
  }
cout << "To modify customer details, enter following fields. Leave blank to "
          "keep the detail same as before. "
       << endl;
  cout << "Name: ";
  getline(cin, name);
  cout << "Email: ";
  getline(cin, email);
  cout << "Phone: ";
  getline(cin, phone);
  cout << "Type: ";
  getline(cin, type);

  if (name.empty())
    name = temp[1];
  if (email.empty())
    email = temp[2];
  if (phone.empty())
    phone = temp[3];
  if (type.empty())
    type = temp[4];

  delete[] temp;

  int choice;
  cout << "Confirm modify details?" << endl;
  cout << "1.Confirm. " << endl;
  cout << "2.Cancel. " << endl;
  cin >> choice;

  if (choice == 1) {
    Customer c1(cnic, name, email, phone, type);
    c1.update_customer();
  } else if (choice == 2) {
    cout << "Cancelled" << endl;
  } else {
    cout << "Invalid option. " << endl;
  }

  
  int choice2;
  choice2 = customer_menu();
  customers_menu(choice2);
}
void add_customer() {
  string cnic, name, email, phone, type;
  cout << "To add new customer, enter: " << endl;
  cout << "CNIC: ";
  cin >> cnic;
  cout << "Name: ";
  cin.ignore();
  getline(cin, name);
  cout << "Email: ";
  cin >> email;
  cout << "Phone: ";
  cin >> phone;
  cout << "Type: ";
  cin >> type;

  Customer c1(cnic, name, email, phone, type);
  c1.add_new_customer();

  int choice;
  choice = customer_menu();
  customers_menu(choice);
}
void find_customer() {
  string data[5];
  
  cin.get();
  cout << "Please specify at least one of the following to find the customer. "
          "Leave all fields blank to return to Customers Menu"
       << endl;
  cout << "CNIC: ";
  
  getline(cin, data[0]);
  cout << "Name: ";
  getline(cin, data[1]);
  cout << "Email: ";
  getline(cin, data[2]);
  cout << "Phone: ";
  getline(cin, data[3]);
  cout << "Type: ";
  getline(cin, data[4]);
  cout << "data[0]: "<< data[0] << "blink"<< endl;

  Customer c1(data[0], data[1], data[2], data[3], data[4]);
  if (data[0].empty() && data[1].empty() && data[2].empty() && data[3].empty() && data[4].empty()){
    return_to_main_menu();
  }
  else
  {c1.search_customer();}

  int choice;
  choice = customer_menu();
  customers_menu(choice);
}
void delete_customer() {
  string cnic;
  string *arr;
  cout << "To remove customer details, enter: " << endl;
  cout << "CNIC: ";
  cin >> cnic;

  arr = search_cnic(cnic);

  if (arr[0] == "x") {
    while (arr[0] == "x") {
      cout << "Customer not found." << endl;
      cout << "You have entered the CNIC of a customer that doesn't exist in "
              "the database. Please enter an existing customer's CNIC: ";
      cin >> cnic;
      arr = search_cnic(cnic);
    }
  }

  Customer c1(arr[0], arr[1], arr[2], arr[3], arr[4]);
  delete[] arr;

  int choice;
  cout << "Confirm remove customer details?" << endl;
  cout << "1.Confirm. " << endl;
  cout << "2.Cancel. " << endl;
  cin >> choice;

  if (choice == 1)
    c1.delete_customer();

  else if (choice == 2)
    cout << "Cancelled" << endl;
  else
    cout << "Invalid option. " << endl;

  int choice2;
  choice2 = customer_menu();
  customers_menu(choice2);
}
void add_item() {
  string sku, des;
  float price;
  int qty;
  cout << "To add new item, enter: " << endl;
  cout << "Item_SKU: ";
  cin >> sku;
  cout << "Description: ";
  cin.get();
  getline(cin, des);
  cout << "Price: ";
  cin >> price;
  cout << "Quantity: ";
  cin >> qty;

  string Price = to_string(price);
  string quantity = to_string(qty);
  Item c1(sku, des, Price, quantity);
  c1.add_new_item();

  
  int choice;
  choice = items_menu();
  items_menu(choice);
}
void delete_item() {

  string sku;
  string *arr;
  cout << "To remove item, enter: " << endl;
  cin.get();
  cout << "Item_SKU: ";
  getline(cin, sku);

  arr = search_sku(sku);

  if (arr[0] == "x") {
    while (arr[0] == "x") {
      cout << "Item not found." << endl;
      cout << "You have entered the item SKU of an item that doesn't exist in "
              "the database. Please enter an existing item's SKU: ";
      cin >> sku;
      arr = search_sku(sku);
    }
  }

  Item i1(arr[0], arr[1], arr[2], arr[3]);
  delete[] arr;

  int choice;
  cout << "Confirm remove item?" << endl;
  cout << "1.Confirm. " << endl;
  cout << "2.Cancel. " << endl;
  cin >> choice;

  if (choice == 1)
    i1.delete_item();

  else if (choice == 2)
    cout << "Cancelled" << endl;
  else
    cout << "Invalid option. " << endl;

  int choice2;
  choice2 = items_menu();
  items_menu(choice2);
}
void search_item()
{
 string data[4];
  
  cin.get();
  cout << "Please specify at least one of the following to find the item. "
          "Leave all fields blank to return to Items Menu."
       << endl;
 
  cout << "Item SKU: ";
  getline(cin, data[0]);
  cout << "Description: ";
  getline(cin, data[1]);
  cout << "Price: ";
  getline(cin, data[2]);
  cout << "Quantity: ";
  getline(cin, data[3]);
 
  
  Item c1(data[0], data[1], data[2], data[3]);
  if (data[0].empty() && data[1].empty() && data[2].empty() && data[3].empty()){
    return_to_main_menu();
  }
  else
  {c1.search_item();}

  int choice;
  choice = items_menu();
  items_menu(choice);
}
void modify_item() {
  string sku;
  string description;
  string price;
  string qty;
  string *temp;
  cin.get();
  cout << "Enter Item_SKU: ";
  getline(cin, sku);
  temp = search_sku(sku);
  if (temp[0] == "x") {
    while (temp[0] == "x") {
      cout << "Item not found." << endl;
      cout << "You have entered the Item_SKU of an item that doesn't exist in "
              "the database. Please enter an existing item's SKU: ";
      getline(cin, sku);
      temp = search_sku(sku);
    }
  }
  Item c1(temp[0], temp[1], temp[2], temp[3]);
  cout << endl;
  c1.display1();
  cout << "To modify item details, enter following fields. Leave blank to keep "
          "the detail same as before. "
       << endl;
  cout << "Description: ";
  getline(cin, description);
  cout << "Price: ";
  getline(cin, price);
  cout << "Available quantity: ";
  getline(cin, qty);

  if (description.empty())
    description = temp[1];
  if (price.empty())
    price = temp[2];
  if (qty.empty())
    qty = temp[3];

  delete[] temp;

  int choice;
  cout << "Confirm modify details?" << endl;
  cout << "1.Confirm. " << endl;
  cout << "2.Cancel. " << endl;
  cin >> choice;

  if (choice == 1) {
    Item c2(sku, description, price, qty);
    c2.update_item();

  } else if (choice == 2) {
    cout << "Cancelled" << endl;
  } else {
    cout << "Invalid option. " << endl;
  }

  int choice2;
  choice2 = items_menu();
  items_menu(choice2);
}
void items_menu(int choice) {
  if (choice == 1) {
    add_item();
  } else if (choice == 2) {
    modify_item();
  } else if (choice == 3) {
    search_item();
  } else if (choice == 4) {
    delete_item();
  }
  else if (choice == 5)
  {
    return_to_main_menu();
  }
}
int items_menu() {
  int choice;
  cout << "1. Add new item." << endl;
  cout << "2. Update item details." << endl;
  cout << "3. Find item." << endl;
  cout << "4. Remove existing item." << endl;
  cout << "5. Return to main menu." << endl;
  cout << "(Press 1 to 5 to select an option.)" << endl;
  cin >> choice;
  while (choice < 1 || choice > 5) {
    cout << "Invalid option. Press 1 to 5 to select an option." << endl;
    cin >> choice;
    cin.get();
  }

  return choice;
}
void customers_menu(int choice) {
  if (choice == 1) {
    add_customer();
  } else if (choice == 2) {
    modify_customer();
  } else if (choice == 3) {
    find_customer();
  } else if (choice == 4) {
    delete_customer();
  }
  else if(choice == 5){
   return_to_main_menu();
  }
}
int customer_menu() {
  int choice;
  cout << "1. Add new customer." << endl;
  cout << "2. Update customer details." << endl;
  cout << "3. Find customer." << endl;
  cout << "4. Remove existing customer." << endl;
  cout << "5. Return to main menu." << endl;
  cout << "(Press 1 to 5 to select an option.)" << endl;
  cin >> choice;
  while (choice < 1 || choice > 5) {
    cout << "Invalid option. Press 1 to 5 to select an option." << endl;
    cin >> choice;
    cin.get();
  }
  return choice;
}
int sales_menu() {
  int choice;
  cout << "Press 1 to enter new item." << endl;
  cout << "Press 2 to end sale." << endl;
  cout << "Press 3 to remove existing item from the current sale." << endl;
  cout << "Press 4 to cancel sale." << endl;
  cout << "(Choose from option 1-4)" << endl;
  cin >> choice;
  return choice;
}
void make_payment(Sales sale1,int size)
{
  POS p1(sale1,size);
  p1.make_payment();
}
void enter_new_item(Saleslineitem sli, Customer c, double totalamount);
void remove_item_from_sale(Sales s1,int size, double total, int option)
{
  int j = 0;
  bool a = (option == 3);
  string *temp;
  int newtotal;
  string sku;
  Customer c2 = s1.get_customer ();
  Saleslineitem s4[size - 1];
  int index;
  Saleslineitem sli;
  Sales sale;
  while (option == 3)
  {
  cout << "Enter Item_SKU to remove item from sale: ";
  cin >> sku;
  temp = search_sku(sku);
  
  
  for (int i = 0; i < size; i++) {
      sli = s1.get_sli(i);
    Item item = sli.get_item ();
    if (item.get_sku() == sku && j<size-1)
    {
      index = i;
      item.add_back_qty(sli.get_quantity());
    }
  }
  for (int i=0;i<index;i++)
    {
    sli = s1.get_sli(i);
    s4[i] = sli;
    }

  for (int i=index+1;i<size;i++)
    { sli = s1.get_sli(i);
      s4[i-1] = sli;
    }
    sli = s1.get_sli(index);
    double newtotal = total - sli.get_quantity()*stod(temp[2]);
   c2.set_amountpayable(newtotal);


    sale.set_customer(c2);
   sale.set_sli(size-1,s4);
    
      cout << "Removed item successfully." << endl;
   option = sales_menu();
    if (option!=3)
      {break;}
    
   }  
    
  if (option == 2)
  {
    sale.display_bill(size-1, c2.get_amountpayable());
  
   int choice = return_main_menu();
    if (choice == 4)
      {
        make_payment(sale,size-1);
      }
    }
   
  else if (option == 4)
  {cout << "Sale cancelled."<< endl;
   return;}
  else
  {cout << "Invalid option."<< endl;
  return;}

  delete [] temp;
}
void enter_new_item(Saleslineitem sli, Customer c, double totalamount) {
  int option = 1;
  string sku[1000];
  int qty[1000];
  string *item;
  int count = 1;
  Saleslineitem s[1000];
  s[0].set_item(sli.get_item());
  s[0].set_lineno(1);
  s[0].set_quantity(sli.get_quantity());
  double total = totalamount;

  for (int i = 0; i < 1000; i++) 
  {
    cout << "Enter Item_SKU: ";
    cin >> sku[i];
    item = search_sku(sku[i]);
    if (item[0] == "x") {
      while (item[0] == "x") {
        cout << "Item not found." << endl;
        cout
            << "You have entered the Item_SKU of an item that doesn't exist in "
               "the database. Please enter an existing item's SKU: ";
        cin >> sku[i];
        item = search_sku(sku[i]);
      }
    }
    Item i1(item[0], item[1], item[2], item[3]);

    cout << "Enter quantity: ";
    cin >> qty[i];
    if (qty[i] > stoi(item[3]) || qty[i] < 0) {
      while (qty[i] > stoi(item[3]) || qty[i] < 0) {
        cout << "There is not enough available quantity to purchase this item "
                "in this quantity.The maximum quantity that can be purchased  "
                "of this item is "
             << item[3] << endl;
        cout << "Please re-enter quantity: ";
        cin >> qty[i];
      }
    }
    i1.update_qty(qty[i]);
    total = total + qty[i] * stod(item[2]);
    
    cout << "Total amount payable: " << total << endl;
    c.set_amountpayable(total);
    count++;
    s[i + 1].set_item(i1);
    s[i + 1].set_lineno(count);
    s[i + 1].set_quantity(qty[i]);

    option = sales_menu();
    
    delete[] item;
    if (option != 1)
      break;
  
}
 
      Sales sale(c, s, count);
      if (option == 2)
       {sale.display_bill(count, total);
      
       int choice = return_main_menu();
          if (choice == 4)
          {
            make_payment(sale,count);
          }
       }
     else if (option == 3)
       {remove_item_from_sale(sale, count, total, 3);}
     if (option == 4)
       {cout << "Sale cancelled."<< endl;}
     else
    {cout << "Invalid option."<< endl;}
    

}
void make_new_sale( ) {
  string sku;
  string cnic;
  string *customer;
  string *item;
  int qty;

  cout << "Enter CNIC: ";
  cin >> cnic;
  customer = search_cnic(cnic);

  if (customer[0] == "x") {
    while (customer[0] == "x") {
      cout << "Customer not found." << endl;
      cout << "You have entered the CNIC of a customer that doesn't exist in "
              "the database. Please enter an existing customer's CNIC: ";
      cin >> cnic;
      customer = search_cnic(cnic);
    }
  }
  cout << "Enter Item_SKU: ";
  cin >> sku;
  item = search_sku(sku);
  if (item[0] == "x") {
    while (item[0] == "x") {
      cout << "Item not found." << endl;
      cout << "You have entered the Item_SKU of an item that doesn't exist in "
              "the database. Please enter an existing item's SKU: ";
      cin >> sku;
      item = search_sku(sku);
    }
  }
  display_des_price(sku);
  cout << "Enter quantity purchased: ";
  cin >> qty;

  if (qty > stoi(item[3]) || qty < 0) {
    while (qty > stoi(item[3]) || qty < 0) {
      cout << "There is not enough available quantity to purchase this item in "
              "this quantity.The maximum quantity that can be purchased  of "
              "this item is "
           << item[3] << endl;
      cout << "Please re-enter quantity: ";
      cin >> qty;
    }
  }

  double total = qty * stod(item[2]);
  cout << "Sub-total: "<< total << endl;
  
  Customer c(customer[0], customer[1], customer[2], customer[3], customer[4]);
  c.set_amountpayable(total);
 
  Item i(item[0], item[1], item[2], item[3]);

  Saleslineitem s2[1];
  s2[0].set_item(i);
  s2[0].set_lineno(1);
  s2[0].set_quantity(qty);
  Sales s6(c, s2, 1);

  i.update_qty(qty);

  delete[] customer;
  delete[] item;
  
  int option = sales_menu();
  if (option == 1) {
    enter_new_item(s2[0], c, total);
  } else if (option == 2) 
  {
    s6.display_bill(1, total);

    int choice = return_main_menu();
    if (choice == 4)
    {
      make_payment(s6,1);
    }

  } else if (option == 3) {
    remove_item_from_sale(s6,1, total, 3);
  } else if (option == 4) {
   cout << "Sale cancelled." << endl;
  } else
    cout << "Invalid choice." << endl;
}
void return_to_main_menu()
{
  int option;
  int choice;
  option = main_menu();

  if (option == 1)
  {
    choice = items_menu();
    items_menu(choice);
  }
  else if (option == 2)
  {
    choice = customer_menu();
    customers_menu(choice);
  }
  else if (option == 3)
  {
    
    make_new_sale();
    
  }
  else if (option == 4)
  {
    Sales s1;
    make_payment(s1,1);
  }
  else if (option == 5)
  {
    cout << "Exited."<< endl;
  }

}
int return_main_menu()
{
  int option;
  int choice;
  option = main_menu();

  if (option == 1)
  {
    choice = items_menu();
    items_menu(choice);
  }
  else if (option == 2)
  {
    choice = customer_menu();
    customers_menu(choice);
  }
  else if (option == 3)
  {
   make_new_sale();
  }
  else if (option == 5)
  {
    cout << "Exited."<< endl;
  }
 return option;

}
int main() {


  int option;
  int choice;
  option = main_menu();

  if (option == 1)
  {
    choice = items_menu();
    items_menu(choice);
  }
  else if (option == 2)
  {
    choice = customer_menu();
    customers_menu(choice);
  }
  else if (option == 3)
  {
    make_new_sale();
  }
  else if (option == 4)
  {
    Sales s1;
    make_payment(s1,1);
  }
  else if (option == 5)
  {
    cout << "Exited."<< endl;
  }

 

  return 0;
}
