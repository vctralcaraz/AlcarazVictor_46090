/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 16, 2015, 11:24 AM
 * Purpose: To calculate the mean and standard deviation
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
const double MXRND=pow(2,31)-1;

//Function Prototypes
float normal();
void filAray(float [],int);
void prntAry(const float [],int,int);
float max(float [],int);
float min(float [],int);
float mean(float [],int);
float stdev(float [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=500000;
    float array[SIZE];
    
    //initialize array
    filAray(array,SIZE);
    
    //output the initial array
    //prntAry(array,SIZE,5);
    
    //Print the statistics
    cout<<"The max value of the array = "<<max(array,SIZE)<<endl;
    cout<<"The min value of the array = "<<min(array,SIZE)<<endl;
    cout<<"The mean value of the array = "<<mean(array,SIZE)<<endl;
    cout<<"The standard deviation in the array = "<<stdev(array,SIZE)<<endl;
    
    //Exit stage right!
    return 0;
}

/**********************************************
 *       Standard Deviation of the Array      *
 **********************************************
 * Purpose: To find the standard deviation
 * Input:
 *      n-> the size of the array
 *      a-> the float array
 * Output:
 *      standard deviation
 **********************************************/
float stdev(float a[],int n){
    //Declare and initialize variables
    float std=0,avg=mean(a,n);
    //loop to find the 
    for(int i=0;i<n;i++){
        float amavg=(a[i]-avg);
        std+=amavg*amavg;
        //std+=(a[i]-mean(a,n)*a[i]-mean(a,n));
    }
    //return value
    return sqrt(std/(n-1));
}

/**********************************************
 *              Mean of the Array             *
 **********************************************
 * Purpose: To find the mean
 * Input:
 *      n-> the size of the array
 *      a-> the float array
 * Output:
 *      mean value
 **********************************************/
float mean(float a[],int n){
    //Declare and initialize variables
    float mean=0;
    //loop to find the
    for(int i=0;i<n;i++){
        mean+=a[i];
    }
    //return value
    return mean/n;
}

/**********************************************
 *               Max of the Array             *
 **********************************************
 * Purpose: To find the maximum
 * Input:
 *      n-> the size of the array
 *      a-> the float array
 * Output:
 *      maximum value
 **********************************************/
float max(float a[],int n){
    //Declare and initialize variables
    float max=a[0];
    //loop to find the
    for(int i=1;i<n;i++){
        if(max<a[i])max=a[i];
    }
    //return value
    return max;
}

/**********************************************
 *               Min of the Array             *
 **********************************************
 * Purpose: To find the minimum
 * Input:
 *      n-> the size of the array
 *      a-> the float array
 * Output:
 *      minimum value
 **********************************************/
float min(float a[],int n){
    //Declare and initialize variables
    float min=a[0];
    //loop to find the
    for(int i=1;i<n;i++){
        if(min>a[i])min=a[i];
    }
    //return value
    return min;
}

/**********************************************
 *      Normal Distribution Approximation     *
 **********************************************
 * Purpose:
 * Output:
 *      Normal density function approximation
 **********************************************/
void prntAry(const float a[],int n,int nCols){
    //format
    cout<<fixed<<showpoint<<setprecision(4);
    
    cout<<endl;
    //loop and output every element in the array
    for(int i=0;i<n;i++){
        cout<<setw(8)<<a[i];
        //When column is reached go to next line
        if((i%nCols)==(nCols-1))cout<<endl;
    }
    //separate outputs
    cout<<endl;
}

/**********************************************
 *      Normal Distribution Approximation     *
 **********************************************
 * Purpose:
 * Output:
 *      Normal density function approximation
 **********************************************/
void filAray(float a[],int n){
    for(int i=0;i<n;i++){
        a[i]=normal();
    }
}

/**********************************************
 *      Normal Distribution Approximation     *
 **********************************************
 * Purpose:
 * Output:
 *      Normal density function approximation
 **********************************************/
float normal(){
    //delcare variables
    float norm=0; //[-6,6]
    //loop 12 times
    for(int i=1;i<=12;i++){
        norm+=(rand()/MXRND-0.5); //[-0.5,0.5]
    }
    return norm;
}