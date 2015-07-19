/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 16, 2015, 12:35 AM
 * Purpose: To eventually play blackjack
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    string suit,  //The suit of a card (spade,club,diamond,heart)
           number;//number card (2-10)
    int    cNum,  //card number
           sNum,  //suit number
           faceVal;//face value of a card
    
    //set random number seed
    srand(time(0));
    
    //Set random card
    sNum=rand()%4+1;
    cNum=rand()%13+1;
    
    //Test Card
    if(sNum==1){
        suit = "Hearts";
    }else if(sNum==2){
        suit = "Diamonds";
    }else if(sNum==3){
        suit = "Spades";
    }else {
        suit = "Clubs";
    }
    
    if(cNum==1){
        number = "Ace";
    }else if(cNum==2){
        number = "Two";
    }else if(cNum==3){
        number = "Three";
    }else if(cNum==4){
        number = "Four";
    }else if(cNum==5){
        number = "Five";
    }else if(cNum==6){
        number = "Six";
    }else if(cNum==7){
        number = "Seven";
    }else if(cNum==8){
        number = "Eight";
    }else if(cNum==9){
        number = "Nine";
    }else if(cNum==10){
        number = "Ten";
    }else if(cNum==11){
        number = "Jack";
    }else if(cNum==12){
        number = "Queen";
    }else {
        number = "King";
    }
    if(cNum==1){
        faceVal = 1||11;
    }else if(cNum==2){
        faceVal = 2;
    }else if(cNum==3){
        faceVal = 3;
    }else if(cNum==4){
        faceVal = 4;
    }else if(cNum==5){
        faceVal = 5;
    }else if(cNum==6){
        faceVal = 6;
    }else if(cNum==7){
        faceVal = 7;
    }else if(cNum==8){
        faceVal = 8;
    }else if(cNum==9){
        faceVal = 9;
    }else if(cNum==10){
        faceVal = 10;
    }else if(cNum==11){
        faceVal = 10;
    }else if(cNum==12){
        faceVal = 10;
    }else {
        faceVal = 10;
    }
    
    cout<<number<<" of "<<suit<<" = "<<faceVal<<endl;
    
    
    
    //Exit Stage Right!
    return 0;
}

