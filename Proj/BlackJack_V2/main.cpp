/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 19, 2015, 11:25 AM
 * Purpose: To Play BlackJack against the CPU
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int gtUCard();
int gtDCard();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    bool nxtCard,  //next card boolean
         nxtGame;  //next game boolean
    char uChoice,  //user choice
         dChoice;  //dealer hits
    int  uWins=0,   //Player wins total
         dWins=0,   //Dealer wins total
         game;      //number of games
    
    //set random number seed
    srand(time(0));
    
    //user input number of games
    cout<<"How many games do you want to play?"<<endl;
    cin>>game;
    cout<<endl;
    
    //complete games play again?
    for(int i=1;i<=game;i++){
    //do{
        int uTotal=0,  //card totals for user
            dTotal=0,  //card totals for dealer
            dCard,     //dealer card
            uCard;     //user card
        
        //number game
        cout<<endl<<"Game Number "<<i<<endl;
        
        //dealer card
        cout<<endl;
        dCard=gtDCard();
        if(dCard==1){
            if(dTotal>=11){
                dTotal+=1;
            }else{
                dTotal+=11;
            }
        }else{
                dTotal+=dCard;
        }
    
        //loop to get card totals
        do{
            uCard=gtUCard();
            if(uCard==1){
                if(uTotal>=11){
                    uTotal+=1;
                }else{
                    uTotal+=11;
                }
            }else{
                uTotal+=uCard;
            }
            
            cout<<"Your Total   = "<<uTotal<<endl;
            cout<<"Dealer Total = "<<dTotal<<endl<<endl;

            if(uTotal>=21){
                nxtCard=false;
                if(uTotal>21){
                    cout<<"You busted over 21. You lose."<<endl<<endl;
                    dWins++;
                }
            }else{

                //validation and hit or stand call for player
                do{
                    cout<<"Hit [H] or Stand [S]"<<endl;
                    cin>>uChoice;
                    cout<<endl;
                    if(uChoice!='s' && uChoice!='S' && uChoice!='H' && uChoice!='h'){
                    cout<<"You did not put an 'H' or an 'S'"<<endl;
                    }
                }while(uChoice!='s' && uChoice!='S' && uChoice!='H' && uChoice!='h');

                if(uChoice=='S' || uChoice=='s'){
                    nxtCard=false;
                }else{
                    nxtCard=true;
                }
            }
        }while(nxtCard==true);

        //dealer totals
        do{
            //validation if user busted, skip dealer
            if(uTotal>21){
                nxtCard=false;
            }else{
                //dealer card totals
                dCard=gtDCard();
                if(dCard==1){
                        if(dTotal>=11){
                                dTotal+=1;
                        }else{
                                dTotal+=11;
                        }
                }else{
                        dTotal+=dCard;
                }
                cout<<"Your Total   = "<<uTotal<<endl;
                cout<<"Dealer Total = "<<dTotal<<endl<<endl;
                //dealer stays on 17-21
                if(dTotal>=17){
                    nxtCard=false;
                    //dealer busts over 21
                    if(dTotal>21){
                        cout<<"The Dealer has busted! You win!"<<endl;
                        uWins++;
                    }
                }else{
                    //validation to continue
                    do{
                        cout<<"Press [D] to continue"<<endl;
                        cin>>dChoice;
                        if(dChoice!='D' && dChoice!='d'){
                            cout<<"You did not hit [D]"<<endl<<endl;
                        }
                    }while(dChoice!='D' && dChoice!='d');
                    nxtCard=true;
                }
            }
        }while(nxtCard==true);
        //calculating win, loss, or push
        if(uTotal>dTotal && uTotal<22){
            cout<<"You beat the dealer!"<<endl<<endl;
            uWins++;
        }else if(dTotal>uTotal && dTotal<22){
            cout<<"Dealer wins!"<<endl<<endl;
            dWins++;
        }else if(dTotal==uTotal){
            cout<<"Push"<<endl<<endl;
            i--;
        }
        
        //display wins and losses
        cout<<"Your wins   = "<<uWins<<endl;
        cout<<"Dealer wins = "<<dWins<<endl<<endl;
        
        if(i==game){
            cout<<"Thanks for playing!"<<endl;
        }
        cout<<"Press any letter to continue"<<endl;
        cin>>uChoice;
    }
    
    //Exit Stage Right!
    return 0;
}

