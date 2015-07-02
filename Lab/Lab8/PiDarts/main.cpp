/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 2, 2015, 10:21 AM
 * Purpose: Approximate PI with a dart board
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
const double PI=4*atan(1.0);
const double MXRND=pow(2,31)-1;

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed with time
    srand(static_cast<unsigned int>(time(0)));
    
    //Determine the maximum and minimum
    unsigned int max=rand();
    unsigned int min=rand();
    unsigned int nDarts=1000000000;
    unsigned int nDrtInC=0;
    float apprxPI=0;
    
    //loop to find the min and max
    for(int dart=1;dart<=nDarts;dart++){
        float x=rand()/MXRND;//[0,1]
        float y=rand()/MXRND;//[0,1]
        if(x*x+y*y<=1)nDrtInC++;
    }
    apprxPI=4.0f*nDrtInC/nDarts;
    //output the results
    cout<<fixed<<showpoint<<setprecision(20);
    cout<<"Exact Value of PI = "<<PI<<endl;
    cout<<"The approximate value of PI = "<<apprxPI<<endl;
    
    //Exit Stage Right!
    return 0;
}

