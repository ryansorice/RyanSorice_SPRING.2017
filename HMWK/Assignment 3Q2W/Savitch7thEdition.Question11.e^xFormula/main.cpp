/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 5 October 2016, 9:17 PM
 * 
 * Purpose: Use formula to calculate e^x
 */

//System libraries 
#include <iostream>
#include <cmath>

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {

    //Declaration of variables
    float x, //Exponential of e
          n=1, //Counter to run algorithm for e^x
          fact=1, //Variable for divider factorial
          power,
          e,
          e2=1;
    
    //Initial output;Initiation variable x
    cout<<"Lets solve e^x. Enter a value for x.\n";
    cin>>x;
    
    while(n<=100)
    {
        int c=1;
        while(c<=n){
        fact=fact*n;
        power=pow(x,n);
        e=power/fact;
        e2=e2+e;
        
        n++;
    }
    cout<<e2<<endl;
    cout<<exp(x);
    //Exit program
    return 0;
}

