/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 15, 2015, 10:19 AM
 * Purpose: 
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
int linSrch(int [],int,int,int);
int cntDup(int [],int,int);
int binSrch(int [],int &,int &,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=1000;
    int array[SIZE];
    
    //Initialize the array
    filAray(array,SIZE);
    
    //Output initial array
    prntAry(array,SIZE,20);
    
    //Process the inputs
    markSrt(array,SIZE);
    
    //Output the results
    prntAry(array,SIZE,20);

    //Test the search routine
    int value=rand()%90+10;
    int start=0,end=SIZE;
    int pos=binSrch(array,start,end,value);
    
    cout<<value<<" was found at "<<pos<<endl;
    cout<<value<<" was found "<<cntDup(array,SIZE,value)<<" times"<<endl;
    cout<<"Beginning Range = "<<start<<endl;
    cout<<"Ending Range    = "<<end<<endl;
    //Exit Stage Right!
    return 0;
}

/******************************************************
 *                   Binary Search                    *
 ******************************************************
 * Purpose: To find where a value resides
 * Input:
 *      a -> integer array
 *      val->The value to search for
 * Input-Output:
 *      first -> starting position for the search
 *      last  -> ending position for the search
 * Output:
 *      position where val was found
 ******************************************************/
int binSrch(int a[],int &first,int &last,int val){
    //loop to find first occurrence
    do{
        //Declare and initialize middle
        int middle=(first+last)/2;
        if(a[middle]==val)     return middle;
        else if(val<a[middle]) last=middle-1;
        else                   first=middle+1;
    }while(first<last);
    //Exit routine
    return -1;
}

/******************************************************
 *                  Count Duplicates                  *
 ******************************************************
 * Purpose: To find the number of occurrences of
 *          the value in the array
 * Input:
 *      n -> size of the array/list
 *      a -> integer array
 *      val->The value to search for
 * Output:
 *      How many times val was found
 ******************************************************/
int cntDup(int a[],int n,int val){
    //declare variables
    int count=0,
        pos=-1;
    
    //Find the number of occurrences
    do{
        pos=linSrch(a,n,++pos,val);
        count++;
    }while(pos>=0);
    
    //Return the output
    return --count;
}

/******************************************************
 *                   Linear Search                    *
 ******************************************************
 * Purpose: To find where a value resides
 * Input:
 *      n -> size of the array/list
 *      a -> integer array
 *      val->The value to search for
 *      strt-> Where to start the search
 * Output:
 *      position where val was found
 ******************************************************/
int linSrch(int a[],int n,int strt,int val){
    //loop until value is found
    for(int i=strt;i<n;i++){
        //report back if found
        if(a[i]==val) return i;
    }
    //if not found, then use sentinel
    return -1;
}

/******************************************************
 *                     Mark Sort                      *
 ******************************************************
 * Purpose: To sort any integer array
 * Input:
 *      n -> size of the array/list
 *  * Input-Output:
 *      a -> The sorted integer array
 * Output:
 ******************************************************/
void markSrt(int a[],int n){
    //Loop and sort of every position
    for(int pos=0;pos<n-1;pos++){
        swapMin(a,n,pos);
    }
}

/******************************************************
 *                    Swap Minimum                    *
 ******************************************************
 * Purpose: To place the minimum at the top of the list
 * Input:
 *      n -> size of the array/list
 *      pos -> position to place the minimum
 *  * Input-Output:
 *      a -> an integer array/list
 * Output:
 ******************************************************/
void swapMin(int a[],int n,int pos){
    //loop through the list starting at pos+1
    for(int i=pos+1;i<n;i++){
        //place the smallest value at the position pos
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

/******************************************************
 *                       Swap                         *
 ******************************************************
 * Purpose: To swap by logical operations two values
 * Input-Output:
 *      a -> an integer value
 *      b -> an integer value
 * Output:
 ******************************************************/
void swap(int &a,int &b){
    //Perform the logical in-place swap
    a=a^b;
    b=a^b;
    a=a^b;
}

/******************************************************
 *                    Print Array                     *
 ******************************************************
 * Purpose: To print an integer array with any number
 *          of columns
 * Input:
 *      n -> size of the array
 *      a -> integer array
 *      nCols -> number of columns to display the array
 * Output:
 *      On Screen
 ******************************************************/
void prntAry(const int a[],int n,int nCols){

    //loop and output every element in the array
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        //When column is reached, go to next line
        if((i%nCols)==(nCols-1)){
            cout<<endl;
        }
    }
            //Separate outputs with a line
        cout<<endl;
}

/******************************************************
 *                     Fill Array                     *
 ******************************************************
 * Purpose: To fill an array with 2-digit integer
 *          random numbers
 * Input:
 *      n -> size of the array
 * Input-Output:
 *      a -> integer array
 * Output:
 ******************************************************/
void filAray(int a[],int n){
    //loop on every element and equate to 2 digits
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}