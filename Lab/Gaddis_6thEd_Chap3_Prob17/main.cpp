/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 1, 2015, 11:04 AM
 * Purpose: calculate monthly payments
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Define Variables
    unsigned short loanAmt=10000; //amount of the loan in $'s
    float intRate=0.01f;          //interest rate
    unsigned char nPaymnt=36;     //number of payments
    float mnthPay;                //the monthly payment in $'s
    float temp=1.0f;              //intermediate value found in monthly payment equation
    float cstLoan;                //cost of the loan in $'s
    float totCost;                //total paid back to lender in $'s
    
    //calculate monthly payment
    //mnthPay=(intRate*pow(1+intRate,nPaymnt)*loanAmt)/(pow(1+intRate,nPaymnt)-1);
    
    //calculate intermediate value
    float onePlsi=(1+intRate);
    for(int months=1;months<=nPaymnt;months++){
        temp*=onePlsi;
    }
    
    //calculate monthly payment
    mnthPay=intRate*temp*loanAmt/(temp-1);
    int imnthPay=mnthPay*100;    //taking off the fractional portion
    mnthPay=imnthPay/100.0f;     //exact amount in pennies
    totCost=nPaymnt*mnthPay;
    cstLoan=totCost-loanAmt;
    
    //display result
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"Loan Amount:          $"<<setw(8)<<static_cast<float>(loanAmt)<<endl;
    cout<<"Monthly Interest Rate: "<<setw(8)<<intRate*100<<"%"<<endl;
    cout<<"Number of Payments:    "<<setw(8)<<static_cast<int>(nPaymnt)<<endl;
    cout<<"Monthly Payment:      $"<<setw(8)<<mnthPay<<endl;
    cout<<"Amount Paid Back:     $"<<setw(8)<<totCost<<endl;
    cout<<"Interest Paid:        $"<<setw(8)<<cstLoan<<endl;
    
    return 0;
}

