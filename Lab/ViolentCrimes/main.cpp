/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 25, 2015, 12:25 PM
 * Purpose: Lab 4, Violent Crimes in the US and UK
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
    
    // Define Variables
    float usPop;      //Population of the US in millions
    float ukPop;      //Population of the UK in millions
    float usCrime;    //Number of violent crimes in the US in 2002
    float ukCrime;    //Number of violent crimes in the UK in 2002
    float rteUs;      //Crime rate in the US in %
    float rteUk;      //Crime rate in the UK in %
    
    //Input Variables
    usPop=318e6;      //318,000,000
    ukPop=64.1e6;     //64,100,000
    usCrime=11.88e6;  //11,880,000
    ukCrime=6.52e6;   //6,520,000
    
    //Calculating crime rate for both US and UK
    rteUs=usCrime/usPop*100;
    rteUk=ukCrime/ukPop*100;
    
    //Output
    cout<<setprecision(2)<<fixed;
    cout<<"The crime rate in the US is "<<rteUs<<"% with a population ";
    cout<<"of "<<static_cast<int>(usPop)<<" people!"<<endl;
    cout<<"The crime rate in the UK is "<<rteUk<<"% with a population ";
    cout<<"of "<<static_cast<int>(ukPop)<<" people!"<<endl;
    cout<<"What country has the higher crime rate?"<<endl;
    
    //Exit Stage Right!
    return 0;
}

