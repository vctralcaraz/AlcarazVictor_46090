/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 2, 2015, 1:23 PM
 * Purpose: Homework, To calculate time from seconds
 */

//System Libraries
#include <iostream>
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
    bool doAgain;
    
    do{
        unsigned char response;
        
        //prompt user input in seconds
        cout<<"enter the amount of seconds you want to convert?"<<endl;
        cin>>nSecs;

        //calculating the conversion
        seconds=nSecs%60;  //seconds remaining
        nSecs/=60;
        minutes=nSecs%60;  //minutes remaining
        nSecs/=60;
        hours=nSecs%24;    //hours remaining
        nSecs/=24;
        days=nSecs%7;      //days remaining
        nSecs/=7;
        weeks=nSecs%4;     //weeks remaining
        nSecs/=4;
        months=nSecs%12;   //months remaining
        years=nSecs/12;    //years

        //output the results
        cout<<"That converts to:"<<endl;
        cout<<"Years     = "<<years<<endl;
        cout<<"Months    = "<<months<<endl;
        cout<<"Weeks     = "<<weeks<<endl;
        cout<<"Days      = "<<days<<endl;
        cout<<"Hours     = "<<hours<<endl;
        cout<<"Minutes   = "<<minutes<<endl;
        cout<<"Seconds   = "<<seconds<<endl;
        cout<<endl;
        cout<<"Would you like to convert more seconds? y/n"<<endl;
        cin>>response;
        cout<<endl;
        
        if(response=='y')doAgain=true;
        else doAgain=false;
        
    }while(doAgain);
    
    return 0;
}