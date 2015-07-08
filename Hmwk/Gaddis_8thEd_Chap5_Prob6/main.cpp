/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 7, 2015, 6:06 PM
 * Purpose: To figure out distance traveled
 */

//System Libraries
#include <iostream>//I/O Library
#include <iomanip>
using namespace std;//Standard namespace for iostream

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float distnce; //distance traveled in miles
    float speed;   //speed of vehicle in MPH
    float hours;   //number of hours the vehicle traveled
    
    //User input of hours and speed
    cout<<"What was the speed of the vehicle? (MPH)"<<endl;
    cin>>speed;
    cout<<endl;
    cout<<"How many hours was the vehicle traveling?"<<endl;
    cin>>hours;
    cout<<endl<<endl;

    //Loop that calculates and outputs the distance
    if(speed>0 && hours>0){
        
        cout<<"Hour     Distance Traveled"<<endl;
        cout<<"---------------------------"<<endl;
        
        for(unsigned int time=1;time<=hours;time++){
            distnce=time*speed;

            cout<<" "<<time<<"        "<<setw(4)<<distnce<<" miles"<<endl;

        }
    }else {
        cout<<"You need to put a positive number for speed and hours."<<endl;
        return 1;
    }
    
    //Exit Stage Right!
    return 0;
}

