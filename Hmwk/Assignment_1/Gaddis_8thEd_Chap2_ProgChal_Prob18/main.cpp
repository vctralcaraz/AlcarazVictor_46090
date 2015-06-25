/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 23, 2015, 5:03 PM
 * Purpose: Homework, Energy Drink Consumption
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
    unsigned short cSurv = 16500;   //the amount of people surveyed
    unsigned short pEDrnks = 15;    //percentage of surveyed that drink energy drinks
    unsigned short pCDrnks = 58;    //percent of energy drinkers that prefer citrus flavor
    unsigned short nEDrnks;         //number of energy drinkers
    unsigned short nCDrnks;         //number of energy drinkers prefer citrus flavor
    
    //Input Values Here
    nEDrnks=cSurv*pEDrnks/100;
    nCDrnks=nEDrnks*pCDrnks/100;
    
    //Output Unknowns Here
    cout<<"Out of the "<<cSurv<<" surveyed, "<<nEDrnks<<" drank energy drinks."<<endl;
    cout<<"Of those "<<nEDrnks<<", "<<nCDrnks<<" people preferred the citrus flavor."<<endl;
    
    //Exit Stage Right!
    return 0;
}