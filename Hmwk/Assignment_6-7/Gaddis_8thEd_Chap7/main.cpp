/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 21, 2015, 12:41 PM
 * Purpose: Chapter 7 Gaddis Problems
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
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
void ftion(int [],int,int);

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
    cout<<"Problem #1: Largest/Smallest Array Values"<<endl<<endl;
    
    //initialize the array
    const int SIZE=10; //size of the array
    int array[SIZE];   //integer array
    
    //declare variables
    int min,   //smallest value
        max;   //largest value
    
    //user input numbers into the array
    cout<<"Enter "<<SIZE<<" numbers"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"Number "<<i+1<<endl;
        cin>>array[i];
    }
    
    //find the smallest and largest
    min=array[0];
    max=array[0];
    for(int j=0;j<SIZE;j++){
        if(array[j]<=min){
                min=array[j];
            }
        if(array[j]>=max){
                max=array[j];
            }
    }
    
    //output the results
    cout<<endl<<"The smallest number of the ones you entered is "<<min<<endl;
    cout<<"The largest number of the ones you entered is "<<max<<endl<<endl;
}

//Solution to problem 2
void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    cout<<"Problem #2: Rainfall Statistics"<<endl<<endl;
    
    //initialize array
    const int SIZE=12;
    float array[SIZE];
    
    //define variables
    float min,  //smallest value
          max,  //largest value
          sum=0,  //sum of all values
          avg;  //average of all values
    
    //user input of rainfall per month in inches
    cout<<"Enter the amount of rainfall in inches per month for "<<SIZE<<" months"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"Month number "<<i+1<<endl;
        cin>>array[i];
    }
    
    //find the smallest and largest
    min=array[0];
    max=array[0];
    for(int j=0;j<SIZE;j++){
        if(array[j]<=min){
                min=array[j];
            }
        if(array[j]>=max){
                max=array[j];
            }
    }
    
    //find sum and average
    for(int k=0;k<SIZE;k++){
        sum+=array[k];
    }
    avg=sum/SIZE;
    
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Rainfall for the year is "<<sum<<" inches"<<endl;
    cout<<"Average rainfall for the year is "<<avg<<" inches"<<endl;
    cout<<"Max rainfall in any month is "<<max<<" inches"<<endl;
    cout<<"Min rainfall in any month is "<<min<<" inches"<<endl<<endl;
}

//Solution to problem 3
void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    cout<<"Problem #3: Chips And Salsa"<<endl<<endl;
    
    const int SIZE=5;
    string salsa[SIZE]{"Mild","Medium","Sweet","Hot","Zesty"};
    int jars[SIZE];
    
    for(int i=0;i<SIZE;i++){
        cout<<"How many jars of "<<salsa[i]<<" was sold last month?"<<endl;
        cin>>jars[i];
    }
    
    //declare variables
    int min=jars[0],  //minimum value of jars sold
        max=jars[0],  //maximum value of jars sold
        posMin,       //position of minium in array
        posMax,       //position of maximum in array
        sum=0;        //sum of all jars sold
    
    //find the smallest and largest
    for(int j=0;j<SIZE;j++){
        if(jars[j]<=min){
                min=jars[j];
                posMin=j;
        }
        if(jars[j]>=max){
                max=jars[j];
                posMax=j;
        }
    }
    
    //output the results
    cout<<endl<<"Last Months Numbers:"<<endl;
    for(int k=0;k<SIZE;k++){
        cout<<"Jars of "<<salsa[k]<<" = "<<jars[k]<<endl;
        
        //add sum of all jars
        sum+=jars[k];
    }
    cout<<"Total jars = "<<sum<<endl;
    cout<<"The minimum of any salsa sold was "<<salsa[posMin]<<endl;
    cout<<"The maximum of any salsa sold was "<<salsa[posMax]<<endl<<endl;
}

//Solution to problem 4
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    cout<<"Problem #4: Larger than n"<<endl<<endl;
    
    //initilize array
    const int SIZE=10;
    int array[SIZE]{7,100,68,4,11,22,53,88,15,72};
    
    //declare variables
    int number;
    
    //user input
    cout<<"Enter a number between 1 and 100"<<endl;
    cin>>number;
    
    //call function
    ftion(array,SIZE,number);
}

//Solution to problem 5
void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    cout<<"Problem #5: Monkey Business"<<endl<<endl;
    
    //initialize array
    const int ROWS=3,
              COLS=5;
    int foodEat[ROWS][COLS];
    
    //define variables
    float sum=0,  //sum of all food eaten
          avg,    //average of all food eaten
          min=100,  //minimum of any food eaten
          max=0;  //maximum of any food eaten
    
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            cout<<"Monkey "<<i+1;
            cout<<",  Amount fed Day "<<j+1<<": ";
            cin>>foodEat[i][j];
        }
        cout<<endl;
    }
    
    //sum all food eaten
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            sum+=foodEat[i][j];
        }
    }
    
    //average of food eaten
    avg=sum/COLS;
    
    //find the smallest and largest
    int minpRow,  //position of minimum row
        minpCol,  //position of minimum column
        maxpRow,  //position of maximum row
        maxpCol;  //position of maximum column
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(foodEat[i][j]<=min){
                    min=foodEat[i][j];
                    minpRow=i;
                    minpCol=j;
            }
            if(foodEat[i][j]>=max){
                    max=foodEat[i][j];
                    maxpRow=i;
                    maxpCol=j;
            }
        }
    }
    
    //display results
    cout<<endl;
    cout<<"Average food eaten per day = "<<avg<<" lbs"<<endl;
    cout<<"Minimum pounds of food eaten by any Monkey = "<<foodEat[minpRow][minpCol]<<" lbs"<<endl;
    cout<<"Maximum pounds of food eaten by any Monkey = "<<foodEat[maxpRow][maxpCol]<<" lbs"<<endl<<endl;
}

