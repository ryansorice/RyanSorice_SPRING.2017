/* 
 * File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 28 September 2016 12:06 PM
 * 
 * Purpose: Write a program that allows user to input a temperature range
 *          and then outputs velocity at each increment of temperature within
 *          the given range.
 */

//System library
#include <iostream>

using namespace std; //Namespace in system library

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    short count=0;
    float veloc, //Velocity with given temperature
          temp1, //Beginning temperature 
          temp2, //Ending temperature
          tempHld, //Holds starting temp range and each increment
          tempRge; //Temperature range
    
    //Initial output to user and initialization of variables
    cout<<"What is your starting temperature in degrees Celsius?\n";
    cin>>temp1;
    cout<<"What is your ending temperature in degrees Celsius?\n";
    cin>>temp2;
    
    //Processing temperature range
    tempRge=temp2-temp1;
    
    //Loop to process each increment of temperature in the temperature range
    while(count<=tempRge)
    {
        //Processing inputs mapping to outputs
        tempHld=temp1+count; //Initial temp then adds 1 until final temp is reached
        veloc=331.3+0.61*tempHld; 
        count++;
        
        //Final output of processed values
        cout<<"At "<<tempHld<<" degrees Celsius, the velocity of sound is "<<veloc<<" m/s\n";
    }

    //Exits program
    return 0;
}

