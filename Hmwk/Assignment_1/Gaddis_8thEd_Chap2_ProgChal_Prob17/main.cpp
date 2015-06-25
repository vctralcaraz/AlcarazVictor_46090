/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 23, 2015, 4:34 PM
 * Purpose: Homework, Stock Commission
 */

//System Libraries
#include <iostream> //File I/O
using namespace std; //std namespace -> iostream

//User Libraries

//Global constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables Here
    unsigned short shrStck=750;   //Shares of stock
    unsigned short stkCost=35;    //the cost per share in $s
    unsigned short pComm=2;       //Percent of commission to broker
    unsigned short stckTtl;       //The amount paid for the stock alone
    unsigned short brkrCom;       //The amount of the commission
    float total;                  //The total amount paid
    
    //Input Values Here
    stckTtl=shrStck*stkCost;
    brkrCom=stckTtl*pComm/100;
    total=stckTtl+brkrCom;
    
    //Output Unknowns Here
    cout<<"750 shares of stock = $"<<stckTtl<<endl;
    cout<<"Broker Commission   = $"<<brkrCom<<endl;
    cout<<"Total amount paid   = $"<<total<<endl;
    
    //Exit Stage Right!
    return 0;
}

