/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 27 September 2016 5:07 PM
 * 
 * Purpose: Write a program that reads in 10 whole numbers and outputs the sum of all numbers
 *          greater than zero, the sum of all numbers less than zero and the sum of ALL numbers.
 *          The program should also output the average of all positive numbers, the average of all
 *          negative numbers and zeros, and the average of ALL the numbers.
 * 
 */

//System libraries
#include <iostream>
#include <iomanip>

using namespace std; //namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration and initiation of variables
    short counter=0, //Counter for loop
          countP=0, //Counter for positive numbers
          countN=0; //Counter for negative numbers
    float posNegZ, //Whole numbers input by user
          posSum=0, //Postive sum
          negSum=0, //Negative sum
          totSum=0, //Total sum
          avgTot, //Total average
          avgPos, //Average of positive numbers
          avgNeg; //Average of negative numbers
    
    //Loop to separate positive and negative numbers
    while(counter<10)
    {
        //First output to user who is initializing the variable each time through
        cout<<"Input a whole number.\n";
        cin>>posNegZ;
        
        //If statement that takes all positive whole numbers
        if(posNegZ>0)
        {
            posSum=posSum+posNegZ;//Processing sum of each positive number to the total sum
            countP++;
            
        }
        
        //Second if statement that takes all negative whole numbers and zeros
        else if(posNegZ<=0)
        {
            negSum=negSum+posNegZ;//Processing sum of each negative number and zero to the total sum
            countN++;
        }
        totSum=totSum+posNegZ;//Processing sum of ALL numbers to total sum
        counter++;//Counter to end loop at 10 numbers entered
        
    }
    
    //Processing of all averages
    avgPos=posSum/countP; //average of positive whole numbers
    avgNeg=negSum/countN; //average of negative numbers and zeros
    avgTot=totSum/counter; //average of ALL numbers
    
    //Final output to user with all sum totals
    cout<<"The sum of the positive numbers is                 : "<<setw(6)<<posSum<<".\n";
    cout<<"The average of the positive numbers is             : "<<setw(6)<<avgPos<<".\n"<<endl;
    cout<<"The sum of the negative numbers and zeros is       : "<<setw(6)<<negSum<<".\n";
    cout<<"The average of the negative numbers and zeros is   : "<<setw(6)<<avgNeg<<".\n"<<endl;
    cout<<"The total sum of ALL the numbers is                : "<<setw(6)<<totSum<<".\n";
    cout<<"The average of ALL the numbers is                  : "<<setw(6)<<avgTot<<".\n";

    //Exits program
    return 0;
}

