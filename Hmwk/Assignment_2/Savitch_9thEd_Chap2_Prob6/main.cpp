/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 1, 2015, 1:04 PM
 * Purpose: Homework, worker hours
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
    float payRate=16.78;       //pay-rate of employee in $'s
    unsigned short hrsWrkd;    //hours the employee worked
    float socSec=0.06f;        //percent withheld for social security
    float fedTax=0.14f;        //percent withheld for federal income tax
    float steTax=0.05f;        //percent withheld for state income tax
    float ssTake;              //amount of social security taken in $'s
    float ftTake;              //amount of federal taxes taken in $'s
    float stTake;              //amount of state taxes taken in $'s
    float ttlTake;             //total amount of taxes and dues paid
    unsigned short uniDues=10; //union dues in $'s
    unsigned short dpndnts;    //number of dependants the employee has
    unsigned short dpndCst;    //cost in $'s depending how many dependants
    float grssPay;             //pay before taxes
    float netPay;              //pay after taxes
    bool doAgain;
    
    do{
        //prompt hours
        cout<<"How many hours did you work this week?"<<endl;
        cin>>hrsWrkd;

        //calculating gross pay
        if(hrsWrkd>40){
            //Define variables
            unsigned short ovrHrs;       //overtime hours worked
            float ovrPay;              //amount paid in overtime in $'s

            //calculating pay
            ovrHrs=hrsWrkd-40;
            ovrPay=ovrHrs*(payRate*1.5);
            grssPay=(40*payRate)+ovrPay;
        }else{
            grssPay=hrsWrkd*payRate;
        }

        //calculate taxes taken
        ssTake=grssPay*socSec;   //social security taken
        ftTake=grssPay*fedTax;   //federal tax taken
        stTake=grssPay*steTax;   //state tax taken
        ttlTake=ssTake+ftTake+stTake+uniDues; 

        //prompt dependants
        cout<<"How many dependants do you have?"<<endl;
        cin>>dpndnts;
        cout<<endl;

        if(dpndnts>=3){
            dpndCst=35; //cost in $'s if dependants is 3 or more
        }else{
            dpndCst=0; //cost in $'s if dependants is less than 3
        }

        //calculate netpay
        netPay=grssPay-ttlTake-dpndCst;

        //Output gross pay, amounts withheld, and net pay
        cout<<fixed<<showpoint<<setprecision(2);
        cout<<"Hours worked:      "<<setw(6)<<hrsWrkd<<endl;
        cout<<"Gross Pay:        $"<<setw(6)<<grssPay<<endl;
        cout<<"Social Security: -$"<<setw(6)<<ssTake<<endl;
        cout<<"Federal Tax:     -$"<<setw(6)<<ftTake<<endl;
        cout<<"State Tax:       -$"<<setw(6)<<stTake<<endl;
        cout<<"Union Dues:      -$"<<setw(6)<<uniDues<<endl;
        cout<<"Health Insurance:-$"<<setw(6)<<dpndCst<<endl;
        cout<<"Net-Pay:          $"<<setw(6)<<netPay<<endl;
        cout<<endl;
        
        //prompt the user if the process wants to be repeated
        char response;
        cout<<"Do you want to start over? y/n"<<endl;
        cin>>response;
        
        if(response=='y')
            doAgain=true;
        else
            doAgain=false;
        
    }while(doAgain);
    //Exit Stage Right!
    return 0;
}

