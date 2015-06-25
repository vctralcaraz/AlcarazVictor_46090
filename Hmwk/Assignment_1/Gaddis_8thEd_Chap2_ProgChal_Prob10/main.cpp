/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 23, 2015, 4:16 PM
 * Purpose: Homework, Miles Per Gallon
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
    unsigned short gallGas = 15.0f;   //Gallons of gas a car can hold
    unsigned short mlsTrav = 375.0f;  //Distance traveled in miles
    unsigned short mPG;               //Miles Per Gallon Driven
    
    //Calculating Miles Per Gallon
    mPG=mlsTrav/gallGas;
    
    //Output Unknowns Here
    cout<<"The car's MPG is "<<mPG<<"!"<<endl;
    
    //Exit Stage Right!
    return 0;
}



