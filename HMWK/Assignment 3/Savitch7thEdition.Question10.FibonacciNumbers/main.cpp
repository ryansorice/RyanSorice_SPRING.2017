/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 5 October 2016 7:52 AM
 * 
 * Purpose: Calculate Fibonacci's Number Sequence for the growth of the
 *          'green crud' population, that grows every 5th day.
 */

//System libraries
#include <iostream>

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    float lbs, //Initial weight of population
          lbs1=0, //Holds previous weight 
          lbs2, //Total accrued weight
          days; //Number of days to grow population
    short x=0; //Counter for population growth loop
    
    //Initial output to user; Variable initiation
    cout<<"What is the starting weight (lbs) of the Green Crud population.\n";
    cin>>lbs;
    cout<<"How many days will this population grow?\n";
    cin>>days;
    
    //Loop to process population group for allotted number of days
    while(x<days)
    {
        //Processing of values
        lbs2=lbs1+lbs; 
        lbs1=lbs; 
        lbs=lbs2; 
        x+=5; //Calculates growth every 5 days
        
    }
    //If statement to output previous total weight if there is a remainder of days
    if(x>days)
    {
            cout<<"The population weighs "<<lbs1<<" lbs after "<<days<<" days.\n";
    }
    //Else, outputs total weight if no remainder of days
    else
    {
        cout<<"The population weighs "<<lbs<<" lbs after "<<days<<" days.\n";
    }

    //Exits program
    return 0;
}

