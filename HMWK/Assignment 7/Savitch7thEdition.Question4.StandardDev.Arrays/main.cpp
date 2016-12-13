/* File: main
 * Author: Ryan Sorice
 * Created on November 2016 1:24 PM
 * Purpose: Calculate standard deviation of an array of numbers
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;        //Name-space in system libraries

//User Libraries

//Global Variables

//Function Prototypes
void fillAry(float [], int);
void stndDev(float [], int);

//Execution begins here
int main(int argc, char** argv) {
    //Declaration of variables
    int temp;
    
    //Initial output; Variable initiation
    cout<<"How many numbers will you be using to compute the standard deviation?\n";
    cin>>temp;
    
    //Declare array variables
    int const SIZE=temp;
    float numbs[SIZE+1];
    
    //User fills array with values
    fillAry(numbs,SIZE);
    
    //Computes standard deviation from array values
    stndDev(numbs,temp);
    
    //Final output
    cout<<"The standard deviation of ";
    for(int n=0;n<SIZE;n++) cout<<numbs[n]<<" ";
    cout<<" = "<<numbs[temp+1];
    
    //Exits program
    return 0;
}
void stndDev(float numbs[], int temp){
    float mean=0,stndDev=0;
    for(int n=0;n<temp;n++) mean+=numbs[n];
    mean/=temp;
    for(int n=0;n<temp;n++) stndDev+=pow((numbs[n]-mean),2);
    stndDev/=temp;
    stndDev=sqrt(stndDev);
    numbs[temp+1]=stndDev;
}

void fillAry(float numbs[], int size){
    for(int n=0;n<size;n++) {
        cout<<"Enter number: ";
        cin>>numbs[n];
    }
}    