//Solution to problem 6
void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    cout<<"Problem #12: Grade Book"<<endl<<endl;
    
    //initialize the array
    const int STUDENT=5,  //number of students
              GRADES=5,   //number of letter grades
              SCORES=4;   //number of test scores
    string names[STUDENT];//array of student names
    char letGrad[GRADES]={'F','D','C','B','A'}; //array of letter grades
    float stuScre[STUDENT][SCORES];
    float sumStu[STUDENT];
    
    //declare variables
    float avg;  //average of each test score per student
    
    //write student names and scores
    for(int i=0;i<STUDENT;i++){
        int sum=0;
        cout<<"Enter name of student "<<i+1<<": ";
        cin>>names[i];
        for(int j=0;j<SCORES;j++){
            do{
            cout<<names[i]<<": Score "<<j+1<<": ";
            cin>>stuScre[i][j];
            if(stuScre[i][j]==0){
                    cout<<"You got a zero?!?!?! Get a life!"<<endl;
                }
            if(stuScre[i][j]<0 || stuScre[i][j]>100){
                cout<<"A test score cannot be less than 0 or greater than 100"<<endl<<endl;
            }
            }while(stuScre[i][j]<0 || stuScre[i][j]>100);
            sum+=stuScre[i][j];
        }
        sumStu[i]=sum;
    }
    cout<<endl;
    
    //output letter grade
    for(int i=0;i<STUDENT;i++){
        avg=sumStu[i]/4;
        cout<<names[i]<<"'s Grade: ";
        if(avg>=90) cout<<"Average: "<<avg<<"% "<<letGrad[4]<<endl;
        else if(avg>=80) cout<<"Average: "<<avg<<"% "<<letGrad[3]<<endl;
        else if(avg>=70) cout<<"Average: "<<avg<<"% "<<letGrad[2]<<endl;
        else if(avg>=60) cout<<"Average: "<<avg<<"% "<<letGrad[1]<<endl;
        else cout<<"Average: "<<avg<<"% "<<letGrad[0]<<endl;
    }
    cout<<endl;
}

//Solution to problem 7
void problem7(){
    cout<<"In problem # 7"<<endl<<endl;
    cout<<"Problem #13: Grade Book Modification"<<endl<<endl;
    
    //initialize the array
    const int STUDENT=5,  //number of students
              GRADES=5,   //number of letter grades
              SCORES=4;   //number of test scores
    string names[STUDENT];//array of student names
    char letGrad[GRADES]={'F','D','C','B','A'}; //array of letter grades
    float stuScre[STUDENT][SCORES];
    float sumStu[STUDENT];
    
    //declare variables
    float avg;      //average of each test score per student
    int   min=100;  //minimum score
    
    //write student names and scores
    for(int i=0;i<STUDENT;i++){
        int sum=0;
        cout<<"Enter name of student "<<i+1<<": ";
        cin>>names[i];
        for(int j=0;j<SCORES;j++){
            do{
            cout<<names[i]<<": Score "<<j+1<<": ";
            cin>>stuScre[i][j];
            if(stuScre[i][j]<min){
                min=stuScre[i][j];
            }
            if(stuScre[i][j]==0){
                    cout<<"You got a zero?!?!?! Get a life!"<<endl;
                }
            if(stuScre[i][j]<0 || stuScre[i][j]>100){
                cout<<"A test score cannot be less than 0 or greater than 100"<<endl<<endl;
            }
            }while(stuScre[i][j]<0 || stuScre[i][j]>100);
            sum+=stuScre[i][j];
        }
        sum-=min;
        sumStu[i]=sum;
    }
    cout<<endl;
    
    //output letter grade
    for(int i=0;i<STUDENT;i++){
        avg=sumStu[i]/3;
        cout<<names[i]<<"'s Grade with lowest test score dropped: ";
        if(avg>=90) cout<<"Average: "<<avg<<"% "<<letGrad[4]<<endl;
        else if(avg>=80) cout<<"Average: "<<avg<<"% "<<letGrad[3]<<endl;
        else if(avg>=70) cout<<"Average: "<<avg<<"% "<<letGrad[2]<<endl;
        else if(avg>=60) cout<<"Average: "<<avg<<"% "<<letGrad[1]<<endl;
        else cout<<"Average: "<<avg<<"% "<<letGrad[0]<<endl;
    }
    cout<<endl;
}

//Exit Comment
void def(int inN){
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void ftion(int a[],int s,int n){
    cout<<endl<<"numbers larger than the number you put in are:"<<endl;
    for(int i=0;i<s;i++){
        if(a[i]>n){
            cout<<a[i]<<" ";
        }
    }
    cout<<endl<<endl;
}