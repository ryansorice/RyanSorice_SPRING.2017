/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 27 September 2016 7:18 PM
 * 
 * Purpose: Write a program that allows user to read in the amount of a loan on an item
 *          and the amount of annual interest on that item, then outputs how many months
 *          it will take to pay off the loan, as well as the total amount of interest paid 
 *          over the life of the loan.
 */


//System libraries
#include <iostream>
#include <cmath>

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    float loan, //Loan amount
          payment, //Amount paid per month
          intAnl, //Annual interest rate
          intMon, //Monthly interest rate
          months=0, //Amount of months to pay off loan
          intOwed, //Interest owed per month
          loanPay, //Loan balance payment per month
          totInt=0, //Total interest paid
          intFrac; //Fractional monthly interest rate
    
    //Initial output to user and initiation of variables
    cout<<"What is the amount of the loan on your item?\n";
    cin>>loan;
    cout<<"How much will you be paying per month on your loan?\n";
    cin>>payment;
    cout<<"Now, what is the annual interest rate on your loan?\n";
    cin>>intAnl;
    
    //Processing of variables for interest rate
    intMon=intAnl/12; 
    intFrac=intMon/100;
    
    //First if statement to determine if the loan will accrue interest before being paid off
    if(payment>=loan)
    {
        cout<<"Congratulations you were able to pay off your loan before any interest was accrued!\n";
    }
    //Second if statement if interest must be paid on the loan
    else if(payment<loan)
    {
        //Loop to process interest and payments until the loan is less than or equal to zero
        while(loan>0)
            {
            intOwed=loan*intFrac; //Processing monthly interest payment
            loanPay=payment-intOwed; //Processing monthly loan payment
            totInt=totInt+intOwed; //Processing total interest until loan is paid off
            loan=loan-loanPay; //Processing the value of the loan after each payment
            months++; //Adds 1 month for each successful pass in the loop
            }
        
        int places=2; //Decimal places for total interest paid
        float shift=pow(10,places); //Number of places to shift answer
        int round=totInt*shift+0.5; //Rounds the total interest paid to two decimals
        totInt=round/shift; //Shifts answer back
    
        //Final output
        cout<<"The amount of total interest to be paid is $"<<totInt<<".\n";
        cout<<"It will take "<<months<<" months to pay off the loan.\n";
    }
    
    //Exits program
    return 0;
}

