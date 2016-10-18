/* File: main
 * Author: Ryan Sorice
 * Created on 16 October 2016 5:12 PM 
 * Purpose: Calculate after-tax cost of the first year annual cost of a new
 *          house w/ respects to: loan/interest rates, mortgage costs, tax
 *          savings.(Repeat as long as user likes)                          */

//System libraries
#include <iostream> //Inputs and outputs

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {

    //Declaration of variables
    char yesno='y'; //Loop variable 
    float houseP, //Total price of user's house
          downPay, //User's down payment on house
          annMort, //Annual mortgage cost
          taxSvgs, //Tax savings on cost of house
          loanBal, //Initial loan balance
          cost; //Total house cost of first year
    
    //Initial output; Variable initiation
    cout<<"This program will compute the total annual cost for the first\n";
    cout<<"year of your new home.\n";
    
    //Loop to allow user to utilize program until they say no
    //('Y' 'y' true, else false)
    while(yesno=='y'||yesno=='Y'){
        //Output; Variable initiation
        cout<<"What is the total cost of your house?\n";
        cin>>houseP;
        cout<<"Now, what was your down payment?\n";
        cin>>downPay;

        //Process variables
        loanBal=houseP-downPay; //Initial loan balance (house payment less down payment)
        annMort=(loanBal*0.03)+(loanBal*0.06); //Annual Mortgage (3% of loan balance + 6% l.b.)
        taxSvgs=(0.35*(loanBal*0.06)); //Tax savings (35% of interest paid)
        cost=annMort-taxSvgs; //Total first year cost (annual mortgage less tax savings)

        //Final output; Loop initiation/break
        cout<<"The annual cost for the first year of your new home is $"<<cost<<endl<<endl;
        cout<<"Would you like enter a new house cost and down payment?\n";
        cout<<"Enter 'Y'-Yes or 'N'-No\n";
        cin>>yesno; 
    }        
    //Exits program
    return 0;
}

