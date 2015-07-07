/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 5, 2015, 1:10 PM
 * Purpose: Homework, Thermal Expansion
 */

//System Libraries
#include <iostream>//I/O Library
using namespace std;//Standard namespace for iostream

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float initLth;    //initial length of material in meters
    float displac;    //displacement in meters
    float tmpChng;    //change in temperature in Celsius
    float coefcnt;    //coefficient for linear expansion
    
    //User input of data
    cout<<"What is the initial length of the material in meters?"<<endl;
    cin>>initLth;
    cout<<endl;
    
    cout<<"What is the change in temperature in Celsius?"<<endl;
    cin>>tmpChng;
    cout<<endl;
    
    cout<<"Enter the coefficient for linear expansion."<<endl;
    cin>>coefcnt;
    cout<<endl;
    
    //Calculate the the thermal expansion
    displac=coefcnt*initLth*tmpChng;
    
    //Output the results
    if(displac<0){
        cout<<"The material will contract by "<<-displac<<" meters."<<endl;
    }else if(displac>0){
        cout<<"The material will expand by "<<displac<<" meters."<<endl;
    }else
        cout<<"There was no thermal expansion."<<endl;
    
    //Exit Stage Right!
    return 0;
}

