/* File: main
 * 
 * Author: Ryan Sorice
 * 
 * Created on 28 September 2016 4:53 PM
 * 
 * Purpose: To calculate the volume of a sphere given radius. In the book, it is to show
 *          proper formatting techniques with respect indentation, commenting, constants, 
 *          etc., on a pre-written program.
 */

//System library
#include <iostream>

using namespace std; //Namespace in system library

//Global constants
const float PIE=3.1415; 

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    const float fractl=4/3;
    float radius, //Radius of sphere
          vm; //Volume of sphere
    
    //Initial output to user;initialization of variable
    cout<<"Enter radius of a sphere.\n";
    cin>>radius;
    
    //Processing of variables
    vm=fractl*PIE*radius*radius*radius;
    
    
    //Final out to user
    cout<<"The volume is "<<vm<<".\n"; //Outputs the volume of the sphere

    //Exits program
    return 0;
}

