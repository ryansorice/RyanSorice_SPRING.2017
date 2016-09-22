/* 
 * Author: Ryan Sorice
 *
 * Created on 16 September 2016
 * 
 * Purpose: Write a program that reads in a distance, in miles, and outputs the 
 *          time it takes to travel that distance, in hours. Program should also 
 *          output the amount spent on gas.
 */

//System libraries
#include <iostream> //Inputting/Outputting
#include <cmath> //math library for power function

using namespace std; //namespace used in library

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration and initialization of variables
    float miles, speed, cost, time;
    short mpg=20; //miles per gallon of vehicle
    float gas=2.67; //cost of fuel per gallon
    
    //Initial output;asks user for variable initialization
    cout<<"How many miles are you driving?\n";
    cin>>miles;
    cout<<"What speed will you be traveling?\n";
    cin>>speed;
    
    //Processing of values
    cost=miles/mpg*gas; //Total cost of gas needed
    time=miles/speed; //Distance traveled
    float shift=pow(10,2); //Number of places to shift answer
    int round=time*shift+0.5; //Round to nearest 10^places
    time=round/shift; //Shifts result back
    round=cost*shift+0.5; //Round to nearest 10^places
    cost=round/shift; //Shifts result back
    
    //Final output of processed values
    cout<<"It will take you "<<time<<" hours to travel "<<miles<<" miles.\n";
    cout<<"It will cost you $"<<cost<<"."<<endl;

    //Exits program
    return 0;
}

