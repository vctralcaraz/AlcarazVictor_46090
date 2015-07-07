/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 1, 2015, 5:45 PM
 * Purpose: Homework, Velocity of Sound
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begin Here!
int main(int argc, char** argv) {
    
    //Define and Initialize Variables
    float velocty;     //speed/velocity in meters per second(m/s)
    int tempCel;      //temperature of the air in degrees Celsius
    int strtTmp;      //starting temperature in degrees Celsius
    int endTmp;       //ending temperature in degrees Celsius
    bool doAgain;
    
    cout<<"Choose a starting temperature and an ending temperature in degrees Celsius."<<endl;
    
    do{
        //User input of Temperature in Celsius
        cin>>strtTmp>>endTmp;
        cout<<endl;
        
        if(strtTmp<=endTmp){
            while(strtTmp<=endTmp){
            //calculating velocity
                velocty=331.3+0.61*strtTmp;

                //Output every result in the while-loop
                cout<<fixed<<showpoint<<setprecision(1);
                cout<<"At "<<strtTmp<<" degrees Celsius, the velocity of sound is "<<velocty<<" m/s."<<endl;
                strtTmp++;
                doAgain=false;
            }
        }else{
            cout<<"Please enter a starting temperature that is smaller than the ending temperature."<<endl<<endl;
            doAgain=true;
        }
    
    }while(doAgain);
    return 0;
}

