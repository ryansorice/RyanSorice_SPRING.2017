
 /* Author: Ryan Sorice
  * 
  * Created on 14 September 2016
  * 
  * Purpose: To write a program that allows the user to enter a number of
  *         quarters, dimes and nickels and then outputs the monetary value of the
  *         coins in cents.
  */

//System Libraries
#include <iostream>

using namespace std; //namespace used in system library

//Execution begins here...
int main(int argc, char** argv) {
    //Declaration of variables
    float x, y, z, nick, dime, quart, cents;
    
    //Displays output and asks user for input values
    cout<<"Welcome! What are your coins? "<<endl;
    cout<<"How many nickels?"<<endl;
    cin>>x;
    cout<<"How many dimes?"<<endl;
    cin>>y;
    cout<<"How many quarters?"<<endl;
    cin>>z;
    
    //Process values for nickels, dimes, and quarters.
    nick=x*5;
    dime=y*10;
    quart=z*25;
    
    //Process of getting total change
    cents=nick+dime+quart;
    
    //Outputs total change
    cout<<"Your change is "<<cents<<" cents!";
    
    //Exit program.
    return 0;
}

