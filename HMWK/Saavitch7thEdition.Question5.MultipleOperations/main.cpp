/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Author:Ryan Sorice
 * Created on 15 September 2016
 * Purpose: Write a C++ program that reads in two integers and then outputs
 * both their sum and their product.
 * 
 * (I did all 4 standard operations)
 */

//System Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    int x,y;
    
    //Displays first output and asks user for two inputs
    cout<<"What is your first number?"<<endl;
    cin>>x;
    cout<<"What is your second number?"<<endl;
    cin>>y;
    
    //Executes each operation and displays outputs
    cout<<x<<" + " <<y<<" = "<<x+y<<endl;
    cout<<x<<" - " <<y<<" = "<<x-y<<endl;
    cout<<x<<" * " <<y<<" = "<<x*y<<endl;
    cout<<x<<" / " <<y<<" = "<<x/y<<endl;
    

    //Exits program
    return 0;
}

