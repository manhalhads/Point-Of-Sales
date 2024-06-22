#include "POS.h"
POS :: POS() { Sales ();}
Customer POS :: get_customer()
{
 return sales.get_customer();
}
Saleslineitem POS :: get_sli(int index)
{
  return sales.get_sli(index);
}
Receipt POS ::get_receipt(){return sales.get_receipt();}
int POS :: get_salesid(){return sales.get_salesid();}
string POS :: get_status(){return sales.get_status();}
string POS :: get_date(){return sales.get_date();}
void POS :: set_customer (Customer c){sales.set_customer(c);}
void POS :: set_sli(int index, Saleslineitem* s){sales.set_sli(index,s);}
void POS :: set_receipt(int no, double amount){sales.set_receipt(no,amount);}
void POS :: set_salesid(int id){sales.equate_salesid(id);}
void POS :: set_date(){sales.set_date();}
void POS :: set_status(string status){sales.set_status(status);}
POS :: POS(Sales s1, int size)
{ 
    Saleslineitem s2[size];
    
 sales.equate_salesid(s1.get_salesid());
 sales.set_date();
 sales.set_customer(s1.get_customer());
 Receipt r1 = s1.get_receipt();
 sales.set_receipt(r1.get_receiptno(),r1.get_amount());
 sales.set_status(s1.get_status());

 for (int i=0;i<size;i++)
 s2[i] = s1.get_sli(i);
}
void POS :: display(int size)
{
    sales.display(size);
}
void POS :: make_payment()
{
    int id;
    double amountpaid = 0;
    double payment;
    cout << "Enter SalesID: ";
    cin >> id;
    if (sales.get_salesid() == id)
    {
        Customer c1 = get_customer();
        cout << "Customer name: "<< c1.get_name()<< endl;
        cout << "Total sales amount: "<< c1.get_amountpayable()<< endl;

         if (c1.get_type() == "Gold")
        {
            c1.set_amountpayable(c1.get_amountpayable()-(c1.get_amountpayable()*3/100)); 
            cout << "Amount after discount: "<< c1.get_amountpayable() << endl;
        }
       else  if (c1.get_type() == "Platinum")
        {
            c1.set_amountpayable(c1.get_amountpayable()-(c1.get_amountpayable()*5/100)); 
            cout << "Amount after discount: "<< c1.get_amountpayable() << endl;
        }

        cout << "Amount Paid: "<< amountpaid << endl;
        cout << "Remaining amount: "<< c1.get_amountpayable() - amountpaid << endl;
        cout << "Amount to be paid: ";
        cin >> payment;
        
       
       c1.set_amountpayable(c1.get_amountpayable() - payment);

       cout << "Paymment recorded."<< endl;
       cout << "Customer balance successfully updated."<< endl;
       
    }
    else
    {cout << "Sales ID not found."<< endl;}

}
