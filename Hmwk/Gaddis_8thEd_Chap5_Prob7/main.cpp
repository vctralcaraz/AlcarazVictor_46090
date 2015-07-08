/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 7, 2015, 6:30 PM
 * Purpose: Pennies for Pay
 */

//System Libraries
#include <iostream>//I/O Library
#include <iomanip>
using namespace std;//Standard namespace for iostream

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int days; //days in days
    float money=0.01f; //daily money amount in $'s
    float ttlMony;     //total amount of money at the end of cycle in $'s
    
    //User input of days
    cout<<"You get a starting salary of 1 penny for the first day and"<<endl;
    cout<<"2 pennies for the second day. Your income keeps doubling"<<endl;
    cout<<"per day. Enter an amount of days that you would like to see"<<endl;
    cout<<"calculated with your salary."<<endl;
    cin>>days;
    cout<<endl;
    
    //Loop to calculate and output money earned
    if(days>=1){
        cout<<"Day    Money Recieved"<<endl;
        cout<<"-----------------------"<<endl;
        for(unsigned int cycle=1;cycle<=days;cycle++){
            cout<<" "<<setw(2)<<cycle<<"        $"<<setw(10)<<money<<endl;
            ttlMony+=money;
            money*=2;
        }
    }else {
        cout<<"You can't have zero or a negative amount of days"<<endl;
        return 1;
    }
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"   Total = $"<<setw(10)<<ttlMony<<endl;
    //Exit Stage Right!
    return 0;
}


