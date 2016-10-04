/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 4 October 2016 1:23 PM
 * 
 * Purpose: Compute interest due, minimum payment and total amount due
 *          for a revolving credit account.
 */

//System libraries
#include <iostream> //Inputs/outputs
#include <iomanip> //Formatting

using namespace std; //Namespace in system 

//Global constants
const float INTRST1=.015,
            INTRST2=.01;

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    float accBal, //Users account balance
          tmpBal1, //Temporary interest holder
          tmpBal2, //Temporary interest holder
          totBal; //Total balance due after interest
    
    //Initial output to user; initiation of accBal
    cout<<"What is the account balance on your credit card?\n";
    cin>>accBal;
    
    //First if statement if amount is $1000 or under
    if(accBal<=1000)
    {
        //Process values map inputs to outputs
        tmpBal1=accBal*INTRST1; //Interest due
        totBal=tmpBal1+accBal;
        
        //First nested if, if total balance is $10 or less
        if(totBal<=10)
        {
            cout<<"The interest due is: $"<<setw(5)<<tmpBal1<<endl;
            cout<<"The minimum payment is the total balance due of: $"<<setw(5)<<totBal<<endl;
        }
        //Next nested if, if total balance is greater than $10
        else
        {
            cout<<"The interest due is: $"<<setw(5)<<tmpBal1<<endl;
            cout<<"The minimum payment is: $"<<setw(5)<<totBal/10<<endl;
            cout<<"The total balance due is: $"<<setw(5)<<totBal<<endl;
        }  
    }
    //Next if statement if amount is greater than $1000
    else if(accBal>1000)
    {
        //Process values map inputs to outputs
        tmpBal1=(1000*INTRST1); //Interest for first $1000
        tmpBal2=(accBal-1000)*INTRST2; //Interest for everything over $1000
        totBal=accBal+tmpBal1+tmpBal2;
        cout<<"The interest due is: $"<<tmpBal1+tmpBal2<<endl;
        cout<<"The minimum payment is: $"<<totBal/10<<endl;
        cout<<"The total balance due is: $"<<totBal<<endl;
    }

    //Exit program
    return 0;
}

