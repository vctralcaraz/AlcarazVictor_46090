/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 24, 2015, 4:21 PM
 * Purpose: Homework, 
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std;//Namespace for iostream

//User Libraries

//Global Constants
const float GRAVITY=32.174f;//Acceleration due to Gravity Earth

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Declare variables
    float dstnce;     //The distance of drop in ft
    float time;       //Time in seconds
    
    //User input of time
    cout<<"To calculate the Distance Dropped"<<endl;
    cout<<"Input the Time in Seconds"<<endl;
    cin>>time;
    
    //Calculate the free-fall distance
    dstnce=GRAVITY*time*time/2;
    
    //Output the results
    cout<<"The distance traveled = ";
    cout<<dstnce<<"(ft)"<<endl;
    
    //Exit stage right!
    return 0;
}