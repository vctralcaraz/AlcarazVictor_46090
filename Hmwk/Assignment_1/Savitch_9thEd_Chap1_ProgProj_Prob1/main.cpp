/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 23, 2015, 7:29 PM
 * Purpose: Homework, Two Variables
 */

//System Libraries
#include <iostream> //File I/O
using namespace std; //std namespace -> iostream

//User Libraries

//Global constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables Here
    int var1 = 46;      //first variable
    int var2 = 83;      //second variable
    int sum;            //the sum of variables 1 and 2
    int product;        //the product of variables 1 and 2
    
    //Input Values Here
    sum=var1+var2;
    product=var1*var2;
    
    //Output Unknowns Here
    cout<<"The sum of the two variables is "<<sum<<"."<<endl;
    cout<<"The product of the two variables is "<<product<<"."<<endl;
    
    //Exit Stage Right!
    return 0;
}
