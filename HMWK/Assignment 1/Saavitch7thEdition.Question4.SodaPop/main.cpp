/* 
 * Author: Ryan Sorice
 *
 * Created on 9 September 2016
 * 
 * Purpose: Write a program that displays the number of soda drinkers and diet 
 *          soda drinkers, Given: number of surveyed people 30,000, percentage 
 *          of soda drinkers 20% and percentage of soda drinkers that drink diet
 *          soda 34%.
 */

//System Library
#include <iostream>   //Input/Output objects
using namespace std;  //namespace used in the system library


//Execution Begins Here!
int main(int argc, char** argv) {
   
    //Declaration of variables and initializations
    float survey=30000; //Amount of customers surveyed
    float soda; //Amount of surveyed customers that drink soda
    float diesoda; //Diet soda drinkers
    unsigned char pSoda=20; //Percentage of soda drinkers
    unsigned char pDsoda=34; //Percentage of diet soda drinkers
    
    //Process values
    soda=survey*pSoda/100; //Processes soda drinkers
    diesoda=soda*pDsoda/100; //Processes diet soda drinkers out of the soda drinkers
    
    //Display ALL Outputs
    cout<<"The number of customers surveyed     =  "<<survey<<endl;
    cout<<"The percentage of soda drinkers      =  "<<static_cast<int>(pSoda)<<"%"<<endl;
    cout<<"The percentage of diet soda drinkers =  "<<static_cast<int>(pDsoda)<<"%"<<endl;
    cout<<"The number of soda drinkers          =  "<<soda<<endl;
    cout<<"The number of diet soda drinkers     =  "<<diesoda<<endl;

    //Exit Program
    return 0;
}