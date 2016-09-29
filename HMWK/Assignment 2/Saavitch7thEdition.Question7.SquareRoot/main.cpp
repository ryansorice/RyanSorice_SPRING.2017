/* 
 * File:   main
 * 
 * Author: Ryan Sorice
 * 
 * Created on 28 September 2016 1:32 PM
 *
 * Purpose:  Babylonian Algorithm for Square Root
 */

//System Libraries
#include <iostream>   //Input/Output objects
#include <cmath>      //Square Root Function
using namespace std;  //Name-space used in the System Library

//Execution Begins Here!
int main(int argc, char** argv) {
    
    //Declaration of Variables
    float n,guess,r;
    short counter=0;
    
    //Display the Initialization
    cout<<"What number would you like the square root of?\n";
    cin>>n;
    cout<<"What is YOUR guess?\n";
    cin>>guess;
    
    //First Pass
    r=n/guess;
    guess=(guess+r)/2;
    counter+=1;
    //Display Output
    cout<<"Pass "<<counter<<"  [r,guess]=["<<r<<","<<guess<<"]"<<endl;
        
    //Second Pass
    r=n/guess;
    guess=(guess+r)/2;
    counter+=1;
    //Display Output
    cout<<"Pass "<<counter<<"  [r,guess]=["<<r<<","<<guess<<"]"<<endl;
    
    //Next Pass
    r=n/guess;
    guess=(guess+r)/2;
    counter+=1;
    //Display Output
    cout<<"Pass "<<counter<<"  [r,guess]=["<<r<<","<<guess<<"]"<<endl;
    
    //Next Pass
    r=n/guess;
    guess=(guess+r)/2;
    counter+=1;
    //Display Output
    cout<<"Pass "<<counter<<"  [r,guess]=["<<r<<","<<guess<<"]"<<endl;

    //Next Pass
    r=n/guess;
    guess=(guess+r)/2;
    counter+=1;
    //Display Output
    cout<<"Pass "<<counter<<"  [r,guess]=["<<r<<","<<guess<<"]"<<endl;
    
    //The answer or solution is
    cout<<"The sqrt("<<n<<")= "<<sqrt(n)<<endl;

    //Exit Program
    return 0;
}