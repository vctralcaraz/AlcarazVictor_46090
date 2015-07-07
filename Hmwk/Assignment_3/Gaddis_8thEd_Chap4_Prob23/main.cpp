/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on July 5, 2015, 2:50 PM
 * Purpose: Homework, Geometry Calculator
 */

//System Libraries
#include <iostream>//I/O Library
using namespace std;//Standard namespace for iostream

//User Libraries

//Global Constants
const float PI=3.14159;

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;  //User choice
    bool doAgain;
    
    //the loop
    do{


        //Output the Selection Menu
        cout<<"Geometry Calculator"<<endl<<endl;
        cout<<"     1. Calculate the Area of a Circle"<<endl;
        cout<<"     2. Calculate the Area of a Rectangle"<<endl;
        cout<<"     3. Calculate the Area of a Triangle"<<endl;
        cout<<"     4. Quit"<<endl<<endl;
        cout<<"Enter your choice (1-4): ";
        cin>>choice;
        cout<<endl<<endl;

        switch(choice){
            case '1':
                float radCir;  //radius of a circle
                float areaCir; //area of the circle
                cout<<"Enter the radius of the circle"<<endl;
                cin>>radCir;
                cout<<endl;
                if(radCir<=0){
                    cout<<"You shouldn't enter a negative number or zero"<<endl;
                    return 3;
                }else{
                    areaCir=PI*radCir*radCir;
                    cout<<"The area of your circle is "<<areaCir<<" units squared"<<endl;
                }
                break;
            case '2':
                float length;   //length of rectangle
                float width;    //width of rectangle
                float areaRec;  //area of rectangle
                cout<<"Enter the length of your rectangle"<<endl;
                cin>>length;
                cout<<endl<<"Enter the width of the your rectangle"<<endl;
                cin>>width;
                if(length<=0 || width<=0){
                    cout<<"You shouldn't enter a negative number or zero"<<endl;
                    return 3;
                }else{
                    areaRec=length*width;
                    cout<<endl<<"The area of your rectangle is "<<areaRec<<" units squared"<<endl;
                }
                break;
            case '3':
                float base;   //base of triangle
                float height; //hieght of triangle
                float areaTri;//area of triangle
                cout<<"Enter the base of your triangle"<<endl;
                cin>>base;
                cout<<endl<<"Enter the height of your triangle"<<endl;
                cin>>height;
                if(base<=0 || height<=0){
                    cout<<"You shouldn't enter a negative number or zero"<<endl;
                    return 3;
                }else{
                    areaTri=base*height/2;
                    cout<<endl<<"The area of your triangle is "<<areaTri<<" units squared"<<endl;
                }
                break;
            case '4':
                cout<<"Bye"<<endl;
                return 2;
            default:
                cout<<"You didn't choose a number between 1 and 4"<<endl;
                return 1;
        }
        char response;
        cout<<endl<<endl<<"Would you like to do another calculation? y/n"<<endl;
        cin>>response;
        cout<<endl<<endl;
        if(response=='y')doAgain=true;
        else{
            doAgain=false;
            cout<<"Bye"<<endl;
        }
    }while(doAgain);
    //Exit Stage Right!
    return 0;
}