/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 23, 2015, 10:52 AM
 * Purpose: Simple sort step by step
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants

//Function Prototypes
Array * filAray(int);
void prntAry(const Array *,int);
void swap(int &,int &);
void swapMin(int [],int,int);
void markSrt(int [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=200;
    Array *array=filAray(size);
    
    //Output the initial array
    prntAry(array,20);
    
    //Process the inputs
    markSrt(array->data,size);
    
    //Output the results
    prntAry(array,20);
    
    //Exit Stage Right
    delete []array->data;
    delete []array;
    return 0;
}

/**************************************************
 *                Mark Sort                       *
 **************************************************
 * Purpose:  To sort any integer array
 * Input:
 *    n-> The size of the array
 * Input-Output:
 *    a-> The sorted integer Array
 */
void markSrt(int a[],int n){
    //Loop and sort every position
    for(int pos=0;pos<n-1;pos++){
        swapMin(a,n,pos);
    }
}

/**************************************************
 *                   SwapMin                      *
 **************************************************
 * Purpose:  To place the minimum at the top of the
 *           list.
 * Input:
 *    n-> Size of the array/list
 *    pos->Position to place the minimum
 * Input-Output:
 *    a-> An integer array/list
 */
void swapMin(int a[],int n,int pos){
    //Loop through the list starting at pos+1
    for(int i=pos+1;i<n;i++){
        //Place smallest value at the position pos
        if(a[pos]>a[i])swap(a[pos],a[i]);
    }
}

/**************************************************
 *                     Swap                       *
 **************************************************
 * Purpose:  To swap by logical operations two values
 * Input-Output:
 *    a-> An integer value
 *    b-> An integer value
 */
void swap(int &a,int &b){
    //Perform the logical in-place swap
    a=a^b;
    b=a^b;
    a=a^b;
}

/**************************************************
 *                Print Array                      *
 **************************************************
 * Purpose:  To print an integer array with any
 *           number of columns
 * Input:
 *    n-> The size of the array
 *    a-> The array structure
 *    nCols->Number of columns to display the array.
 * Output:
 *    On Screen
 */
void prntAry(const Array *a,int nCols){
    //Separate outputs with a line
    cout<<endl;
    //Loop and output every element in the array
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<" ";
        //When column is reached go to next line
        if((i%nCols)==(nCols-1))cout<<endl;
    }
    //Separate outputs with a line
    cout<<endl;
}

/**************************************************
 *                Fill Array                      *
 **************************************************
 * Purpose:  To fill an array with 2 digit integer
 *           random numbers.
 * Input:
 *    n-> The size of the array
 * Input-Output:
 *    a-> The array structure
 * Output:
 */
Array * filAray(int n){
    //declare a structure pointer
    Array *a=new Array; //allocating memory for the structure
    a->size=n;          //setting the size of the data array
    a->data=new int[a->size=n]; //allocating memory for the data
    //Loop on every element and equate to 2 digits
    for(int i=0;i<n;i++){
        a->data[i]=rand()%90+10;//[10-99]
    }
    //return the array
    return a;
}