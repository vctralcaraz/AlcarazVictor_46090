/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 2, 2015, 1:23 PM
 * Purpose: Homework, To calculate time from seconds
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
    //define and initialize variables
    unsigned int years;  //number of years
    unsigned int months; //number of months
    unsigned int weeks;  //number of weeks
    unsigned int days;   //number of days
    unsigned int hours;  //number of hours
    unsigned int minutes;//number of minutes
    unsigned int seconds;//number of seconds
    unsigned int nSecs;  //number of seconds inputted by user
    
    cin>>nSecs;
    
    seconds=nSecs%60;
    nSecs/=60;
    minutes=nSecs%60;
    nSecs/=60;
    hours=nSecs%24;
    nSecs/=24;
    days=nSecs%7;
    nSecs/=7;
    weeks=nSecs%4;
    nSecs/=4;
    months=nSecs%12;
    years=nSecs/12;
    
    cout<<years<<endl;
    cout<<months<<endl;
    cout<<weeks<<endl;
    cout<<days<<endl;
    cout<<hours<<endl;
    cout<<minutes<<endl;
    cout<<seconds<<endl;
    
    
    return 0;
}