/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 27 September 2016 6:27 PM
 * 
 * Purpose: Write a program that outputs the expected cost of an item in a specified 
 *          number of years after inflation; the user will enter the current cost of the item, the 
 *          number of years to be inflated, and the inflation rate.
 */

//System Libraries
#include <iostream>
#include <cmath>

using namespace std; //namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration and initiation of variables
    float infltP,//Inflation percentage
          infltF,//Inflation fractional
          cost;//Current cost of item
    
    short years,//Amount of years to be inflated
          count=0;//Place counter for number of years of inflation
   
    int places=2;//Places to round answer
    
    //First output to user; asks user for variable initiations
    cout<<"What is the current cost of your item?\n";
    cin>>cost; 
    cout<<"How many years from now will the item be purchased?\n";
    cin>>years; 
    cout<<"What is the inflation percentage?\n";
    cin>>infltP; 
    
    infltF=infltP/100; //Processing fractional value of inflation percentage
    
    //Loop for processing inflation
    while(count<years)
    {
        cost=cost*infltF+cost; //Processing of cost with inflation 1 year at a time
        count++; //Counts how many times the loop has run until it has run the specified number of years
    }
    
    float shift=pow(10,places); //Number of places to shift answer
    int round=cost*shift+0.5; //Rounds the inflated cost to two decimals
    cost=round/shift; //Shifts answer back
    
    //Final output to user with new cost after inflation
    cout<<"The cost of your item after "<<years<<" years is $"<<cost<<".\n";

    //Exits program
    return 0;
}

