/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 2, 2015, 11:03 AM
 * Purpose:  Generate the Fibonacci Sequence
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    //Declare and initialize members of the sequence
    unsigned short fi=1;
    unsigned short fip1=1;
    unsigned short fip2;
    unsigned char terms=10;
    
    //print the initial conditions
    cout<<"The number of terms in the Fibonacci sequence to display is "<<terms<<endl;
    cout<<"Term "<<1<<" in the sequence = "<<fi<<endl;
    cout<<"Term "<<2<<" in the sequence = "<<fip1<<endl;
    
    //Loop and show terms as you generate
    for(unsigned char term=3;term<=terms;term++){
        //calculate the next term in the sequence
        fip2=fi+fip1;
        //output the current term
        cout<<"Term "<<static_cast<int>(term)<<" in the sequence = "<<fip2<<endl;
        //now shift
        fi=fip1;
        fip1=fip2;
    }
    
    return 0;
}

