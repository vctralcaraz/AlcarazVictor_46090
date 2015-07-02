/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 30, 2015, 3:13 PM
 * Purpose: Homework, Stadium Seating
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototype

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Define and Initialize Variables
    unsigned short seatA=15.0f;    //price of seating class a in $'s
    unsigned short seatB=12.0f;    //price of seating class b in $'s
    unsigned short seatC=9.0f;     //price of seating class c in $'s
    unsigned short tktSldA;     //the amount of tickets sold in a
    unsigned short tktSldB;     //the amount of tickets sold in b
    unsigned short tktSldC;     //the amount of tickets sold in c
    unsigned short total;       //total amount of income from tickets in $'s
    
    //User input of tickets sold per class seating
    cout<<"How many tickets were sold in class A seating?"<<endl;
    cin>>tktSldA;
    cout<<endl;
    cout<<"How many tickets were sold in class B seating?"<<endl;
    cin>>tktSldB;
    cout<<endl;
    cout<<"How many tickets were sold in class C seating?"<<endl;
    cin>>tktSldC;
    cout<<endl;
    
    //Calculating total income from tickets sold
    total=seatA*tktSldA+seatB*tktSldB+seatC*tktSldC;
    
    //Output the results
    cout<<setprecision(2)<<showpoint<<fixed;
    cout<<"The total income from seating sales is $"<<total<<"!"<<endl;
    
    
    //Exit Stage Right!
    return 0;
}

