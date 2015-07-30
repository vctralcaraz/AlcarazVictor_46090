/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 27, 2015, 4:07 PM
 * Purpose: play Black Jack / adding an array of 52 cards
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void gtDeck(int []);
void gtStrt(string [],int [],int [],int &,int &);
void split(string [],int [],int [],int &,int &,int &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //set random number seed
    srand(time(0));
    
    //initialize arrays
    const int CARDS=52; //number of cards
    int deck[CARDS]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
                     23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,
                     42,43,44,45,46,47,48,49,50,51}, //number cards
        shufDk[CARDS],  //shuffled deck
        value[CARDS]={1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,10,
                      10,1,2,3,4,5,6,7,8,9,10,10,10,10,1,2,3,4,5,6,7,8,9,10,10,
                      10,10},  // value of each number cards
        uCards[CARDS],  //user cards
        dCards[CARDS];  //dealer cards
    string faces[CARDS]={"A-H","2-H","3-H","4-H","5-H","6-H","7-H","8-H","9-H",
                         "10-H","J-H","Q-H","K-H","A-S","2-S","3-S","4-S","5-S",
                         "6-S","7-S","8-S","9-S","10-S","J-S","Q-S","K-S","A-D",
                         "2-D","3-D","4-D","5-D","6-D","7-D","8-D","9-D","10-D",
                         "J-D","Q-D","K-D","A-C","2-C","3-C","4-C","5-C","6-C",
                         "7-C","8-C","9-C","10-C","J-C","Q-C","K-C"};
    
    //Declare Variables
    int bet=0,     //user bet
                 minBet=25, //minimum bet in $'s
                 money=1000;//player starting money
    bool nxtCard=true,  //next card boolean
         bJack,         //if got black jack
         splitH;         //if split hand
    char uChoice,  //player input of hit/stand/double down/split
         dDown,    //Double Down Input
         splitDc;
    
    //Welcome and explanation
    cout<<"Welcome to the game of Black Jack"<<endl<<endl;
    cout<<"You will be going against the Dealer alone for now"<<endl<<endl;
    cout<<"  H = Hearts"<<endl<<"  S = Spades"<<endl<<"  D = Diamonds"<<endl<<"  C = Clubs"<<endl<<endl;
    cout<<"You will start off with $"<<money<<" with the table"<<endl<<"having"
          " a minimum bet of $"<<minBet<<endl<<endl;
    
    do{
        int uTotal=0,  //card totals for user
            uTotal1=0, //user totals for split hand 1
            uTotal2=0, //user totals for split hand 2
            dTotal=0;  //card totals for dealer
        bJack=false;
        splitH=false;
        //get the shuffled deck
        gtDeck(shufDk);
        do{
            //player cash and bet
            cout<<"What is your bet going to be?"<<endl;
            cout<<"Cash: $"<<money<<endl<<"Your Bet: $";
            cin>>bet;
            if(bet<25 || bet>money){
                cout<<"You can't bet less than the minimum bet or bet more than what you have"<<endl<<endl;
            }
        }while(bet<minBet || bet>money);
        money-=bet;
        cout<<endl;

        //get first cards
        gtStrt(faces,value,shufDk,uTotal,dTotal);

        //check for ace card
        if(value[shufDk[0]]==1 || value[shufDk[2]]==1){
                uTotal+=10;
        }
        if(value[shufDk[1]]==1 || value[shufDk[3]]==1){
                dTotal+=10;
        }
        int i=4;//card position after the starting 4
        
        if(uTotal==21){
            cout<<"You got Black Jack! Getting Black Jack pays 3 to 2. You won $"<<bet+(bet*1.5)<<endl<<endl;
            money+=bet+(bet*1.5);
            bJack=true;
        }else if(dTotal==21){
            cout<<"Dealer got Black Jack! You lose!"<<endl<<endl;
            cout<<"Your Total: "<<uTotal<<endl<<"Dealer Total: "<<dTotal<<endl<<endl;
        }else if(uTotal==9 || uTotal==10 || uTotal==11){
            do{
                cout<<"Would you like to Double Down? [Y]/[N]"<<endl;
                cin>>dDown;
            if(bet>money){
                cout<<"You do not have enough funds to Double Down"<<endl;
            }
            }while(bet>money);
            cout<<endl;
            if(dDown=='Y' || dDown=='y' && money>=bet){
                money-=bet;
                //only give a single card
                cout<<"Your Card: "<<faces[shufDk[i]]<<endl<<endl;
                    
                //add 11 for the ace if total is less than 11 else add original value
                if(value[shufDk[i]]==1){
                    if(uTotal<11){
                        uTotal+=11;
                    }
                }else{
                    uTotal+=value[shufDk[i]];
                }

                //current totals
                cout<<"Your Total: "<<setw(2)<<uTotal<<"\tDealer Total: "<<value[shufDk[1]]<<endl<<endl;
                i++;
            }
            
        //split hand
        }else if(value[shufDk[0]]==value[shufDk[2]]){
            //ask if play wants to split
            cout<<"Do you want to split? [Y]/[N]"<<endl;
            cin>>splitDc;
            cout<<endl;
            if(splitDc=='Y' || splitDc=='y'){
                //call split function
                split(faces,value,shufDk,uTotal1,uTotal2,i);
                splitH=true;
                
                
                //deal with first hand
                cout<<endl<<"Hand 1:"<<endl<<endl;
                if(uTotal1==21){
                    cout<<"You Got Black Jack on your first hand! Black Jack Pays 3 to 2! You won $"<<bet+(bet*1.5)<<endl;
                    money+=bet+(bet*1.5);
                }else{
                    do{
                        cout<<"Your Total: Hand 1: "<<setw(2)<<uTotal1<<"\tDealer Total: "<<value[shufDk[1]]<<endl;
                        cout<<"            Hand 2: "<<setw(2)<<uTotal2<<endl<<endl;
                                
                        //play hand
                        cout<<"[H]it or [S]tand?"<<endl;
                        cin>>uChoice;
                        cout<<endl;
                        if(uChoice=='S' || uChoice=='s'){
                           nxtCard=false;
                        }else{
                            cout<<"Your Card: "<<faces[shufDk[i]]<<endl<<endl;

                            //add 11 for the ace if total is less than 11 else add original value
                            if(value[shufDk[i]]==1){
                                if(uTotal1<11){
                                    uTotal1+=11;
                                }
                            }else{
                                uTotal1+=value[shufDk[i]];
                            }

                            //current totals
                            cout<<"Your Total: "<<uTotal1<<endl;
                            if(uTotal1==21)nxtCard=false;
                            else if(uTotal1>21){
                                cout<<"You busted over 21. Hand 1 lost!"<<endl<<endl;
                                nxtCard=false;
                            }else nxtCard=true;
                            i++;
                        }
                    }while(nxtCard==true);
                }
                
                //deal with second hand
                cout<<"Hand 2:"<<endl<<endl;
                if(uTotal2==21){
                    cout<<"You Got Black Jack on your second hand! Black Jack Pays 3 to 2! You won $"<<bet+(bet*1.5)<<endl;
                    money+=bet+(bet*1.5);
                }else{
                    do{
                        cout<<"Your Total: Hand 1: "<<setw(2)<<uTotal1<<"\tDealer Total: "<<value[shufDk[1]]<<endl;
                        cout<<"            Hand 2: "<<setw(2)<<uTotal2<<endl<<endl;
                        
                        //play hand
                        cout<<"[H]it or [S]tand?"<<endl;
                        cin>>uChoice;
                        cout<<endl;
                        if(uChoice=='S' || uChoice=='s'){
                           nxtCard=false;
                        }else{
                            cout<<"Your Card: "<<faces[shufDk[i]]<<endl<<endl;

                            //add 11 for the ace if total is less than 11 else add original value
                            if(value[shufDk[i]]==1){
                                if(uTotal2<11){
                                    uTotal2+=11;
                                }
                            }else{
                                uTotal2+=value[shufDk[i]];
                            }

                            //current totals
                            cout<<"Your Total: "<<uTotal1<<endl;
                            if(uTotal2==21)nxtCard=false;
                            else if(uTotal2>21){
                                cout<<"You busted over 21. Hand 2 lost!"<<endl<<endl;
                                nxtCard=false;
                            }else nxtCard=true;
                            i++;
                        }
                    }while(nxtCard==true);
                }
            }
            
            
        //"normal" hand
        }else if(splitH==false){
        
            //initial totals
            cout<<"Your Total: "<<setw(2)<<uTotal<<"\tDealer Total: "<<value[shufDk[1]]<<endl<<endl;
            //player cards with decision of hit or stand
            do{
                cout<<"[H]it or [S]tand?"<<endl;
                cin>>uChoice;
                cout<<endl;
                if(uChoice=='S' || uChoice=='s'){
                   nxtCard=false;
                }else{
                    cout<<"Your Card: "<<faces[shufDk[i]]<<endl<<endl;
                    
                    //add 11 for the ace if total is less than 11 else add original value
                    if(value[shufDk[i]]==1){
                        if(uTotal<11){
                            uTotal+=11;
                        }
                    }else{
                        uTotal+=value[shufDk[i]];
                    }
                    
                    //current totals
                    cout<<"Your Total: "<<setw(2)<<uTotal<<"\tDealer Total: "<<value[shufDk[1]]<<endl<<endl;
                    if(uTotal==21)nxtCard=false;
                    else if(uTotal>21){
                        cout<<"You busted over 21. You lose!"<<endl<<endl;
                        nxtCard=false;
                    }else nxtCard=true;
                    i++;
                }
            }while(nxtCard==true);
        }
        if(uTotal1<22 || uTotal2<22 || uTotal<22 && !bJack){
            cout<<"Press [Enter] to reveal the Dealers second card"<<endl;
            cin.get();
            cin.ignore();
            //reveal Dealer's face down card
            cout<<"Dealer's Card:"<<faces[shufDk[3]]<<endl<<endl;
            if(splitH==true){
                cout<<"Your Total: Hand 1: "<<setw(2)<<uTotal1<<"\tDealer Total: "<<dTotal<<endl;
                cout<<"            Hand 2: "<<setw(2)<<uTotal2<<endl<<endl;
            }else{
                cout<<"Your Total: "<<setw(2)<<uTotal<<"\tDealer Total: "<<dTotal<<endl<<endl;
            }

            int j=i; //card position after player cards
            
            //dealer cards with dealer rules
            do{
                if(dTotal>=17 && dTotal<=21){
                    nxtCard=false;
                    cout<<"Dealer must stand on 17"<<endl;
                }else if(dTotal>21){
                    cout<<"Dealer busted over 21. You win!"<<endl<<endl;
                    money+=(bet*2);
                    nxtCard=false;
                }else{
                    cout<<"Press [Enter] for the Dealer's next card"<<endl;
                    cin.get();
                    cout<<"Dealer Card: "<<faces[shufDk[j]]<<endl<<endl;
                    dTotal+=value[shufDk[j]];
                    if(splitH==true){
                        cout<<"Your Total: Hand 1: "<<setw(2)<<uTotal1<<"\tDealer Total: "<<dTotal<<endl;
                        cout<<"            Hand 2: "<<setw(2)<<uTotal2<<endl<<endl;
                    }else{
                        cout<<"Your Total: "<<setw(2)<<uTotal<<"\tDealer Total: "<<dTotal<<endl<<endl;
                    }
                    nxtCard=true;
                }
                j++;
            }while(nxtCard==true);
            
            cout<<"Press [Enter] to continue"<<endl;
            cin.get();
            cin.ignore();
            
            //final totals
            if(splitH==true){
                cout<<"Your Total: Hand 1: "<<setw(2)<<uTotal1<<"\tDealer Total: "<<dTotal<<endl;
                cout<<"            Hand 2: "<<setw(2)<<uTotal2<<endl<<endl;
                if(uTotal1>dTotal && uTotal1<22){
                    cout<<"Your first hand beat the dealer!"<<endl<<endl;
                    money+=(bet*2);
                }
                if(uTotal2>dTotal && uTotal2<22){
                    cout<<"Your second hand beat the dealer!"<<endl<<endl;
                    money+=(bet*2);
                }
                else if(uTotal<dTotal && dTotal<22){
                    cout<<"The Dealer beat you!"<<endl<<endl;
                }else if(dTotal==uTotal){
                    cout<<"The game was a Push"<<endl<<endl;
                    if(dDown=='Y' || dDown=='y'){
                        money+=(bet*2);
                    }else money+=bet;
                }
            }else{
                cout<<"Your Total: "<<setw(2)<<uTotal<<"\tDealer Total: "<<dTotal<<endl<<endl;
                if(uTotal>dTotal && uTotal<22){
                    cout<<"You beat the dealer!"<<endl<<endl;
                    if(dDown=='Y' || dDown=='y'){
                        money+=(bet*4);
                    }else money+=(bet*2);
                }else if(uTotal<dTotal && dTotal<22){
                    cout<<"The Dealer beat you!"<<endl<<endl;
                }else if(dTotal==uTotal){
                    cout<<"The game was a Push"<<endl<<endl;
                    if(dDown=='Y' || dDown=='y'){
                        money+=(bet*2);
                    }else money+=bet;
                }
            }
        }
        //Here is a pointer *
    }while(money>=minBet);
    
    //Thanks for playing
    cout<<"You have run out of funds.\nThanks for playing Black Jack."<<endl;
    cout<<"We will see you next time"<<endl;
    
    //Exit Stage Right!
    return 0;
}

