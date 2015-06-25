/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 25, 2015, 11:17 AM
 * Purpose: To prove your math instructor
 */

//System Libraries
#include <iostream>//I/O Library
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare variables
    unsigned short a,b,c;
    short d,e,f;
    ofstream out;
    srand(static_cast<unsigned int>(time(0)));
    int thrwDce;
    
    
    //Initialize values
    a=20000;
    b=50000;
    d=20000;
    e=30000;
    out.open("numbers.dat");
    thrwDce=rand()%6+1;
    
    //Perform a simple addition
    c=a+b;
    f=d+e;
    
    //Output the results
    cout<<setw(6)<<c<<" = "<<a<<" + "<<b<<endl;
    cout<<setw(6)<<f<<" = "<<d<<" + "<<e<<endl;
    cout<<"The Dice value = "<<thrwDce<<endl;
    cout<<pow(2,3)<<" = "<<exp(3*log(2))<<endl;
    out<<setw(6)<<c<<" = "<<a<<" + "<<b<<endl;
    out<<setw(6)<<f<<" = "<<d<<" + "<<e<<endl;
    out<<"The Dice value = "<<thrwDce<<endl;
    out<<pow(2,3)<<" = "<<exp(3*log(2))<<endl;
    
    //Exit stage right!
    out.close();
    return 0;
}

