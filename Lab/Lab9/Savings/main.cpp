/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 6, 2015, 12:40 PM
 * Purpose: Learn how to save
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float save1(float,float,int);
float save2(float,float,int);
float save3(float,float,int);
float save4(float,float,int);
float save5(float,float,int);
float save5(float,float,float);
float save6(float,float,int);
float save7(float,float,int);
float save8(float,float,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables
    float pv=1e4f;//present value in $'s
    float i=5e-2f;//interest rate
    int nCmpd=50; //number of compounding periods (yrs)
    
    //output the future value of our savings
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Present Value = $"<<pv<<endl;
    cout<<"Interest Rate =  "<<i*100<<"%"<<endl;
    cout<<"Years to save =  "<<nCmpd<<"(yrs)"<<endl;
    cout<<"Savings 1 =     $"<<save1(pv,i,nCmpd)<<endl;
    cout<<"Savings 2 =     $"<<save2(pv,i,nCmpd)<<endl;
    cout<<"Savings 3 =     $"<<save3(pv,i,nCmpd)<<endl;
    cout<<"Savings 4 =     $"<<save4(pv,i,nCmpd)<<endl;
    cout<<"Savings 5 =     $"<<save5(pv,i,nCmpd)<<endl;
    float fnCmpd=nCmpd;
    cout<<"Same savings 5 but with n as a float"<<endl;
    cout<<"Savings 5 =     $"<<save5(pv,i,fnCmpd)<<endl;
    cout<<"Bank Savings 6 =     $"<<save6(pv,i,nCmpd)<<endl;
    cout<<"The Poeple's Bank Savings 7 =     $"<<save7(pv,i,nCmpd)<<endl;
    cout<<"The More Poeple's Bank Savings 8 =     $"<<save8(pv,i,nCmpd)<<endl;
    
    //Exit Stage Right!
    return 0;
}
//Savings function
//Inputs
//p->Present value in $'s
//i->interest rate %/year
//n->compounding periods (yr)
float save1(float p,float i,int n){
    //loop to determine the answer
    for(int year=1;year<=n;year++){
        p*=(1+i);
    }
    return p;
}

//Savings function
//Inputs
//p->Present value in $'s
//i->interest rate %/year
//n->compounding periods (yr)
float save2(float p,float i,int n){
    //use the power function
    return p*pow(1+i,n);
}

//Savings function
//Inputs
//p->Present value in $'s
//i->interest rate %/year
//n->compounding periods (yr)
float save3(float p,float i,int n){
    //use the exp and log function
    return p*exp(n*log(1+i));
}

//Savings function
//Inputs
//p->Present value in $'s
//i->interest rate %/year
//n->compounding periods (yr)
float save4(float p,float i,int n){
    //call ourself aka recursion
    if(n<=0)return p;
    return save4(p,i,n-1)*(1+i);
}

//Savings function
//Inputs
//p->Present value in $'s
//i->interest rate %/year
//n->compounding periods (yr)
float save5(float p,float i,int n){
    //loop to determine the answer
    float power=1.0f;
    for(int year=1;year<=n;year++){
        power*=(1+i);
    }
    cout<<"n is an int"<<endl;
    return p*power;
}

//Savings function
//Inputs
//p->Present value in $'s
//i->interest rate %/year
//n->compounding periods (yr)
float save5(float p,float i,float n){
    //loop to determine the answer
    float power=1.0f;
    for(int year=1;year<=n;year++){
        power*=(1+i);
    }
    cout<<"n is a float"<<endl;
    return p*power;
}

//Savings function
//Inputs
//p->Present value in $'s
//i->interest rate %/year
//n->compounding periods (yr)
float save6(float p,float i,int n){
    //loop to determine the answer
    for(int year=1;year<=n;year++){
        p*=(1+i);
        //scale to pennies
        p=static_cast<int>(p*100)/100.0f;
    }
    return p;
}

//Savings function
//Inputs
//p->Present value in $'s
//i->interest rate %/year
//n->compounding periods (yr)
float save7(float p,float i,int n){
    //loop to determine the answer
    for(int year=1;year<=n;year++){
        p*=(1+i);
        //scale to pennies and round
        p=static_cast<int>(p*100+0.5)/100.0f;
    }
    return p;
}

//Savings function
//Inputs
//p->Present value in $'s
//i->interest rate %/year
//n->compounding periods (yr)
float save8(float p,float i,int n){
    //loop to determine the answer
    for(int year=1;year<=n;year++){
        p*=(1+i);
        //scale to pennies and round
        p=static_cast<int>(p*100+1)/100.0f;
    }
    return p;
}