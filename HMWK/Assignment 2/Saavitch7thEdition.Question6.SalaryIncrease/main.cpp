/*
 * File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 26 September 2016 6:40 PM
 * 
 * Purpose: Write a program that takes an employees  previous annual salary
 *          as input, and outputs the amount of retroactive pay due to the employee(7.5%),
 *          the new annual salary and the new monthly salary, for any number of 
 *          months inputted by the user. Should be able to be calculated for any number 
 *          of employees entered by the user.
 */

//System Library
#include <iostream>

using namespace std; //namespace in system library

//Execution begins here
int main(int argc, char** argv) 
{
    //Declaration/Initiation of variables for counting/number of employees
    short count=1, //Counter for loop
          nSalary; //Amount of employees getting increase (amount of times to run the program)
   
    //First output to user
    cout<<"How many employee's are getting the 7.5% retroactive increase in their pay?\n";
    cin>>nSalary; //number of employees getting pay increase
    
    //Loop to determine each employees individual salary changes
    while(count<=nSalary)
    {
        //Declaration of variables
        float incom, //Salary of each employee
              twelveM, //1 month of employees current salary
              newInc,  //Employees new overall income with retroactive increase
              perMon, // 1 month of retroactive pay with 7.5% increase
              months, //Months of the raise
              payInc; //7.5% pay increase for one month
    
        //Output to user for each employee's income and months to be increased
        cout<<"What is the employee's current salary?"<<endl;
        cin>>incom; //Income amount
        cout<<"How many months will this employee receive a pay increase?"<<endl;
        cin>>months; //Months of retroactive pay increase
        
        //If statement to define no more than 12 months in a year;no less than 1 month
        if(months>0&&months<13)
        {
            //Processing of values
            twelveM=incom/12; 
            payInc=twelveM*0.075; 
            perMon=payInc+twelveM; 
            newInc=payInc*months+incom; 
            
            //Outputs results for employees salary increases
            cout<<"The employee was making $"<<incom<<" annually."<<endl;
            cout<<"The employee is owed $"<<payInc*months<<" for "<<months<<" months of their salary."<<endl;
            cout<<"This means the employee will receive $"<<perMon<<" per month, for the next "<<months<<" months."<<endl;
            cout<<"The employee has a new annual salary of $"<<newInc<<endl;
            count++; //Adds count to itself to keep track of employees 
        }
        
        //Else statement to restart loop; does not increase count 
        else
        {
            cout<<"That is not a valid amount of months. Enter a number between 1 and 12.\n";
        }
    }
    //Exits program
    return 0;
}

