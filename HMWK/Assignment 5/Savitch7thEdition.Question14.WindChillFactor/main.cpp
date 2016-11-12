/* File: main
 * Author: Ryan Sorice
 * Created on 3 November 2016 3:27 PM
 * Purpose: Compute windchill factor given airspeed and temperature
 */

//System libraries
#include <iostream>         //Inputs and outputs
#include <cmath>            //Math library;Power function

using namespace std;        //Name-space in system libraries

//User libraries

//Global variables

//Function prototypes
float windChl(float,float);                        //Function to computer Windchill factor

//Execution begins here
int main(int argc, char** argv) {
    //Declaration of variables
    float windSpd,                                 //Speed of wind in m/sec
          temp,                                    //Temperature in degrees Celsius
          wChill;                                  //Variable to hold value of windchill factor
    char yesno='y';                                //Variable to control loop by user 
    
    //Initial output
    cout<<"This program will calculate the current windchill!\n";
    
    //Loop to allow user to repeat calculation until they say no
    while(yesno=='y'||yesno=='Y'){
        //Output, variable initiation
        cout<<"What is the current temperature in degrees Celsius?\n";
        cin>>temp;
        cout<<"What is the current speed of the wind?\n";
        cin>>windSpd;
        
        //If temperature is too high to produce windchill
        if(temp>10) cout<<"It's too warm for their to be a windchill!\n";
        //Else if temperature is in range to produce windchill
        else{
            wChill=windChl(temp,windSpd);           //Gets value of windchill from function
            //Output windchill value
            cout<<"Windchill Index = "<<wChill<<" Degrees Celsius\n";
        }
        //Output; User initiates/breaks loop
        cout<<"Would you like to calculate with new date? Enter 'Y'-Yes or 'N'-No\n";
        cin>>yesno;
    }
    //Exits program
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   windChl ******************************************
//Purpose:  Compute windchill factor
//Inputs:   temp,windSpd: Floats; temperate and windspeed
//Output:   wChill: Float; windchill
//******************************************************************************
float windChl(float temp,float windSpd){
    //Declare and process return variable
    float wChill=13.12+(0.6215*temp)-(11.37*pow(windSpd,0.16))+(0.3965*temp*pow(windSpd,0.016));
    return wChill;      //Returns value of windchill to function
}