/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 24, 2015, 4:31 PM
 * Purpose: Homework, Big C
 */

//System Libraries
#include <iostream>//I/O Library
using namespace std;//Standard namespace for iostream

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables
    char c;     //The character that will be input
    
    //The character input
    cout<<"Give me a single Character."<<endl;
    cin>>c;
    //Calculate process
    
    //Output
    cout<<"    "<<c<<" "<<c<<" "<<c<<endl;
    cout<<"   "<<c<<"    "<<c<<endl;
    cout<<"  "<<c<<endl;
    cout<<"  "<<c<<endl;
    cout<<"  "<<c<<endl;
    cout<<"  "<<c<<endl;
    cout<<"  "<<c<<endl;
    cout<<"   "<<c<<"    "<<c<<endl;
    cout<<"    "<<c<<" "<<c<<" "<<c<<endl;
    
    //Exit Stage Right!
    return 0;
}