/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 5, 2015, 4:05 PM
 * Purpose: Homework, The Speed of Sound
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
    //Declare and Initialize Variables
    unsigned int air=1100;   //speed of sound through air in ft/s
    unsigned int water=4900; //speed of sound through water in ft/s
    unsigned int steel=16400;//speed of sound through steel in ft/s
    unsigned int distnce;           //distance sounds traveled
    float time;              //time taken in seconds to travel distance 
    char choice;
    
    //User input of distance in feet
    cout<<"How far is the sound traveling? (ft)"<<endl;
    cin>>distnce;
    
    //menu
    cout<<"      1. Air"<<endl;
    cout<<"      2. Water"<<endl;
    cout<<"      3. Steel"<<endl<<endl;
    cout<<"What medium is sound traveling through? 1-3"<<endl;
    cin>>choice;
    cout<<fixed<<setprecision(4);
    
    switch(choice){
        case '1':
            time=distnce/air;
            cout<<"Sound traveled "<<distnce<<"(ft) in "<<time<<"(secs)"<<endl;
            break;
        case '2':
            time=distnce/water;
            cout<<"Sound traveled "<<distnce<<"(ft) in "<<time<<"(secs)"<<endl;
            break;
        case '3':
            time=distnce/steel;
            cout<<"Sound traveled "<<distnce<<"(ft) in "<<time<<"(secs)"<<endl;
            break;
        default:
            cout<<"You didn't choose a corresponding number"<<endl;
            return 1;
    }
    
    //Exit Stage Right!
    return 0;
}

