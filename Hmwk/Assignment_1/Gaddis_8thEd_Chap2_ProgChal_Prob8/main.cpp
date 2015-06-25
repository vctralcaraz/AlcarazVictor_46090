/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on June 23, 2015, 4:02 PM
 * Purpose: Homework, Total Purchase
 */

//System Libraries
#include <iostream> //File I/O
using namespace std; //std namespace -> iostream

//User Libraries

//Global constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declare Variables Here
    float pItem1 = 15.95;  //Price of item 1
    float pItem2 = 24.95;  //Price of item 2
    float pItem3 = 6.95;   //Price of item 3
    float pItem4 = 12.95;  //Price of item 4
    float pItem5 = 3.95;   //Price of item 5
    float subTtl;          //total amount of sale before tax
    unsigned short saleTax = 7;//Percent tax of sale
    float ttlTax;          //total amount of tax on sale
    float ttlSale;         //total amount of sale with tax
    
    //calulating sales tax and total
    subTtl=pItem1+pItem2+pItem3+pItem4+pItem5;
    ttlTax=subTtl*saleTax/100;
    ttlSale=subTtl+ttlTax;
    
    //Output Unknowns Here
    cout<<"Sub-total = $"<<subTtl<<endl;
    cout<<"Sales Tax = $"<<ttlTax<<endl;
    cout<<"Total     = $"<<ttlSale<<endl;
    
    //Exit Stage Right!
    return 0;
}