void split(string k[],int v[],int s[],int &u1,int &u2,int &i){
    cout<<"Hand 1:"<<endl;
    cout<<"  First Initial Card: "<<k[s[0]]<<endl;
    cout<<"  New Card:           "<<k[s[i]]<<endl;
    u1=v[s[0]]+v[s[i]];
    i++;
    
    cout<<"Hand 2:"<<endl;
    cout<<"  Second Initial Card: "<<k[s[2]]<<endl;
    cout<<"  New Card:            "<<k[s[i]]<<endl;
    u2=v[s[2]]+v[s[i]];
    i++;
}

/*********************************************************
 *****************  get starting hand  *******************
 *********************************************************
 * Purpose: get the first 4 cards of the game
 * Input:
 *      k[] -> string face cards (ex. A-H)
 *      v[] -> values of each card
 *      s[] -> shuffled deck of cards
 * Input-Output:
 *      &u -> user totals
 *      &d -> dealer totals
 ********************************************************/
void gtStrt(string k[],int v[],int s[],int &u,int &d){
    //adding totals of each starting hand
    u+=v[s[0]];
    u+=v[s[2]];
    d+=v[s[1]];
    d+=v[s[3]];
    
    //reveal each card individually
    cout<<"Press Enter to reveal each card"<<endl<<endl;
    cin.get();
    cout<<"Your Card:"<<endl;
    cout<<"Card 1: "<<k[s[0]]<<endl;
    cin.get();
    //cin.ignore();
    cout<<"Dealer Card:"<<endl;
    cout<<"Card 2: "<<k[s[1]]<<endl;
    cin.get();
    //cin.ignore();
    cout<<"Your Card:"<<endl;
    cout<<"Card 3: "<<k[s[2]]<<endl;
    cin.get();
    //cin.ignore();
    cout<<"Dealer Card:"<<endl;
    cout<<"Card 4: Faced Down"<<endl;
    cin.get();
    //cin.ignore();

    //display player and dealer hands together
    cout<<"Your Cards:"<<endl;
    cout<<"Card 1: "<<k[s[0]]<<endl;
    cout<<"Card 3: "<<k[s[2]]<<endl<<endl;

    cout<<"Dealer Cards:"<<endl;
    cout<<"Card 2: "<<k[s[1]]<<endl;
    cout<<"Card 4: Face Down"<<endl<<endl;
}

/*********************************************************
 ********************  get deck  *************************
 *********************************************************
 * Purpose: get a deck of cards
 * Input:
 *      d[] -> initial deck of cards
 * Input-Output: 
 *      s[] -> shuffled deck of cards(shufDk[CARDS])
 ********************************************************/
void gtDeck(int s[]){
    const int CARDS=52;
    int d[CARDS]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
                  23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,
                  42,43,44,45,46,47,48,49,50,51};
    for(int i=52;i>0;--i){
        int j=rand()%i;
        int temp=d[i];
        d[i]=d[j];
        d[j]=temp;
    }
    for(int k=0;k<52;k++){
        s[k]=d[k];
    }
}