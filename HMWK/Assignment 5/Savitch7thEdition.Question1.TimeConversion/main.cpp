/* File: main
 * Author: Ryan Sorice
 * Created on 9 November 2016 12:12 PM
 * Purpose: Allow user to compute their 24-hour notation time, to 12-hour notation
 */

//System libraries
#include <iostream>         //Inputs and outputs

using namespace std;        //Name-space in system libraries

//User Libraries

//Global variables

//Function prototypes
string newTime(short &);    //Function to convert hours to 12-hour notation and get am/pm value

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    string ampm;            //String to hold am/pm value
    short hour,minute;      //Values for the minute/hour; before/after
    char yesno='y';         //Loop variable
    
    //Initial output
    cout<<"This program will convert 24-hour notation to 12-hour notation!\n";
    
    //Loop to repeat computation; While user says yes
    while(yesno=='y'||yesno=='Y'){
        //Output; User initiates variables
        cout<<"What is the hour?\n";
        cin>>hour;
        cout<<"What is the minute?\n";
        cin>>minute;
        if((hour<0||hour>24)||(minute<0||minute>59)){               //If invalid inputs to hours or minutes
            cout<<"That is not a valid time!\n";
        }
        else{                                                       //Else compute new time
            //Process inputs to get outputs
            ampm=newTime(hour);                                     //Gets am/pm value and changes hour value from function
            //If minutes is a single digit to add a 0 in front
            if(minute>=0&&minute<10) cout<<"Your time is "<<hour<<":0"<<minute<<" "<<ampm<<endl;
            //Else output new time
            else cout<<"Your time is "<<hour<<":"<<minute<<" "<<ampm<<endl;
        }
        //Output; initiate/break loop
        cout<<"Would you like to compute with new data? Enter 'Y'-Yes 'N'-No\n";
        cin>>yesno;
    }
    //Exits program
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   newTime ******************************************
//Purpose:  Turn 24-hour notation to 12-hour notation
//Inputs:   hour, minute; shorts for user's time(the hour and the minute)
//Output:   ampm; string returned for 'am' or 'pm' of the time
//******************************************************************************
string newTime(short &hour){
    string ampm;                            //Variable to be returned; am/pm
    if(hour==0){                            //If hour is 0 
        hour=12;                            //12-hour notation; hour set to 12
        ampm="A.M.";                        //String value set to am
    }
    else if(hour>0&&hour<12) ampm="A.M.";   //Else If hour between 0 and 12; String value set to am
    else if(hour==12) ampm="P.M.";          //Else If hour is 12; String value set to pm
    else if(hour>12){                       //Else If hour greater than 12
        hour=hour-12;                       //New hour value is hour-12 for 12-hour notation
        ampm="P.M.";                        //String value set to pm
    }
    return ampm;                            //Returns string value back to function
}