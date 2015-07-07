/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 5, 2015, 10:46 PM
 * Purpose: Freezing and Boiling Points
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
    int ethFrz=-173;   //ethyl alcohol freezing point in degrees Fahrenheit
    int mercFrz=-38;   //mercury freezing point in degrees Fahrenheit
    int oxyFrz=-362;   //oxygen freezing point in degrees Fahrenheit
    int wtrFrz=32;     //water freezing point in degrees Fahrenheit
    int ethBol=172;    //ethyl alcohol boiling point in degrees Fahrenheit
    int mercBol=676;   //mercury boiling point in degrees Fahrenheit
    int oxyBol=-306;   //oxygen boiling point in degrees Fahrenheit
    int wtrBol=212;    //water boiling point in degrees Fahrenheit
    int degrees;       //user input of degrees Fahrenheit
    
    //User input of temperature
    cout<<"Enter a temperature in degrees Fahrenheit"<<endl;
    cin>>degrees;
    
    //check for what's boiling and freezing
    if(degrees<=ethFrz)cout<<"Ethyl Alcohol freezes"<<endl;
    if(degrees<=mercFrz)cout<<"Mercury freezes"<<endl;
    if(degrees<=oxyFrz)cout<<"Oxygen freezes"<<endl;
    if(degrees<=wtrFrz)cout<<"Water freezes"<<endl;
    if(degrees>=ethBol)cout<<"Ethyl Alcohol boils"<<endl;
    if(degrees>=mercBol)cout<<"Mercury boils"<<endl;
    if(degrees>=oxyBol)cout<<"Oxygen boils"<<endl;
    if(degrees>=wtrBol)cout<<"Water boils"<<endl;
    
    
    //Exit Stage Right!
    return 0;
}

