/* File: main
 * Author: Ryan Sorice
 * Created on 16 October 2016 7:47 AM
 * Purpose: Output total interest due on a credit card account given the 
 *          balance, interest rate and number of months to collect interest. */

//System libraries
#include <iostream> //Inputs and outputs

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {

    //Declaration/Initiation of variables
    short n=0, //Loop counter
          mons; //Number of months interest to be paid
    float credBal, //User's credit balance
          intRate, //Interest rate on credit balance
          accInt, //Total interest accrued after each month
          totInt=0, //Total accrued interest after all months
          totBal=0; //Total balance due with interest
          
    
    //Initial output; Variable initiation
    cout<<"What is your current credit balance owed?\n";
    cin>>credBal;
    cout<<"What is the interest rate on your credit balance?\n";
    cin>>intRate;
    cout<<"How many months is interest being collected?\n";
    cin>>mons;
    
    //Loop to calculate total interest and total balance for user's  months
    while(n<mons){
        //Process values
        accInt=credBal*(intRate/100); //Interest of on total balance after each month
        credBal=accInt+credBal; //Adds interest for each month to total balance
        totInt=totInt+accInt; //Adds interest to total interest after each month
        n++; //Increments n til equal to months for the loop
    }
    //Final output; total interest and total balance
    cout<<"The total interest due is $"<<totInt<<endl;
    cout<<"Your balance due, with interest, after "<<mons<<" month(s) is $"<<credBal<<endl;
    
    //Exits program
    return 0;
}