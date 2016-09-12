/* 
   File:   main
   Author: Ryan Sorice
   Created on September 12, 2016
   Purpose:  Calculate the Nasa Budget as percentage of Federal Budget
    Federal Budget -> $3.999 trillion from 
        https://en.wikipedia.org/wiki/2016_United_States_federal_budget
    Nasa Budget -> $18.5 billion from
        http://www.nasa.gov/content/reach-for-new-heights-nasa-budget-unveiled-for-fiscal-year-2016
 */

//System Libraries
#include <iostream>   //Input/Output objects
using namespace std;  //Name-space used in the System Library

//User Libraries

//Global Constants
const unsigned char PERCENT=100;  //Conversion to percentage

//Function prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    float nasBdgt=185e8;   //See reference from above
    float fedBdgt=3.999e12f;//See reference from above
    float pNasSpd;          //Percentage Nasa spending
    
    //Process values -> Map inputs to Outputs
    pNasSpd=nasBdgt/fedBdgt*PERCENT;
    
    //How to round to 2 decimal places
    int round=pNasSpd*100+0.5f;//Shift by 2 decimal places *100 then round up 0.5
    pNasSpd=round/100.0f;//Integer truncated then shift back 2 decimal places
    
    //Display Output
    cout<<"The Nasa Budget for 2016 = $"<<nasBdgt<<endl;
    cout<<"The Federal Budget for 2016  = $"<<fedBdgt<<endl;
    cout<<"The Percentage spent on Nasa = "<<pNasSpd<<"%"<<endl;
    
    //Exit Program
    return 0;
}