#include <iostream>
using namespace std;
#include<cstdlib>
class Card
{
protected:
    string cardSerialNumber;
    string ownerName;
    double balance;
    string issuingBank;
public:
    Card()
    {
        cardSerialNumber=ownerName=issuingBank="";
        balance=0.0;
    }
    Card(string cardSerialNumber,string ownerName,double balance,string issuingBank)
    {
        this->cardSerialNumber=cardSerialNumber;
        this->ownerName=ownerName;
        this->balance=balance;
        this->issuingBank=issuingBank;

    }
    void Display()
    {
        cout<<"The card serial number is: "<<cardSerialNumber<<endl;
        cout<<"Owner of this card is: "<<ownerName<<endl;
        cout<<"The balance of this card is: "<<balance<<endl;
        cout<<"The issuing bank of this card is: "<<issuingBank<<endl;
    }
    void makePurchase(double price)
    {
        if((balance-price)>=0)
        {
            double percentage;
            if(price<500)
            {
                percentage=5/100*price;
                price-=percentage;
                cout<<"There will be a discount with 5%, so you pay only: "<<price<<" LE."<<endl;
                balance-=price;
            }
             else if(price>=500 || price<1000)
            {
                percentage=7.5/100*price;
                price-=percentage;
                cout<<"There will be a discount with 7.5%, so you pay only: "<<price<<" LE."<<endl;
                balance-=price;
            }
            else
            {
                percentage=10/100*price;
                price-=percentage;
                cout<<"There will be a discount with 10%, so you pay only: "<<price<<" LE."<<endl;
                balance-=price;
            }

        }
        else
            cout<<"Can't purchase, balance is not enough"<<endl;

    }
    void addBalance(int price)
    {
        balance+=price;
    }
    void Modify(double price)
    {
        if(price<0){
            cout<<"Error::Can't be negative balance."<<endl;
            exit(EXIT_FAILURE);
        }
        balance=price;
    }
};
class CreditCard:public Card
{
private:
    double limit;
public:
     CreditCard()
     {
         limit=0.0;
     }
     CreditCard(string cardSerialNumber,string ownerName,string issuingBank,double limit):Card(cardSerialNumber,ownerName,0,issuingBank)
     {
       this->limit=limit;
     }
     void makePurchase(int price)
     {
         if((balance+price)>limit)
            cout<<"Can't buy anything more,you have to pay for old purchases first."<<endl;
         balance+=price;
     }
     void Pay(double price)
     {
         balance-=price;
         cout<<"Your balance is now: "<<balance<<" LE."<<endl;
     }
      void Display()
    {
        cout<<"The card serial number is: "<<cardSerialNumber<<endl;
        cout<<"Owner of this card is: "<<ownerName<<endl;
        cout<<"The balance of this card is: "<<balance<<endl;
        cout<<"The issuing bank of this card is: "<<issuingBank<<endl;
        cout<<"The account limit is: "<<limit<<endl;
    }
};
int main()
{
    CreditCard**cards=new CreditCard*[3];
    cards[0]=new CreditCard("111","Sarah","Ahly Bank",1000);
    cards[1]=new CreditCard("222","Farah","Masry Bank",5000);
    cards[2]=new CreditCard("333","Yarah","Zmalek Bank",10000);
    cards[0]->Display();
    cards[1]->makePurchase(500);
    cards[1]->Display();
    cards[2]->makePurchase(500);
    cards[2]->Display();
    cards[0]->addBalance(2000);
    cards[0]->Display();
    cards[0]->Modify(-99);
    return 0;
}
