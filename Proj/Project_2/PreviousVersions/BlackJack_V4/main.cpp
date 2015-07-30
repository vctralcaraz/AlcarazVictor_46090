/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 20, 2015, 6:49 PM
 * Purpose: Play Black Jack
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int gtUCard(string [],string []);
int gtDCard(string [],string []);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    bool nxtCard,  //next card boolean
         nxtGame;  //next game boolean
    char uChoice,  //user choice
         dChoice;  //dealer hits
    int  uWins=0,   //Player wins total
         dWins=0,   //Dealer wins total
         game,      //number of games
         minBet=25; //minimum bet for the table
    unsigned int money=1000;//user money
    
    //initialize array of card faces and array of suits
    const int SUITS=4,  //number of suits in a deck of cards
              FACES=13, //number of faces in a deck of cards
              CARD=52;  //number of cards per player hand
    string suit[SUITS]={"H","S","D","C"},
           face[CARD]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    int values[CARD]={1,2,3,4,5,6,7,8,9,10};
    
    //set random number seed
    srand(time(0));
    
    //user input number of games
    cout<<"Welcome to Black Jack!"<<endl<<endl<<"You will go against the dealer in this 1 on 1 venture"<<endl<<endl;
    cout<<"You will start with $1000 and betting will be a factor in the game."<<endl;
    cout<<"The minimum bet for the table is $25"<<endl<<endl;
    
    do{
        //complete games play again?
        int uTotal=0,  //card totals for user
            dTotal=0,  //card totals for dealer
            dCard,     //dealer card
            uCard,     //user card
            bet=0;     //user bet

        do{
        //betting
        cout<<"What is your bet?"<<endl;
        cout<<"Cash = $"<<money<<endl<<"Minimum Bet = $"<<minBet<<endl;
        cin>>bet;
        cout<<endl;
        if(bet<25) cout<<"Minimum bet is $"<<minBet<<endl;
        if(bet>money) cout<<"You can't bet more than what you have"<<endl;
        }while(bet<25 || bet>money);
        money-=bet;
        cout<<endl;

        //dealer card
        cout<<endl;
        dCard=gtDCard(suit,face);
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
            uCard=gtUCard(suit,face);
            if(uCard==1){
                if(uTotal>=11){
                    uTotal+=1;
                }else{
                    uTotal+=11;
                }
            }else{
                uTotal+=uCard;
            }
            cout<<"Cash         = "<<money<<endl;
            cout<<"Your Bet     = "<<bet<<endl;
            cout<<"Your Total   = "<<uTotal<<endl;
            cout<<"Dealer Total = "<<dTotal<<endl<<endl;

            if(uTotal>=21){
                nxtCard=false;
                if(uTotal>21){
                    cout<<"You busted over 21. You lost $"<<bet<<endl<<endl;
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
                dCard=gtDCard(suit,face);
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
                        cout<<"The Dealer has busted! You won $"<<bet*2<<endl;
                        uWins++;
                        money+=bet*2;
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
            money+=bet*2;
            cout<<"You beat the dealer!"<<endl<<"You won $"<<bet*2<<endl;
            uWins++;
        }else if(dTotal>uTotal && dTotal<22){
            cout<<"Dealer wins!"<<endl<<endl;
            dWins++;
        }else if(dTotal==uTotal){
            cout<<"Push"<<endl<<"You retained your bet of $"<<bet<<endl;
            money+=bet;
        }

        //display wins and losses
        cout<<"Cash        = "<<money<<endl;
        cout<<"Your wins   = "<<uWins<<endl;
        cout<<"Dealer wins = "<<dWins<<endl<<endl;
        cout<<"Press Enter to continue"<<endl;
        cin.get();
        cin.ignore();
    }while(money>minBet);
    
    cout<<"Thanks for your contribution to the casino."<<endl;
    cout<<"Have a great day!"<<endl;
    
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
int gtDCard(string s[],string n[]){
    //Declare Variables
    int faceVal;
    string suit,
           number;
    
    //Set random card
    int sNum=rand()%4+1;
    int cNum=rand()%13+1;
    
    switch(sNum){
        case 1: suit=s[0];break;
        case 2: suit=s[1];break;
        case 3: suit=s[2];break;
        case 4: suit=s[3];break;
        default: cout<<"No Card"<<endl;
    }

    switch(cNum){
        case 1:{
            cout<<"Dealer got an ace! That becomes a 1 or 11."<<endl;
            number=n[0];
            faceVal=1;
            break;
        }
        case 2:{
            number=n[1];
            faceVal=2;
            break;
        }
        case 3:{
            number=n[2];
            faceVal=3;
            break;
        }
        case 4:{
            number=n[3];
            faceVal=4;
            break;
        }
        case 5:{
            number=n[4];
            faceVal=5;
            break;
        }
        case 6:{
            number=n[5];
            faceVal=6;
            break;
        }
        case 7:{
            number=n[6];
            faceVal=7;
            break;
        }
        case 8:{
            number=n[7];
            faceVal=8;
            break;
        }
        case 9:{
            number=n[8];
            faceVal=9;
            break;
        }
        case 10:{
            number=n[9];
            faceVal=10;
            break;
        }
        case 11:{
            number=n[10];
            faceVal=10;
            break;
        }
        case 12:{
            number=n[11];
            faceVal=10;
            break;
        }
        case 13:{
            number=n[12];
            faceVal=10;
            break;
        }
        default: cout<<"No Card"<<endl;
    }
    
    cout<<"Dealer card:"<<endl;
    if(faceVal==1){
        cout<<number<<suit<<" = 1 or 11"<<endl<<endl;
    }else{
        cout<<number<<suit<<" = "<<faceVal<<endl<<endl;
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
int gtUCard(string s[],string n[]){
    //Declare Variables
    int faceVal;
    string number,
           suit;
    
    //Set random card
    int sNum=rand()%4+1;
    int cNum=rand()%13+1;
    
    switch(sNum){
        case 1: suit=s[0];break;
        case 2: suit=s[1];break;
        case 3: suit=s[2];break;
        case 4: suit=s[3];break;
        default: cout<<"No Card"<<endl;
    }

    switch(cNum){
        case 1:{
            cout<<"You got an ace! That becomes a 1 or 11."<<endl;
            number=n[0];
            faceVal=1;
            break;
        }
        case 2:{
            number=n[1];
            faceVal=2;
            break;
        }
        case 3:{
            number=n[2];
            faceVal=3;
            break;
        }
        case 4:{
            number=n[3];
            faceVal=4;
            break;
        }
        case 5:{
            number=n[4];
            faceVal=5;
            break;
        }
        case 6:{
            number=n[5];
            faceVal=6;
            break;
        }
        case 7:{
            number=n[6];
            faceVal=7;
            break;
        }
        case 8:{
            number=n[7];
            faceVal=8;
            break;
        }
        case 9:{
            number=n[8];
            faceVal=9;
            break;
        }
        case 10:{
            number=n[9];
            faceVal=10;
            break;
        }
        case 11:{
            number=n[10];
            faceVal=10;
            break;
        }
        case 12:{
            number=n[11];
            faceVal=10;
            break;
        }
        case 13:{
            number=n[12];
            faceVal=10;
            break;
        }
        default: cout<<"No Card"<<endl;
    }
    
    cout<<"Your Card: "<<endl;
    if(faceVal==1){
        cout<<number<<suit<<" = 1 or 11"<<endl<<endl;
    }else{
        cout<<number<<suit<<" = "<<faceVal<<endl<<endl;
    }
    return faceVal;
}
