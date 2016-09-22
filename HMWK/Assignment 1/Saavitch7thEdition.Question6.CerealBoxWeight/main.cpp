/* Author: Ryan Sorice
 *
 * Created on 11 September 2016
 * 
 * Purpose: Write a program that will read the weight of a package of breakfast 
 *          cereal in ounces and output the weight in metric tons, given a ton is 
 *          35,273.92 ounces. It will also give the number of boxes needed to 
 *          yield one metric ton of cereal.
 */

//System libraries
#include <iostream>

using namespace std; //namespace used in system library

//Global Constants
const float CNVTON=35273.92; //Conversion ounces to tons

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    float crlOncs; //Cereal weight ounces
    float crlTons; //Cereal weight tons
    int crlBxs;    //Unadjusted amount of cereal boxes to make a ton
    float round;   //Adjusted amount of cereal boxes to make a ton
    
    //First output, asks user to read in cereal weight in ounces
    cout<<"What is the weight, in ounces, of your cereal box?\n";
    cin>>crlOncs;
    
    crlTons=crlOncs/CNVTON; //Converts inputted ounces to tons
    crlBxs=CNVTON/crlOncs;  //Gives rounded down number of cereal boxes to make a ton
    round=crlBxs+1;         //Gives actual needed boxes to make a ton
    
    //Finals outputs
    cout<<"The weight of your cereal is "<<crlTons<<" metric tons.\n"<<endl; //Tells the user the weight in tons
    cout<<"The number of cereal boxes to make one metric ton is "<<round<<"."<<endl;//Tells user amount of boxes to make a ton
    
    //Exits Program
    return 0;
}

