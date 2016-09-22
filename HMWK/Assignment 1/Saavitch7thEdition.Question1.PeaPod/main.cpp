/* 
 * Author: Ryan Sorice
 * 
 * Created on 19 September 2016
 * Purpose: Enter the C++ program shown in Display 1.8. Compile and run the
 *          program. If the compiler gives an error message, correct the program
 *          and recompile the program. 
 */

//System libraries
#include <iostream> //Inputs/Ouputs objects

using namespace std; //namespace used in system library

//Execution begins here
int main() {

    //Declaration of variables
    int np_pod; //Number of pea pods
    int pp_pod; //Number of peas per pod
    int t_pea;  //Number of total peas
    
    //Displays first output to user
    cout<<"Press return after entering a number.\n"; //Makes sure user hits 'enter' after typing a number
    cout<<"Enter the number of pods:\n"; //Asks for pea pod amount
    cin>>np_pod; //Input for amount of pea pods
    cout<<"Enter the number of peas in a pod:\n"; //Asks for pea amount in pods
    cin>>pp_pod; //Input for amount of peas per pod
    
    t_pea=np_pod*pp_pod; //Solves for total amount of peas in all the pea pods
    
    //Displays final output.
    cout<<"If you have ";
    cout<<np_pod; //Displays number of pods
    cout<<" pea pods\n";
    cout<<"and ";
    cout<<pp_pod; //Displays number of peas per pod
    cout<<" peas in each pod, then\n";
    cout<<"you have ";
    cout<<t_pea; //Displays total number of peas
    cout<<" peas in all the pods.\n";
    //Exits program
    
    return 0;
}

