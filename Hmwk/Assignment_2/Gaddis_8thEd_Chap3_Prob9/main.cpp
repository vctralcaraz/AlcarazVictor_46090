/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 30, 2015, 3:51 PM
 * Purpose: Homework, How Many Calories?
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {

    //Define Variables
    unsigned short ttlCkie=30;    //amount of cookies per bag
    unsigned short ttlSrv=10;     //amount of servings per bag
    unsigned short calSrv=300;    //amount of calories per serving
    unsigned short calCkie;       //amount of calories per cookie
    unsigned short ckieAte;        //amount of cookies eaten
    unsigned short calCnsm;       //amount of calories consumed from cookies
    
    //User input of how many cookies eaten
    cout<<"How many cookies did you eat?"<<endl;
    cin>>ckieAte;
    cout<<endl;
    
    //calculating calories
    calCkie=calSrv/(ttlCkie/ttlSrv);
    calCnsm=ckieAte*calCkie;
    
    //Output Calories
    cout<<"With those "<<ckieAte<<" cookies,"<<endl;
    cout<<"you consumed "<<calCnsm<<" Calories!"<<endl;
     
    //Exit Stage Right!
    return 0;
}

