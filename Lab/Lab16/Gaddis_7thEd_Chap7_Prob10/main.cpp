/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 16, 2015, 12:52 PM
 * Purpose: Grade a test
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void filAray(char [],int);
void prntAry(const char [],int,int);
int grade(char [],char [],char [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=20;
    char qstns[SIZE],
         answers[SIZE],
         rhtwrg[SIZE];
    
    //initialize array
    filAray(qstns,SIZE);
    filAray(answers,SIZE);
    
    //grade the test
    int score=grade(qstns,answers,rhtwrg,SIZE);
    
    //output the array
    cout<<"The Test Question Solutions"<<endl;
    prntAry(qstns,SIZE,5);
    cout<<"The Test Question Answers"<<endl;
    prntAry(answers,SIZE,5);
    
    //output the score
    cout<<"The scores recieved"<<endl;
    prntAry(rhtwrg,SIZE,5);
    
    cout<<"The score = "<<score<<" out of "<<SIZE<<endl;
    
    //Exit stage right!
    return 0;
}

/**********************************************
 *               score the test               *
 **********************************************
 * Purpose: To print the character type array with
 *          any number of columns
 * Input:
 *      n-> the size of the array
 *      q-> the question array
 *      a-> the answer array
 * Output:
 *      c-> the score array
 *      score-> the total correct
 **********************************************/
int grade(char q[],char a[],char c[],int n){
    //declare the count/score
    int score=0;
    //grade each answer
    for(int i=0;i<n;i++){
        if(q[i]==a[i]){
            c[i]='c';
            score++;
        }
        else c[i]='i';
    }
    //return value
    return score;
}

/**********************************************
 *                 print array                *
 **********************************************
 * Purpose:To fill an array with a,b,c,d
 * Input:
 *      a-> The array
 *      n-> the size of the array
 * Input-Output:
 *      character array
 * Output:
 **********************************************/
void prntAry(const char a[],int n,int nCols){    
    cout<<endl;
    //loop and output every element in the array
    for(int i=0;i<n;i++){
        cout<<setw(2)<<a[i];
        //When column is reached go to next line
        if((i%nCols)==(nCols-1))cout<<endl;
    }
    //separate outputs
    cout<<endl;
}

/**********************************************
 *                  Fill Array                *
 **********************************************
 * Purpose:To fill an array with a,b,c,d
 * Input:
 *      n-> the size of the array
 * Input-Output:
 *      character array
 * Output:
 **********************************************/
void filAray(char a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%4+97;//[a,b,c,d]
    }
}