/*************************************************
 *                 get Dealer card                 *
 *************************************************
 * Purpose: To get cards from random numbers for
 *          the dealer
 * Output:
 *      random card(random suit and random 
 *                  face care/number)
 *************************************************/
int gtDCard(){
    //Declare Variables
    int faceVal;
    string number,
           suit;
    
    //Set random card
    int sNum=rand()%4+1;
    int cNum=rand()%13+1;
    
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
        cout<<"Dealer got an ace! That is a 1 or 11"<<endl;
        faceVal=1;
    }else if(cNum==2){
        number = "Two";
        faceVal=2;
    }else if(cNum==3){
        number = "Three";
        faceVal=3;
    }else if(cNum==4){
        number = "Four";
        faceVal=4;
    }else if(cNum==5){
        number = "Five";
        faceVal=5;
    }else if(cNum==6){
        number = "Six";
        faceVal=6;
    }else if(cNum==7){
        number = "Seven";
        faceVal=7;
    }else if(cNum==8){
        number = "Eight";
        faceVal=8;
    }else if(cNum==9){
        number = "Nine";
        faceVal=9;
    }else if(cNum==10){
        number = "Ten";
        faceVal=10;
    }else if(cNum==11){
        number = "Jack";
        faceVal=10;
    }else if(cNum==12){
        number = "Queen";
        faceVal=10;
    }else {
        number = "King";
        faceVal=10;
    }
    cout<<"Dealer card:"<<endl;
    if(faceVal==1){
        cout<<number<<" of "<<suit<<" = 1 or 11"<<endl<<endl;
    }else{
        cout<<number<<" of "<<suit<<" = "<<faceVal<<endl<<endl;
    }
    return faceVal;
}

/*************************************************
 *                 get User card                 *
 *************************************************
 * Purpose: To get cards from random numbers for
 *          the user
 * Output:
 *      random card(random suit and random 
 *                  face care/number)
 *************************************************/
int gtUCard(){
    //Declare Variables
    int faceVal;
    string number,
           suit;
    
    //Set random card
    int sNum=rand()%4+1;
    int cNum=rand()%13+1;
    
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
        cout<<"You got an ace! That is a 1 or 11"<<endl;
        faceVal=1;
    }else if(cNum==2){
        number = "Two";
        faceVal=2;
    }else if(cNum==3){
        number = "Three";
        faceVal=3;
    }else if(cNum==4){
        number = "Four";
        faceVal=4;
    }else if(cNum==5){
        number = "Five";
        faceVal=5;
    }else if(cNum==6){
        number = "Six";
        faceVal=6;
    }else if(cNum==7){
        number = "Seven";
        faceVal=7;
    }else if(cNum==8){
        number = "Eight";
        faceVal=8;
    }else if(cNum==9){
        number = "Nine";
        faceVal=9;
    }else if(cNum==10){
        number = "Ten";
        faceVal=10;
    }else if(cNum==11){
        number = "Jack";
        faceVal=10;
    }else if(cNum==12){
        number = "Queen";
        faceVal=10;
    }else {
        number = "King";
        faceVal=10;
    }
    
    cout<<"Your Card: "<<endl;
    if(faceVal==1){
        cout<<number<<" of "<<suit<<" = 1 or 11"<<endl<<endl;
    }else{
        cout<<number<<" of "<<suit<<" = "<<faceVal<<endl<<endl;
    }
    return faceVal;
}