/* File: main
 * Author: Ryan Sorice
 * Created on 9 November 2016 12:18 PM
 * Purpose: Compute standard deviation and average of 4 scores
 */

//System libraries
#include <iostream>                         //Inputs and outputs
#include <cmath>                            //Math library; Power/Squareroot functions

using namespace std;                        //Name-space in system libraries

//Global variables

//Function prototypes
float avgScr(float,float,float,float);      //Function for average computation
float stdDev(float,float,float,float,float);//Function for standard deviation computation

//Execution begins here
int main(int argc, char** argv) {
    //Declaration/Initiation of variables
    float scor1,scor2,scor3,scor4,          //Variables for each of the 4 scores
          average,                          //Average of the 4 scores
          stanDev;                          //Standard deviation of the 4 scores
    char yesno='y';                         //Loop variable
    
    //Initial output
    cout<<"This program will compute the average and the standard deviation\n";
    cout<<"of 4 different scores!\n";
    
    //Loop to repeat calculation 'til user says no
    while(yesno=='y'||yesno=='Y'){
        //Output; User initiates score values
        cout<<"What is your first score?\n"; cin>>scor1;
        cout<<"Second score?\n"; cin>>scor2;
        cout<<"Third score?\n"; cin>>scor3;
        cout<<"Last score?\n"; cin>>scor4;
        
        //Process inputs to get outputs
        average=avgScr(scor1,scor2,scor3,scor4);                //Gets average value from function
        stanDev=stdDev(scor1,scor2,scor3,scor4,average);        //Gets standard value deviation from function
        
        //Output results
        cout<<"The average of your 4 scores is: "<<average<<endl;
        cout<<"The standard deviation of your 4 scores is: "<<stanDev<<endl;
        
        //Output; User re-initiates/breaks loop
        cout<<"Would you like to try again with new scores? Enter 'Y'-Yes or 'N'-No\n";
        cin>>yesno;
    }
    //Exits program
    return 0;
}
float stdDev(float scor1, float scor2, float scor3, float scor4, float average){
    float stanDev;                                  //Declare returned variable
    //Process function values to get standard deviation
    stanDev=sqrt((pow((scor1-average),2)+pow((scor2-average),2)+pow((scor3-average),2)+pow((scor4-average),2))/4);
    return stanDev;                                 //Returns standard deviation to function
}
float avgScr(float scor1, float scor2, float scor3, float scor4){
    float average=(scor1+scor2+scor3+scor4)/4;      //Declare and process variable with function values
    return average;                                 //Returns average to function
}