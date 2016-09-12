/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ryan Sorice
 *
 * Created on September 12, 2016, 10:27 AM
 * Purpose :Calculate the distance dropped in free fall. 
 */
//system libraries
#include <iostream>
#include <cmath>

using namespace std;
//Global constants
const float GRAVITY=32.174;

/*
 * 
 */
int main(int argc, char** argv) {
    
    float time; //times as input in seconds
    float disFell; //Distance in free fall
    int places; //Places to round the answer
    
    //input values
    cout<<"This problem determines distance dropped in free-fall"<<endl;
    cout<<"Input the time in free-fall, units of seconds"<<endl;
    cin>>time;
    cout<<"How many decimal places to round the result"<<endl;
    cin>>places;
    
    //Process values; map inputs to outputs
    disFell=GRAVITY*time*time/2;
    float shift=pow(10,places); //number of places to shift answer
    int round=disFell*shift+0.5;
    disFell=round/shift;
    //Display output
    cout<<"Gravity "<<GRAVITY<< " ft/sec^2"<<endl;
    cout<<"Time fallen "<<time<< " seconds"<<endl;
    cout<<"Distance traveled "<<disFell<<" ft"<<endl;
    
    //Exit program
    return 0;
}

