/* File: main
 * Author: Ryan Sorice
 * Created on November 2016 1:25 PM
 * Purpose: Count all repeated numbers in an array
 */

//System libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;                //Name-space in system libraries

//User Libraries

//Global variables

//Function prototypes
void fillAry(int [], int);          //Function to fill array with random integers 1-25
void rvrsSrt(int [], int);          //Function to sort array from greatest to least
void repeats(int [], int[], int);   //Function to count/delete repeats in array/new array

//Execution begins here
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration/Initiation of variables
    int const SIZE=50;                              //Array size variable
    int numbs[SIZE],reap[SIZE];                     //Arrays for random integers and for counting repeats
    
    fillAry(numbs,SIZE);                            //Fills array with random integers from 1-25
    rvrsSrt(numbs,SIZE);                            //Sorts the array from largest to greatest
    
    for(int n=0;n<SIZE;n++) cout<<numbs[n]<<endl;   //Loop that prints initial array values
    
    repeats(numbs,reap,SIZE);                       //Deletes repeats in array and fills new array
                                                    //with repeat count number for each integer
    cout<<" N Count\n";
    for(int n=0;n<SIZE;n++) {                       //Loop to print out integer values and number of repeats                   
        if(numbs[n]==0) n=SIZE;                     //If the arrays get to the last number, ends loop
        else cout<<numbs[n]<<" "<<reap[n]<<endl;    //Else print out array values
    }
    //Exits program
    return 0;
}
void repeats(int numbs[], int reap[], int size){    //Function to count/delete Repeats
    for(int n=0;n<size;n++){                        //Loop to process each variable of array
        if(numbs[n]==0)n=size;                      //If all integers have been processed; end loop
        else{                                       //Else delete current array and fill new array
            int counter=1;                          //Counter for each integer in first array
            for(int m=n+1;m<size;m++){              //Nested Loop for each integer in the array
                if(numbs[m]==numbs[n]) {            //If next integer equals original loop integer value
                    counter++;                      //Add 1 to counter value
                    numbs[m]=0;                     //Change array value to 0 (deleted)
                }
            }
            rvrsSrt(numbs,size);                    //Resort array each time in case of any zeros 
            reap[n]=counter;                        //Sets new array value to counter value to count original array 
        }                                           //integers
    }
}
void rvrsSrt(int numbs[], int size){                //Function to sort array Greatest to Least
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
void fillAry(int numbs[], int size){                //Fill Array Function
    for(int n=0;n<size;n++) numbs[n]=rand()%25+1;   //Loop to fill each array value with random integers 1-25
}