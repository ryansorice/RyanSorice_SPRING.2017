/* 
 * Author: Ryan Sorice
 * 
 * Created on 14 September 2016
 * 
 * Purpose: Write a program that allows the user to enter a time in seconds and
 *          then outputs how far an object, that starts at rest, would drop if it 
 *          is in free-fall for that lengths of time.
 */

//System Libraries
#include <iostream> //Input/Output objects
#include <iomanip> //Formatting

using namespace std; //namespace in system library being used

//Global Constants
const float GRAVITY=32.174; //Acceleration of object (ft/sec^2)
const float CNVMFT=3.28084; // Conversion feet to meters


//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    float time; //Amount of time object is in free-fall
    float dfeet; //Distance fell in feet
    float dmeter; //Distance fell in meters
    
    //First output to user
    cout<<"This program determines how much distance an object has traveled in free-fall for any number of seconds entered."<<endl<<endl; //Point of the program
    cout<<"How many seconds is your object in free-fall?"<<endl; //Asks user for time in seconds
    cin>>time; //User inputs number of seconds
    
    dfeet=GRAVITY*time*time/2; //Calculates distance in feet 
    dmeter=dfeet/CNVMFT; //Conversion of the distance from feet to meters
    
    //Final output with results
    cout<<endl<<"Consider gravity is "<<GRAVITY<<" ft/sec^2"<<"."<<endl<<endl; //Outputs gravity/acceleration
    cout<<"The distance dropped in feet is    : "<<setw(7)<<dfeet<<"."<<endl; //Outputs total distance in feet
    cout<<"The distance dropped in meters is  : "<<setw(7)<<dmeter<<"."<<endl; //Outputs total distance in meters
    
    
    //Exits program
    return 0;
}

