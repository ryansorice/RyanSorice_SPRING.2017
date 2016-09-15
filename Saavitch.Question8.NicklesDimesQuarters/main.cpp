
 /* Author: Ryan Sorice
 * Created on 09/14/16
 * Purpose: To write a program that allows the user to enter a number of
   quarters, dimes and nickles and then outputs the monetary value of the
   coins in cents.
 * 
 */

//System Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//Execution begins here...
int main(int argc, char** argv) {
    //Declaration of variables
    float x, y, z, nick, dime, quart, cents;
    
    //Displays output and asks user for input values
    cout<<"Welcome! What are your coins? "<<endl;
    cout<<"How many nickles?"<<endl;
    cin>>x;
    cout<<"How many dimes?"<<endl;
    cin>>y;
    cout<<"How many quarters?"<<endl;
    cin>>z;
    
    //Process values for nickles, dimes, and quarters.
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

