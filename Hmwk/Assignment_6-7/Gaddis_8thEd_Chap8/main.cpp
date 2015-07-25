/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 23, 2015, 2:34 PM
 * Purpose: Homework Gaddis Chapter 8
 */

//System Libraries
#include <iostream>
#include <iomanip>
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
void output(unsigned short []);
void display(unsigned short &,unsigned short &,unsigned short []);
int listSer(const int [], int, int);
int bSearch(const int [], int, int);

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
    cout<<"Problem #1: Charge Account Validation"<<endl<<endl;
    
    //initialize array
    const int SIZE=18;
    unsigned int account[SIZE]={5658845,4520125,7895122,8777541,
                                8451277,1302850,8080152,4562555,
                                5552012,5050552,7825877,1250255,
                                1005231,6545231,3852085,7576651,
                                7881200,4581002};
    
    //declare variables
    unsigned int number;
    bool found=false;
    
    //number input
    cout<<"Enter account number: ";
    cin>>number;
    
    for(int i=0;i<SIZE;i++){
        if(account[i]==number){
            cout<<number<<" was valid"<<endl;
            found=true;
        }
    }
    if(!found){
        cout<<number<<" is invalid"<<endl<<endl;
    }

}

//Solution to problem 2
void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    cout<<"Problem #2: Lottery Winners"<<endl<<endl;
    
    const int SIZE=10;
    int winNum[SIZE]={13579,26791,26792,33445,55555,
                      62483,77777,79422,85647,93121},
        playNum[SIZE];
    
    //input lucky numbers
    cout<<"Enter your 10 lucky 5-digit numbers"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"Number "<<i+1<<": ";
        cin>>playNum[i];
    }
    
    bool found=false;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(playNum[i]==winNum[j]){
                cout<<playNum[i]<<" is a winning number!"<<endl;
                found=true;
            }
        }
    }
    if(!found){
        cout<<"You did not enter a winning number. Maybe next time."<<endl<<endl;
    }
}

//Solution to problem 3
void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    cout<<"Savitch Chapter 7 Problem #10: Tic-Tac-Toe"<<endl<<endl;
    
    //Declare Variables
    const char SIZE=9;
    unsigned short tic[SIZE]={1,2,3,4,5,6,7,8,9};
    unsigned short num, sNum;
    
    output(tic);
    
    //Prompt and input
    cout<<"To select a spot enter the number in which you wish to put an X or O\n";
    cout<<"Player 1 will be X and player 2 will be O\n";
    
    unsigned short tot=1;
    
    //Loop until board is filled
    do{
        
    cout<<"Player 1 your turn.\n";
    cin>>num;
    
    //To determine spot on the board 
    unsigned short rNum=num-1;
    tic[rNum]=63;
    
    display(num,sNum,tic);
    cout<<"Player 2 your turn.\n";
    cin>>sNum;
    
    //To determine spot on the board 
    unsigned short dNum=sNum-1;
    tic[dNum]=95;
    
    display(num,sNum,tic);
    tot++;
    
    }while(tot<5);
}

//Solution to problem 4
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    
     //Declare Variables Here
    int const SIZE = 20;     
    int lineSer;
    int binSer;
    int pin;
    int access[SIZE]={01, 12, 23, 34, 45, 56, 67, 78, 89, 90, 123, 234, 345, 456, 567, 678, 789, 890, 901, 1000};
        
        //Input valid pin number
    cout<<"Please enter a valid PIN Number: ";
    cin>>pin;
        
    cout<<"I will search for the PIN number using searchList function"<<endl;
    lineSer=listSer(access, SIZE, pin);
    if(lineSer==-1){
        cout<<"You did not enter a valid PIN number."<<endl;
    }else{
    cout<<"You entered a valid PIN number"<<endl;
    cout<<"I searched "<<(lineSer + 1)<<" numbers until I got to your number"<<endl;
    }
    cout<<"I will now search for the PIN number using the Binary search function."<<endl;
    binSer = bSearch(access, SIZE, pin);
    if(binSer==-1){
        cout<<"You have entered an invalid PIN number."<<endl;
    }else{
        cout<<"You have entered a valid PIN number."<<endl;
        cout<<"I searched "<<binSer<<" numbers until I got to your number"<<endl;
    }
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


/************************************************************************
 *                              output
 ************************************************************************
 * Purpose: Displays original table
 * Input-Output:
 *      tic->tic-tac-toe board
 */

void output(unsigned short tic[]){
    for(int i=0;i<=2;i++){
        cout<<tic[i]<<" ";
    }
    cout<<endl;
     for(int i=3;i<=5;i++){
        cout<<tic[i]<<" ";
    }
    cout<<endl;
     for(int i=6;i<=8;i++){
        cout<<tic[i]<<" ";
    }
    cout<<endl;
}

/************************************************************************
 *                              display
 ************************************************************************
 * Purpose: change display board by putting an X or an O
 * Input:
 *      rNum->the spot in the array that needs to be changed to an X
 *      dNum->the spot in the array that needs to be changed to an O
 * Input-Output:
 *      tic->tic-tac-toe board with modifications
 */

void display(unsigned short &rNum,unsigned short &dNum, unsigned short tic[]){
    
    for(int i=0;i<=2;i++){
        if(tic[i]==63){
             cout<<"X ";
        }else if(tic[i]==95){
            cout<<"O ";
        }else{
            cout<<tic[i]<<" ";
        }
    }
    cout<<endl;
    
    for(int i=3;i<=5;i++){
        if(tic[i]==63){
             cout<<"X ";
        }else if(tic[i]==95){
            cout<<"O ";
        }else{
        cout<<tic[i]<<" ";
        }
    }
    cout<<endl;
    
    for(int i=6;i<=8;i++){
        if(tic[i]==63){
             cout<<"X ";
        }else if(tic[i]==95){
            cout<<"O ";
        }else{
            cout<<tic[i]<<" ";
        }
    }
    cout<<endl;
     
}

int listSer(const int list[], int size, int value){
 int index=0,
        position= -1;
 bool found=false;
 while(index < size && !found){
  if(list[index]==value){
   found=true;
   position=index;
  }
  index++;
 }
 return position;
}
int bSearch(const int list[], int size, int value){
 int first = 0,
     last = size -1,
     middle,
     position = -1;
 
 bool found = false;
 while(!found && first <= last){
  middle = (first + last) / 2;
  if (list[middle] == value){
   found = true;
   position = middle;
  }else if (list[middle] > value)
   last = middle - 1;
   else
   first = middle +1;
 }
 return position;
}