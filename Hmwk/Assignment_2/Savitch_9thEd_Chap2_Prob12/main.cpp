/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 5, 2015, 10:40 AM
 * Purpose: Homework, Water Wells
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
const float PI=4*atan(1);
const float CUFTCNV=7.48f;    //conversion from one cubic foot to gallons of water

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Define Variables
    float wellRad;  //radius of the well in inches(in)
    float wellDep;  //depth of the well in feet(ft)
    float volWell;  //volume of the well in gallons
    
    //User input of radius and depth
    cout<<"What is the radius, in inches, of your well?"<<endl;
    cin>>wellRad;
    cout<<endl;
    
    cout<<"What is the depth, in feet, of your well?"<<endl;
    cin>>wellDep;
    cout<<endl;
    
    //Calculate volume
    wellRad/=12;
    volWell=PI*wellRad*wellRad*wellDep;
    volWell*=CUFTCNV;
    
    //Output the results
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Your water well holds "<<volWell<<"(gal) of water!"<<endl;

    //Exit Stage Right!!
    return 0;
}

