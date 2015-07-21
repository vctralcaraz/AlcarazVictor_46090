/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 21, 2015, 12:41 PM
 * Purpose: Chapter 6 Savitch Problems
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();

//Execution begins here
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1: problem1();break;
        case 2: problem2();break;
        case 3: problem3();break;
        case 4: problem4();break;
        case 5: problem5();break;
        case 6: problem6();break;
        case 7: problem7();break;
            default:;
        };
    }while(inN<8);
    return 0;
}

//Menu Function
void Menu(){
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 7 for problem 7"<<endl;
    cout<<"Type 8 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
    int inN;
    cin>>inN;
    return inN;
}

//Solution to problem 1
void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
    ofstream outputFile;
    outputFile.open("data.txt");
    
    cout<<"Now writing data to the file.\n";
    
    outputFile<<"Bach\n";
    outputFile<<"Beethoven\n";
    outputFile<<"Mozart\n";
    outputFile<<"Schubert\n";
    
    outputFile.close();
    cout<<"Done\n";
}

//Solution to problem 2
void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    ifstream inFile;
    const int SIZE=81;
    char name[SIZE];
    
    inFile.open("data.txt");
    cout<<"Reading data from the file.\n\n";
    
    inFile>>name;
    cout<<name<<endl;
    
    inFile>>name;
    cout<<name<<endl;
    
    inFile>>name;
    cout<<name<<endl;
    
    inFile>>name;
    cout<<name<<endl;
    
    inFile.close();
    cout<<"\nDone\n";
}

//Solution to problem 3
void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
}

//Solution to problem 4
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
}

//Solution to problem 5
void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
}

//Solution to problem 6
void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
}

//Solution to problem 7
void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
}

//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}