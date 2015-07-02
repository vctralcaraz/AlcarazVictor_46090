/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 30, 2015, 12:56 PM
 * Purpose: Lab 6, Math Tutor program
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Set the random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned short op1;      //first number
    unsigned short op2;      //second number
    unsigned short result;
    unsigned short answer;
    char op;                 //operator
    bool doAgain;
    
    //loop based upon continuing to play with the math tutor
    do{
        //determine op1/op2
        op1=rand()%900+100;  //[100-999]
        op2=rand()%900+100;  //[100-999]
        op=rand()%5;
        
        //display the problem
        cout<<setw(6)<<op1<<endl;
        switch(op){
            case 0:{
                cout<<" + "<<op2<<endl;
                answer=op1+op2;
                break;
            }
            case 1:{
                cout<<" - "<<op2<<endl;
                answer=op1-op2;
                break;
            }
            case 2:{
                cout<<" * "<<op2<<endl;
                answer=op1*op2;
                break;
            }
            case 3:{
                cout<<" / "<<op2<<endl;
                answer=op1/op2;
                break;
            }
            case 4:{
                cout<<" % "<<op2<<endl;
                answer=op1%op2;
                break;
            }

        }
        cout<<"------"<<endl;
        //doAgain=false;
        
        //input the value for the sum
        cin>>result;
        
        //if correct, output congratulations, else try again?
        if(result==answer){
            cout<<"Congratulations!"<<endl;
        }else{
            cout<<endl<<"Wrong Answer"<<endl;
            cout<<"The answer is "<<answer<<endl;
            
        }
        
        //Prompt if they would like to continue
        cout<<endl<<"Would you like to continue? y/n"<<endl;
        char response;
        cin>>response;
        if(response=='y')doAgain=true;
        else doAgain=false;
        
    }while(doAgain);

    //Exit Stage Right!
    return 0;
}

