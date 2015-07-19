/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 15, 2015, 1:07 PM
 * Purpose: Generate and print a two dimensional array
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void filAray(int [][12],int);
void prntAry(int [][12],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //declare array
    const int ROWS=12;
    const int COLS=12;
    int array[ROWS][COLS];
    
    filAray(array,ROWS);
    
    prntAry(array,ROWS);
    
    //Exit Stage Right!
    return 0;
}

/************************************************
 *                  Print Array                 *
 ************************************************
 * Purpose: To print the two dimensional array
 * Input:
 *      a -> array[ROWS][COLS]
 *      r -> ROWS
 * Output:
 *      The Two dimensional array
 ***********************************************/
void prntAry(int a[][12],int r){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=12;j++){
            cout<<setw(3)<<a[i][j]<<" ";
            if((j%13)==(13-1)){
            cout<<endl;
            }
        }
    }
}

/************************************************
 *                  Fill Array                  *
 ************************************************
 * Purpose: To generate the two dimensional array
 * Input:
 *      a -> array[ROWS][COLS]
 *      r -> ROWS
 * Output:
 *      The Two dimensional array
 ***********************************************/
void filAray(int a[][12],int r){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=12;j++){
            a[i][j]=i*j;
        }
    }
}