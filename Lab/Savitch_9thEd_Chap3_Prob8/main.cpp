/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 1, 2015, 12:30 PM
 * Purpose: Pi
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
const float PI=4*atan(1);

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare and Initialize Variables
    int nTerms=2000000000;
    float apprxPI=1;
    
    //now calculate pi with a for-loop
    for(int i=3,nTerm=1;nTerm<=nTerms;i+=4,nTerm+=2){
        apprxPI+=(-1.0f/i+1.0f/(i+2.0f));
    }
    apprxPI*=4;
    
    //output the result and compare
    cout<<fixed<<showpoint<<setprecision(15);
    cout<<"Exact Value of PI = "<<PI<<endl;
    cout<<"The approximate value of PI = "<<apprxPI<<endl;
    
    //Exit stage right!
    return 0;
}

