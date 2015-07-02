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
    float x=2.0f;    //the x in e^x
    float ex=1.0f;   //first term value in the exponential sequence
    float delt=1.0f; //incremental value of each term in the sequence
    float tol=1e-7;  //determine the accuracy for the approximation
    
    //utilize a for-loop to calculate e^x
    for(int term=1;delt<-tol||delt>tol;delt*=x/term,ex+=delt,term++){}
    
    //output the result
    cout<<fixed<<showpoint<<setprecision(15);
    cout<<"Exact  e("<<x<<")!="<<exp(x)<<endl;
    cout<<"Approx e("<<x<<")!="<<ex<<endl;
    
    //Exit Stage Right!
    return 0;
}