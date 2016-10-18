/* File: main
 * Author: Ryan Sorice
 * Created on 16 October 2016 12:55 PM
 * Purpose: User enters two times of day; Outputs difference in time in minutes.
 */

//System libraries
#include <iostream> //Inputs and outputs
#include <cmath> //Math library for absolute value function

using namespace std; //Namespace in system library

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
     string ampm, //Am or pm of first time
           ampm1; //Am or pm of second time
    int hrs, //Hours of first time
        hrs1, //Hours of second time
        hrs2,
        min, //Minutes of first time
        min1, //Minutes of second time
        min2,
        totMin;
    
    //Initial outputs; Variables initiated
    cout<<"This program calculates the difference, in minutes, between two set times!\n";
    cout<<"What is the hour of your initial time?\n";
    cin>>hrs;
    cout<<"What is the minute of your initial time?\n";
    cin>>min;
    cout<<"Is it am or pm? Enter 'am' or 'pm'\n";
    cin>>ampm;
    cout<<"Now, what is the hour of your ending time?\n";
    cin>>hrs1;
    cout<<"What is the minute of your ending time?\n";
    cin>>min1;
    cout<<"Is it am or pm? Enter 'am' or 'pm'\n";
    cin>>ampm1;
    
    //Process values
    if(hrs1<hrs&&ampm!=ampm1){
       
       if(min>min1){
           hrs2=(11-hrs)+hrs1;
           min2=(60-min)+min1;
       }
       else{
           hrs2=(12-hrs)+hrs1;
           min2=abs(min1-min);
       }
    }
    //Process values
    else if(hrs1<hrs&&ampm==ampm1){
       hrs2=24-(hrs-hrs1);
       min2=abs(min1-min); 
    }
    //Process values
    else if(hrs1>hrs){
        if(min>min1){
           hrs2=abs(hrs1-hrs-1);
           min2=abs(60-min)+min1; 
        }
        else{
            hrs2=abs(hrs1-hrs);
            min2=abs(min1-min);
        } 
    }
    //Process values
    else if(hrs1==hrs){
        hrs2=hrs1-hrs;
        if(min<min1){
            min2=min1-min;
        }
        else if(min>min1){
            min2=(23*60)+(min1+min);
        }
    }
    //If statement
    if(hrs2>0&&ampm==ampm1){
        totMin=min2+(hrs2*60);
        cout<<"The difference in time is "<<totMin<<" minutes.\n";
    }
    else if(hrs2>0&&ampm!=ampm1){
        totMin=min2+(hrs2*60);
        cout<<"The difference in time is "<<totMin<<" minutes.\n";
    }
    else if(hrs2==0){
        cout<<"The difference in time is "<<min2<<" minutes.\n";
    }
    //Exits program
    return 0;
}

