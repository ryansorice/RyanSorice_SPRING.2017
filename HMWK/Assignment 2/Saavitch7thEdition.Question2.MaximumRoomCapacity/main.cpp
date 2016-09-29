/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 27 September 2016 4:17 PM
 * 
 * Purpose: Write a program that determines whether a meeting room is in violation
 *          of fire law regulations regarding maximum room capacity. User enters room 
 *          capacity and amount of people inside; user should be able to repeat this
 *          as often as they would like.
 */

//System library
#include <iostream>

using namespace std; //namespace in system library

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    short maxCap, //maximum capacity of people
          people; //number of people attending
    char yesno; //Variable to continue or end program
    
    //Introductory output to user
    cout<<"So, you would like to hold a meeting today? Enter 'Y' or 'N'?\n";
    cin>>yesno;
    
    //Loop initiation to repeat program as often as user would like
    while(yesno=='y'||yesno=='Y')
    {
        //First output to user;initialization of variables
        cout<<"What is the maximum capacity of the meeting room?\n";
        cin>>maxCap; 
        cout<<"How many people are attending the meeting?\n";
        cin>>people; 
        
        //First if statement/LOGIC MISTAKE
        if(maxCap<=0)
        {
            cout<<"Logically, a meeting room cannot have a capacity of "<<maxCap<<".\n";
        }
        
        //Second if statement
        else if(people<=maxCap)
        {
            //Output if capacity is legal
            cout<<"It is legal to hold this meeting. "<<people<<" people are attending and "<<maxCap-people<<" people can still attend.\n";
        }
        //Third if statement if first two fail
        else if(people>maxCap)
        {
            //Output if capacity is illegal
            cout<<"Due to fire regulations, the meeting cannot be held. "<<people-maxCap<<" people must leave before the meeting can begin.\n";
        }
        //Outputs to user if they would like to run program again
        cout<<"Are you planning another meeting? Enter 'Y' or 'N'?\n";
        cin>>yesno;
    }
    
    //Exits program
    return 0;
}

