/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 30, 2015, 4:42 PM
 * Purpose: Homework, Currency Exchange
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
    
    //Local Constants
    const float YEN_PER_DOLLAR=122.39f;   //conversion rate of dollars to yen
    const float EUROS_PER_DOLLAR=0.9f;     //conversion rate of dollars to euros
    
    //Define Variables
    float usDlrs;      //amount of currency in $'s
    float jpnYen;       //amount of currency in yen
    float ukEuro;      //amount of currency in euros
    
    //User Input of currency
    cout<<"How much money in dollars do you have?"<<endl;
    cin>>usDlrs;
    
    //Calculating conversions to yen and euros
    jpnYen=usDlrs*YEN_PER_DOLLAR;
    ukEuro=usDlrs*EUROS_PER_DOLLAR;
    
    //Output the amount of currency you have in yen and in euros
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"In Japan, you would have "<<jpnYen<<" yen!"<<endl;
    cout<<"And in Europe, you would have "<<ukEuro<<" euros!"<<endl;
    
    return 0;
}

