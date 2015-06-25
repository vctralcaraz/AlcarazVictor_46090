/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 24, 2015, 3:39 PM
 * Purpose: Homework, Coin Counter
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Standard namespace

//User Libraries

//Global Constants

//Function Prototypes

int main(int argc, char** argv) {
    //Declare Variables
    float quartVa = 0.25f;     //The value of a quarter in $'s
    float dimeVa = 0.1f;       //The value of a dime in $'s
    float nickVa = 0.05f;      //The value of a nickel in $'s
    unsigned short nQuarts;    //The number of quarters
    unsigned short nDimes;     //The number of dimes
    unsigned short nNicks;     //The number of nickels
    float ttlMony;             //The total amount of money you have in $'s
    
    //User input of how many coins of each he or she has
    cout<<"How many Quarters do you have?"<<endl;
    cin>>nQuarts;
    cout<<"How many Dimes do you have?"<<endl;
    cin>>nDimes;
    cout<<"How many Nickels do you have?"<<endl;
    cin>>nNicks;
    
    //Calculate
    ttlMony=(quartVa*nQuarts)+(dimeVa*nDimes)+(nickVa*nNicks);
    
    //Output
    cout<<"You have $"<<ttlMony<<"!"<<endl;

    //Exit Stage Right!
    return 0;
}
