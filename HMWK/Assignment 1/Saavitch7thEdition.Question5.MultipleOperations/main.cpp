/* 
 * Author:Ryan Sorice
 * Created on 15 September 2016
 * Purpose: Write a C++ program that reads in two integers and then outputs
 *          both their sum and their product.
 * 
 *          (I did all 4 standard operations and included power function)
 */

//System Libraries
#include <iostream> //Input/Output objects
#include <cmath> //Math library for power function

using namespace std; //namespace utilized in system library

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    float x,y;
    
    //Displays first output and asks user for two inputs
    cout<<"What is your first number?"<<endl;
    cin>>x; //First integer to be computed
    cout<<"What is your second number?"<<endl;
    cin>>y; //Second integer to be computed
    
    //Executes each operation and displays outputs
    cout<<x<<" + "<<y<<" = "<<x+y<<endl; //Addition
    cout<<x<<" - "<<y<<" = "<<x-y<<endl; //Subtraction
    cout<<x<<" * "<<y<<" = "<<x*y<<endl; //Multiplication
    cout<<x<<" / "<<y<<" = "<<x/y<<endl; //Division
    cout<<x<<" ^ "<<y<<" = "<<pow(x,y);  //First integer raised to the power of second integer
    

    //Exits program
    return 0;
}

