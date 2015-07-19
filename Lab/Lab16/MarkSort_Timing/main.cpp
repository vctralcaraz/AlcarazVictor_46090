/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on July 16, 2015, 10:36 AM
 * Purpose:  Simple Sort step by step
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void filAray(int [],int);
void prntAry(const int [],int,int);
void swap(int &,int &);
void swapMin(int [],int,int);
void markSrt(int [],int);
void mrkSrt2(int [],int);
void copy(int [],int [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100000;
    int array[SIZE],brray[SIZE];
    
    //Initialize the array
    filAray(array,SIZE);
    
    //Copy the random array
    copy(array,brray,SIZE);
    
    //Output the initial array
    //prntAry(array,SIZE,20);
    //prntAry(brray,SIZE,20);
    
    //Process the inputs for the first sort
    unsigned int start=time(0);
    markSrt(array,SIZE);//3 function sort
    unsigned int end=time(0);
    cout<<"Total time 3 function sort "<<end-start<<"(secs)"<<endl;

    //Process the inputs for the second sort
    start=time(0);
    mrkSrt2(brray,SIZE);//1 function sort
    end=time(0);
    cout<<"Total time 1 function sort "<<end-start<<"(secs)"<<endl;
    
    //Output the results
    //prntAry(array,SIZE,20);
    //prntAry(brray,SIZE,20);
    
    //Exit Stage Right
    return 0;
}

/**************************************************
 *                Mark Sort 2                     *
 **************************************************
 * Purpose:  To sort any integer array but in 
 *           1 function call
 * Input:
 *    n-> The size of the array
 * Input-Output:
 *    a-> The sorted integer Array
 */
void mrkSrt2(int a[],int n){
    //Loop and sort every position
    for(int pos=0;pos<n-1;pos++){
        //Loop through the list starting at pos+1
        for(int i=pos+1;i<n;i++){
            //Place smallest value at the position pos
            if(a[pos]>a[i]){
                //Perform the logical in-place swap
                a[pos]=a[pos]^a[i];
                a[i]=a[pos]^a[i];
                a[pos]=a[pos]^a[i];
            }
        }
    }
}

/**************************************************
 *                Copy Array                      *
 **************************************************
 * Purpose:  To copy an integer array
 * Input:
 *    n-> The size of the array
 * Input-Output:
 *    a-> The original integer Array
 *    b-> The copied integer Array
 */
void copy(int a[],int b[],int n){
    //Loop on all elements
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
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
 *    a-> The integer Array
 *    nCols->Number of columns to display the array.
 * Output:
 *    On Screen
 */
void prntAry(const int a[],int n,int nCols){
    //Separate outputs with a line
    cout<<endl;
    //Loop and output every element in the array
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        //When column is reached go to next line
        if((i%nCols)==(nCols-1))cout<<endl;
    }
    //Separate outputs with a line
    cout<<endl;
}

/**************************************************
 *                Fill Array                      *
 **************************************************
 * Purpose:  To fill an array with integer
 *           random numbers.
 * Input:
 *    n-> The size of the array
 * Input-Output:
 *    a-> The integer Array
 * Output:
 */
void filAray(int a[],int n){
    //Loop on every element
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
}