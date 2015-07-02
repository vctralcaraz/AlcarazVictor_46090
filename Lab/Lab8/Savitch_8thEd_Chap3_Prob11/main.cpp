/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 2, 2015, 12:09 PM
 * Purpose: Approximate e^x with an infinite sequence
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //declare variables
    float x=2.0f;
    float ex=1.0f;
    char nTerms=30;
    
    //utilize a for-loop to calculate e^x
    for(int term=1;term<=nTerms;term++){
        float fact=1;

        //loop and find the n!
        for(int i=1;i<=term;i++){
            fact*=i;
        }
        ex+=pow(x,term)/fact;
    }
    
    //output the result
    cout<<fixed<<showpoint<<setprecision(15);
    cout<<"Exact  e("<<x<<")!="<<exp(x)<<endl;
    cout<<"Approx e("<<x<<")!="<<ex<<endl;
    
    //Exit Stage Right!
    return 0;
}