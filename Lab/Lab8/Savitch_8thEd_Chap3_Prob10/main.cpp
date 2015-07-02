/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 2, 2015, 11:18 AM
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
    float crudWt;
    float nDays;
    
    //print the initial conditions
    cout<<"Input the initial crud weight in lbs"<<endl;
    cin>>crudWt;
    cout<<"Input the number of days allowed to grow"<<endl;
    cin>>nDays;
    
    //scale the nDays to the Fibonacci Sequence
    terms=nDays/5+1;    //scale by 5 days and start at a term=1;
    
    //given the 3 conditions
    if(terms==1){
        cout<<"The crud wt after "<<nDays<<" = "<<crudWt<<"(lbs)"<<endl;
    }else if(terms==2){
        cout<<"The crud wt after "<<nDays<<" = "<<crudWt<<"(lbs)"<<endl;
    }else{
        //Loop and show terms as you generate
        for(unsigned char term=3;term<=terms;term++){
            //calculate the next term in the sequence
            fip2=fi+fip1;
            //output the current term
            //cout<<"Term "<<static_cast<int>(term)<<" in the sequence = "<<fip2<<endl;
            //now shift
            fi=fip1;
            fip1=fip2;
        }
        cout<<"The crud wt after "<<nDays<<" = "<<fip2*crudWt<<"(lbs)"<<endl;
    }
    return 0;
}

