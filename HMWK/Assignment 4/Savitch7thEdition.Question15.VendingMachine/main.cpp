/* File: main
 * Author: Ryan Sorice
 * Created on 16 October 2016 12:22 PM
 * Purpose: User enters their change into vending machine coin by coin until 
 *          amount for Deep-Fried Twinkie is achieved; Outputs change, if any.*/

//System libraries
#include <iostream>

using namespace std; //Namespace in system library

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    float coin, //Currency user enters
          n=0; //Holder for loop/total money entered in vending machine
    
    //Initial output
    cout<<"Get your hot and fresh, Deep-Fried Twinkies here! Only $3.50!\n"<<endl;
    
    //Loop for calculating change until enough has been entered for a twinkie
    while(n<3.5)
    {
        //Output; Variable initiation
        cout<<"Enter your coin.(1 = Dollar,0.25 = Quarter, 0.10 = Dime, 0.05 = Nickel.\n";
        cout<<"No pennies allowed!\n";
        cin>>coin;
        //Process variables
        n=n+coin; //Total amount of coins entered
        cout<<"Your current total is $"<<n<<endl; //Output current total
    }
    //Final output if user receives change
    if(n>3.5){
        cout<<"Enjoy your Deep-Fried Twinkie!\n";
        cout<<"Your change is $"<<(n-3.5)<<endl;
    }
    //Final output if no change to be received
    else{
        cout<<"Enjoy your Deep-Fried Twinkie!\n";
    }
    //Exits program
    return 0;
}

