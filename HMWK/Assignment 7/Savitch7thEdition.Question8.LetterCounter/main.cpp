/* File: main
 * Author: Ryan Sorice
 * Created on 1 December 2016 2:37 PM
 * Purpose: Count occurrences of each letter in an array; inputed by user
 */

//System Libraries
#include <iostream>
#include <cstdlib>

using namespace std;                //Name-space in system libraries

//User Libraries

//Global Variables

//Function Prototypes
void fillAry(char [],int);
void repeats(char [], int[], int);
void rvrsSrt(char [], int);
void newSort(char [], int [], int);

//Execution begins here
int main(int argc, char** argv) {
    //Declaration/Initiation of variables
    int const SIZE=50;
    char sent[SIZE];
    int count[SIZE];

    fillAry(sent,SIZE);
    rvrsSrt(sent,SIZE);
    for(int n=0;n<SIZE;n++){
        if(sent[n]<'a'||sent[n]>'z') n=SIZE;
        else cout<<sent[n]<<endl;
    }
    repeats(sent,count,SIZE);
    for(int n=0;n<SIZE;n++) {
        if(sent[n]<'a'||sent[n]>'z') n=SIZE;
        else cout<<sent[n]<<"   "<<count[n]<<endl;
    }
    //Exits program
    return 0;
}

void rvrsSrt(char numbs[], int size){                //Function to sort array Greatest to Least
    for(int n=0;n<size-1;n++){                      //Loop to process each value of array
        for(int m=n+1;m<size;m++){                  //Nested loop to compare each array value to previous value
            if(numbs[n]<numbs[m]){                  //If original array value less than current; perform swap
                numbs[n]=numbs[n]^numbs[m];
                numbs[m]=numbs[n]^numbs[m];
                numbs[n]=numbs[n]^numbs[m];
            }
        }
    }
}
void repeats(char sent[], int reap[], int size){    //Function to count/delete Repeats
    for(int n=0;n<size;n++){                        //Loop to process each variable of array
        if(sent[n]==0)n=size;                      //If all integers have been processed; end loop
        else{                                       //Else delete current array and fill new array
            int counter=1;                          //Counter for each integer in first array
            for(int m=n+1;m<size;m++){              //Nested Loop for each integer in the array
                if(sent[m]==sent[n]) {            //If next integer equals original loop integer value
                    counter++;                      //Add 1 to counter value
                    sent[m]=0;                     //Change array value to 0 (deleted)
                }
            }
            rvrsSrt(sent,size);                    //Resort array each time in case of any zeros 
            reap[n]=counter;                        //Sets new array value to counter value to count original array 
        }                                           //integers
    }
}

void fillAry(char sent[], int size){
    cout<<"Enter your sentence/characters with NO SPACES (no greater than 50)\n";
    cin>>sent;        
}