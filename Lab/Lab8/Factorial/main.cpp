/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 2, 2015, 12:09 PM
 * Purpose: Calculate the Factorial
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
    float fact=1;
    unsigned char n=5;
    
    //loop and find the n!
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    
    //output the result
    cout<<static_cast<int>(n)<<"!="<<fact<<endl;
    
    //Exit Stage Right!
    return 0;
}