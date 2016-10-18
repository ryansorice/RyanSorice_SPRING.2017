/* File: main
 * Author: Ryan Sorice
 * Created on 10 October 2016 8:51 AM
 * Purpose: Write a program that computes the value of stock to the nearest
 *          eighth of a number.                                             */

//System libraries
#include <iostream> //Inputs and outputs

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    int nmrtr, //Numerator of fractional of individual share value
        dnmntr, //Denominator of fractional of individual share value
        shares; //Amount of shares user holds
    float whole, //Whole number of individual share value
          nfrac, //Amount of the fractional multiplied by the shares
          rmndr, //Remainder of the fractional multiplied by the shares
          wDollar; //Whole number of individual share value 
    char yesno='y'; //Variable for loop true/false
    
    //Initial output
    cout<<"This program will compute the current value of your stock!\n";
    
    //Loop to allow user to run program til user enters false
    //'y' 'Y' true, else false
    while(yesno=='y'||yesno=='Y'){
        //Output to user; Initialize variables
        cout<<"How many shares of stock do you own?\n";
        cin>>shares;
        cout<<"What is the whole dollar portion of the price of the shares?\n";
        cin>>wDollar;
        cout<<"Now enter the fractional portion of the price of the shares in eighths.\n";
        cout<<"What is the numerator of the fraction portion of the price of the shares?\n";
        cin>>nmrtr;
        cout<<"What is the denominator of the fraction portion of the price of the shares?\n";
        cin>>dnmntr;

        //Processing values
        whole=wDollar*shares;
        nfrac=(nmrtr*shares)/dnmntr; //Fraction portion that gets added to the whole
        rmndr=(nmrtr*shares)%dnmntr; //Remainder of fraction portion

        //If statement if no remainder
        if(rmndr==0){
            //Output value of stock without remainder
            cout<<"The value of your stock is $"<<whole+nfrac<<endl;
        }
        //Else if there is a remainder
        else{  
            //Output value of stock with remainder
            cout<<"The value of your stock is $"<<whole+nfrac<<" "<<rmndr<<"/"<<dnmntr<<endl;
        }
        //Output to user; initiates loop again or break
        cout<<"Do you have more shares? Enter 'Y'-Yes 'N'-No\n";
        cin>>yesno;
    }
    //Exit program
    return 0;
}

