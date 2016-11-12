/* File: main
 * Author: Ryan Sorice
 * Created on 9 November 2016 2:43 PM
 * Purpose: Compute new time given current time and duration of waiting period
 *          in 12-hour notation
 */

//System libraries
#include <iostream>                                         //Inputs and outputs

using namespace std;                                        //Name-space in system libraries

//User Libraries

//Global variables

//Function prototypes
string newTime(short &, short &, short, short, string);     //Function to get new time after a waiting period

//Execution begins here
int main(int argc, char** argv) {
    //Declaration of variables
    short initHr,waitHr,newHr,                              //Hour variables(current/waiting/new)
          initMin,waitMin,newMin;                           //Minute variables(current/waiting/new)
    char yesno='y';                                         //Loop variables
    string intAmpm,newAmpm;                                 //String variables for initial and new am/pm values
    
    //Initial output
    cout<<"This program will compute your new time given\n";
    cout<<"the current time and the duration of time to pass!\n";
    cout<<"**Note: Time is 12-hour notation\n";
   
    while(yesno=='y'||yesno=='Y'){                             //Loop to repeat calculation while user says yes
        //Output; User initiates values of variables
        cout<<"What is the current hour?\n";
        cin>>initHr;
        cout<<"What is the current minute?\n";
        cin>>initMin;
        cout<<"AM or PM? Enter 'AM'-am 'PM'-pm\n";
        cin>>intAmpm;
        cout<<"Now, the amount of hours to wait?\n";
        cin>>waitHr;
        cout<<"And the amount of minutes to wait?\n";
        cin>>waitMin;
        
        while(waitMin>59){                                     //Nested loop if minutes overflow for additional hrs
            waitMin-=60;                                       //Mins minus 60 for each hrs
            waitHr+=1;                                         //Hrs plus 1
        }
        newAmpm=newTime(initHr,initMin,waitHr,waitMin,intAmpm);//Calls function to get am/pm val. & new hrs/mins vals.
        //If the minutes are 0 to 9; add a 0 in front; print new time
        if(initMin>-1&&initMin<10) cout<<"Your time will be "<<initHr<<":0"<<initMin<<" "<<newAmpm<<endl;
        //Else print the new time
        else cout<<"Your time will be "<<initHr<<":"<<initMin<<" "<<newAmpm<<endl;
        //Output; User initiates/breaks loop
        cout<<"Would you like to compute with new data? Enter 'Y'-Yes or 'N'-No\n";
        cin>>yesno;
    }
    //Exits program
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   newTime ******************************************
//Purpose:  Get new time after a waiting period is served; 12-hour notation
//Inputs:   initHr,initMin,waitHr,waitMin; shorts for hrs and mins
//          intAmpm; string for am/pm value
//Output:   newTime; string with computed am/pm value
//          inithr,initMin; shorts for new time
//******************************************************************************
string newTime(short &initHr, short &initMin, short waitHr, short waitMin, string intAmpm){
    string newAmpm;                                         //Returned string variable
    initMin+=waitMin;                                       //Adds minutes to be waited to initial minute
    initHr+=waitHr;                                         //Adds hours to be waited to initial hour
    if(initMin>59){                                         //If the new minutes overflow to the next hour
        initMin-=60;                                        //Take 60 from minutes
        initHr+=1;                                          //Add 1 to hours
    }
    if(initHr>12&&intAmpm=="AM"){                           //If the hours exceed 12 and AM
        initHr-=12;                                         //Subtract 12 from hours to get 12-hour notation 
        newAmpm="PM";                                       //Set value to PM if AM
    }
    else if(initHr>12&&intAmpm=="PM"){                      //Else If the hours exceed 12 and PM
        initHr-=12;                                         //Subtract 12 from hours to get 12-hour notation 
        newAmpm="AM";                                       //Set value to AM if PM   
    }
    else if(initHr==12&&intAmpm=="AM") newAmpm="PM";        //Else If hours = 12 and AM; set to PM            
    else if(initHr==12&&intAmpm=="PM") newAmpm="AM";        //Else If hours = 12 and PM; set to AM             
    else newAmpm=intAmpm;                                   //Else keep same am/pm value 
    return newAmpm;                                         //Returns am/pm value
}