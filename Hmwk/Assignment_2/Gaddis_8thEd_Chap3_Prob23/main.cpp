/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 30, 2015, 5:14 PM
 * Purpose: Homework, Stock Transaction Program
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Define and Initialize Variables
    unsigned int nShares=1000;   //number of shares involved in the transaction
    float cstShre=45.5f;         //the cost per share in $'s
    float brkrCom=0.02f;         //2% broker commission per transaction
    float sldShre=56.9f;         //selling price per share
    float stkPaid;               //total paid w/o commission for purchase
    float stkSold;               //total sold w/o commission for sale
    float comBuy;                //total commission for broker on purchase
    float comSell;               //total commission for broker on sale
    float ttlPaid;               //total paid w/ commission for purchase
    float ttlSold;               //total sold w/ commission for sale
    float profit;                //total profit between purchase and sale of stock
    
    //Calculate stock purchase and commission
    stkPaid=nShares*cstShre;
    comBuy=stkPaid*brkrCom;
    ttlPaid=stkPaid+comBuy;
    
    //Calculate stock sale and commission
    stkSold=nShares*sldShre;
    comSell=stkSold*brkrCom;
    ttlSold=stkSold-comSell;
    
    //Calculate the profit(if any)
    profit=ttlSold-ttlPaid;
    
    //Output the results
    cout<<fixed<<setprecision(2);
    cout<<"Joe bought "<<nShares<<" shares of stock at $"<<cstShre<<" per share.\n";
    cout<<"He paid $"<<stkPaid<<" for the stock alone. On top of that, at 2%, the \n";
    cout<<"stockbroker got $"<<comBuy<<" commission for the purchase. That is a total of\n";
    cout<<"$"<<ttlPaid<<" paid for the purchase. Two weeks later, Joe decided to sell all\n";
    cout<<"of his stock and got $"<<sldShre<<" per share."<<endl;
    cout<<"That is a sale of $"<<stkSold<<" of stock. His broker then got $"<<comSell<<endl;
    cout<<"for the transaction and Joe got $"<<ttlSold<<" total for the sale of stock.\n";
    cout<<"Between both transactions, Joe profitted $"<<profit<<". What a deal!"<<endl;

    //Exit Stage Right!
    return 0;
}

