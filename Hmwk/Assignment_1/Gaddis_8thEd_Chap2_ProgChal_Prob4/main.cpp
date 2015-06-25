/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 23, 2015, 3:25 PM
 * Purpose: Homework, Restaurant Bill
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
    float mealCst = 88.67f;   //The meal cost at the restaurant
    float percTax = 0.0675f;  //Percent tax of the meal cost
    float percTip = 0.2f;     //Percent of the tip for overall cost
    float taxAmnt;            //The amount tax will be for the meal
    float totlTip;            //The amount the tip will be for the meal post-tax
    float total;              //The total amount charged for the meal 
    
    //Input Values Here
    taxAmnt = mealCst*percTax;
    totlTip = (mealCst+taxAmnt)*percTip;
    total = mealCst+taxAmnt+totlTip;
    
    //Output Unknowns Here
    cout<<"Meal = $"<<mealCst<<endl;
    cout<<"Tax = $"<<taxAmnt<<endl;
    cout<<"20% Tip = $"<<totlTip<<endl;
    cout<<"Total = $"<<total<<endl;
    
    //Exit Stage Right!
    return 0;
}