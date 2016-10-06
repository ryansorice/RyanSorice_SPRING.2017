/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 5 October 2016 8:46 PM
 * 
 * Purpose: Write a program that computes the Bouyant force on a sphere in water,
 *          outputting whether it will sink or float.
 */

//System libraries
#include <iostream>

using namespace std; //Namespace in system library

//Global variables
const float y=62.4,
            PI=3.1415;

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    float weight, //Weight of the sphere
          radius, //Radius of sphere
          byntFrc, //Bouyant force acting on the sphere
          volume; //Volume of the sphere
    
    
    //Initial output to user; Variable initiation
    cout<<"What is the weight of your sphere?\n";
    cin>>weight;
    cout<<"Now, what is the radius?\n";
    cin>>radius;
    
    //Processing of variables
    volume=(4/3)*PI*radius*radius*radius; //Calculates volume
    byntFrc=volume*y; //Calculates bouyant force
    
    //If statement if the sphere floats; Bouyant force >= weight
    if(byntFrc>=weight)
    {
        cout<<"Your sphere will float!\n";
    }
    //Else the sphere sinks; Bouyant force < weight
    else
    {
        cout<<"Sorry, your sphere will sink.\n";
    }

    //Exits program
    return 0;
}

