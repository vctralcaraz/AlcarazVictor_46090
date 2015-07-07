/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 5, 2015, 9:15 PM
 * Purpose: Speed of Sound in Gases
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare and Initialize Variables
    float carDiox=258.0f;    //carbon dioxide and the speed of sound through it in meters per second(m/s)
    float air=331.5f;        //air and the speed of sound through it in m/s
    float helium=972.0f;     //helium and the speed of sound through it in m/s
    float hydrgn=1270.0f;    //hydrogen and the speed of sound through it in m/s
    char choice;             //user choice
    unsigned int time;       //time in seconds
    float source;            //distance, in meter, the source is from the detection.
    
    //User prompt of what gas
    cout<<"       1. Carbon Dioxide"<<endl;
    cout<<"       2. Air"<<endl;
    cout<<"       3. Helium"<<endl;
    cout<<"       4. Hydrogen"<<endl<<endl;
    cout<<"Which gas did the sound travel through? (1-4)"<<endl;
    cin>>choice;
    
    switch(choice){
        case '1':
            cout<<"How many seconds did take for the sound to get from the source to detection site?"<<endl;
            cin>>time;
            source=carDiox*time;
            cout<<"The source of the sound is "<<source<<" meters away from the detection site"<<endl;
            break;
        case '2':
            cout<<"How many seconds did take for the sound to get from the source to detection site?"<<endl;
            cin>>time;
            source=air*time;
            cout<<"The source of the sound is "<<source<<" meters away from the detection site"<<endl;
            break;
        case '3':
            cout<<"How many seconds did take for the sound to get from the source to detection site?"<<endl;
            cin>>time;
            source=helium*time;
            cout<<"The source of the sound is "<<source<<" meters away from the detection site"<<endl;
            break;
        case '4':
            cout<<"How many seconds did take for the sound to get from the source to detection site?"<<endl;
            cin>>time;
            source=hydrgn*time;
            cout<<"The source of the sound is "<<source<<" meters away from the detection site"<<endl;
            break;
        default:
            cout<<"You didn't choose from the selection of 1-4"<<endl;
            return 1;
    }
    
    
    //Exit Stage Right!
    return 0;
}

