/* File: main
 * Author: Ryan Sorice
 * Created on 15 November 2016 2:45 PM
 * Purpose:
 */

//System Libraries
#include <iostream>         //Inputs/outputs
#include <iomanip>          //Formatting

using namespace std;        //Name-space in system libraries

//Global variables

//Function prototypes
void fillAry(float [],int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int const MONTHS=12;
    float rainAvg[MONTHS],rainAct[MONTHS];
    string city,mon;
    int month;
    
    //Initial output; Variable initiation
    cout<<"This program will compare actual rainfall per month(in inches) of a\n";
    cout<<"particular city, to the average rainfall per month of that city!\n";
    cout<<"First, what is the name of your city? (Don't enter any spaces if two words +++)\n";
    cin>>city;
    cout<<"Now, what is the current month? Enter 1-12\n";
    cin>>month;
    
    //Fill the arrays
    cout<<"Enter the average rainfall(in cms) from your current month and the prior 11 months\n";
    fillAry(rainAvg,month);
    cout<<"Now, enter the actual rainfall(in cms) from your current month and the prior 11 months\n";
    fillAry(rainAct,month);
    
    //Display array table
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout<<setw(5)<<"Month"<<setw(15)<<"Rainfall(in.)"<<setw(12)<<"+/- Avg.\n";
    //Loop for table
    for(int n=1;n<13;n++){
        switch(n){
            case 1: mon="Jan."; break;
            case 2: mon="Feb."; break;
            case 3: mon="Mar."; break;
            case 4: mon="Apr."; break;
            case 5: mon="May."; break;
            case 6: mon="Jun."; break;
            case 7: mon="Jul."; break;
            case 8: mon="Aug."; break;
            case 9: mon="Sep."; break;
            case 10: mon="Oct."; break;
            case 11: mon="Nov."; break;
            case 12: mon="Dec."; break;
        }
        cout<<setw(5)<<mon<<setw(14)<<rainAct[n]<<setw(10)<<rainAvg[n]-rainAct[n]<<endl;
    }
    //Exits program
    return 0;
}
void fillAry(float rain[],int month){
    for(short n=0;n<12;n++){
        if(month==13) month-=12;
        switch(month){
            case 1: cout<<"January?\n"; cin>>rain[month]; break;
            case 2: cout<<"February?\n"; cin>>rain[month]; break;
            case 3: cout<<"March?\n"; cin>>rain[month]; break;
            case 4: cout<<"April?\n"; cin>>rain[month]; break;
            case 5: cout<<"May?\n"; cin>>rain[month]; break;
            case 6: cout<<"June?\n"; cin>>rain[month]; break;
            case 7: cout<<"July?\n"; cin>>rain[month]; break;
            case 8: cout<<"August?\n"; cin>>rain[month]; break;
            case 9: cout<<"September?\n"; cin>>rain[month]; break;
            case 10: cout<<"October?\n"; cin>>rain[month]; break;
            case 11: cout<<"November?\n"; cin>>rain[month]; break;
            case 12: cout<<"December?\n"; cin>>rain[month]; break;
        }
        month++;
    }
}