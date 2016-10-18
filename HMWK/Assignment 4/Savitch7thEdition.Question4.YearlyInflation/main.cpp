/* File: main
 * Author: Ryan Sorice
 * Created on 11 October 2016 6:38 PM
 * Purpose: Calculate inflation rate of an item; then calculate inflation for
 *          set number of years.                                             */

//System libraries
#include <iostream> //Inputs and outputs

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    float curPric, //Current price
          oldPric, //Price 1 year ago
          inflat, //Inflation rate of item
          years; //Number of years to produce inflated price
    short n=1;
    
    //Initial output/Variables initialization
    cout<<"This program will give you the inflation rate and inflated price of\n";
    cout<<"any item!\n";
    cout<<"What is the current price of your item?\n";
    cin>>curPric;
    cout<<"What was the price of your item one year ago?\n";
    cin>>oldPric;
    cout<<"How many years would you like to calculate inflation on this item?\n";
    cin>>years;
    
    //Process inputs
    inflat=(curPric-oldPric)/oldPric;
    
    //Output of inflation rate
    cout<<"The inflation rate on your item is "<<inflat*100<<"%\n";
    
    //Loop for inflation price for specified years
    for(; n<=years; n++){
        //Process and output inflation price each year
        curPric=(curPric*inflat)+curPric;
        cout<<"The price in "<<n<<" year(s) is $"<<curPric<<endl;
    }
    //Exits program
    return 0;
}

