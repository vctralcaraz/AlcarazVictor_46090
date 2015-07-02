/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 30, 2015, 12:18 PM
 * Purpose: Lab 6, How many candy bars can I eat
 * per day without gaining weight
 */

//System Libraries
#include <fstream>
#include <iostream>
using namespace std;

//User Libraries

//Global constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare Variables
    unsigned short wtLbs;       //weight in pounds
    unsigned short htInch;      //height in inches
    unsigned short ageYrs;      //age in years
    unsigned short bmr;         //basal metabolic rate
    unsigned char nChcBar;      //number of chocolate bars
    unsigned char calChoc=230;  //calories per chocolate bar
    char sex;                   //sex of the person
    ifstream input;
    
    //loop as long as we have data
    input.open("bmr.dat");
    
    //Exhaust the data in the file
    //while(!input.eof()){
        
        //Read from file
        //input>>sex>>wtLbs>>htInch>>ageYrs;
        //or
    
    while(input>>sex>>wtLbs>>htInch>>ageYrs){
        
        //Calculate BMR due to sex
        if(sex=='F'){
            bmr=655+4.3*wtLbs+4.7*htInch-4.7-ageYrs;
        }else{
            bmr=66+6.3*wtLbs+12.9*htInch-6.8-ageYrs;
        }
        
        //What is the equivalent number of chocolate bars
        nChcBar=bmr/calChoc;
        
        //Output the results
        cout<<"Sex = "<<sex<<endl;
        cout<<"Wt  = "<<wtLbs<<"(lbs)"<<endl;
        cout<<"Ht  = "<<htInch<<"(inches)"<<endl;
        cout<<"Age = "<<ageYrs<<"(years)"<<endl;
        cout<<"Your BMR = "<<bmr<<"(cal)"<<endl;
        cout<<"Number of candy bars you may consume = "
                <<static_cast<int>(nChcBar)<<endl;
        cout<<endl<<endl;
        
    }
    
    //Exit Stage Right!
    return 0;
}

