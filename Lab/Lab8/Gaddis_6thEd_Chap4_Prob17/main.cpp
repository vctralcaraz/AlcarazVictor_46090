/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 2, 2015, 1:01 PM
 * Purpose: Wavelengths
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
    //Define and initialize variables
    float waveLth;  //wave length in meters
    bool doAgain;
    
    do{

    //user input of wavelength
    cout<<"What is the wave length in meters?"<<endl;
    cin>>waveLth;
    
    //loop for wavelengths
        if(waveLth<1e-11){
            cout<<"You are in the Gamma Ray wave length!"<<endl;
        }else if(waveLth<=1e-8){
            cout<<"You are in the X-Ray wave length!"<<endl;
        }else if(waveLth<=4e-7){
            cout<<"You are in the Ultra Violet wave length!"<<endl;
        }else if(waveLth<=7e-7){
            cout<<"You are in the Visible Light wave length!"<<endl;
        }else if(waveLth<=1e-3){
            cout<<"You are in the Infrared wave length!"<<endl;
        }else if(waveLth<=1e-2){
            cout<<"You are in the Micro wave length!"<<endl;
        }else{
            cout<<"You are in the Radio wave length!"<<endl;
        }
        
        //prompt if you want to run it again
        char response;
        cout<<endl;
        cout<<"Would you like to put in another wave length? y/n"<<endl;
        cin>>response;
        cout<<endl;
        if(response=='y')doAgain=true;
        else doAgain=false;
        
    }while(doAgain);
    return 0;
}

