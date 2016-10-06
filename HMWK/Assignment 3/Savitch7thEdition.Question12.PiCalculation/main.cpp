/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 5 October 2016 8:03 PM
 * 
 * Purpose: Calculate Pi to the given nth term
 */

//System libraries
#include <iostream>
#include <cmath>

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration/Initiation of variables
    int n, //Number of times to process formula for PI
        i=0; //Loop counter
    float pi=0, //Holder value of PI
          prePi; //Processes inside algorithm of PI formula
    
    //Initial output to user;n initiation
    cout<<"Enter how many times you would like to add a calculation to Pi.\n";
    cin>>n;
    
    //Loop to process PI, n times
    while(i<n)
    {
    prePi=pow(-1,i)/(2*i+1);
    pi=pi+prePi;
    i++;
    }
    
    //Final output of the value of pi
    cout<<pi*4<<endl;
 
    //Exits program
    return 0;
}

