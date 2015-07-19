/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 15, 2015, 12:11 PM
 * Purpose: Generate and print a parallel array
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int square(int);
void parAray(int [],int);
void prntAry(int [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //declare array
    const int SIZE=10;
    int array[SIZE];
    
    //set the array
    parAray(array,SIZE);
    
    //output the array
    cout<<"N     N^2"<<endl;
    cout<<"-     ---"<<endl;
    prntAry(array,SIZE);
    
    //Exit Stage Right!
    return 0;
}

/************************************************
 *                 Print Array                  *
 ************************************************
 * Purpose: To print the parallel array
 * Input:
 *      a -> Array
 *      n -> Size of the array
 * Output:
 *      The array
 ***********************************************/
void prntAry(int a[],int n){
    for(int i=1;i<=n;i++){
        cout<<setw(2)<<a[i]<<"    "<<setw(3)<<a[i*i]<<endl;
    }
}

/************************************************
 *                Parallel Array                *
 ************************************************
 * Purpose: To get the parallel Array
 * Input:
 *      a -> Array
 *      n -> Size of the array
 * Output:
 *      The array
 ***********************************************/
void parAray(int a[],int n){
    for(int i=1;i<=n;i++){
        a[i]=i;
        a[i*i]=i*i;
    }
}