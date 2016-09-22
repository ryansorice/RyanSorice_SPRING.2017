/* 
 * Author: Ryan Sorice
 *
 * Created on 9 September 2016
 * 
 * Purpose: To write a program that reads in a number of candy bars and the weight
 *          of a single candy bar and computes total weight of all candy bars. Then,
 *          repeat the process with new values and give a combined weight of both
 *          candy bar weight totals.
 */

//System Libraries
#include <iostream> //Outputting/Inputting
#include <iomanip>  //Formatting

using namespace std; //namespace used in library

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of varibales
    short cbars; //Number of candy bars
    float weight; //Weight of a single candy bar
    float tWeight; //Total weight of candy bars
    
    //Displays outputs and asks user to initialize first round of inputs
    cout<<"Enter the number of candy bars in your package.\n";
    cin>>cbars;
    cout<<"Enter the weight, in ounces, of a single candy bar.\n";
    cin>>weight;
    
    //Processes values for total weight
    tWeight=cbars*weight;
    
    //First round of candy bar outputs
    cout<<"The number of candy bars   = "<<cbars<<endl;
    cout<<"The weight in ounces       = "<<weight<<endl;
    cout<<"The total weight in ounces = "<<tWeight<<endl<<endl;
    
    //Displays outputs and asks user to initialize second round of inputs
    cout<<"Try a second package!"<<endl;
    cout<<"Enter the number of candy bars in your package.\n";
    cin>>cbars;
    cout<<"Enter the weight, in ounces, of a single candy bar.\n";
    cin>>weight;
    
    float pWeight; //Total weight of second round candy bars
    
    //Processes second round values for total weight
    pWeight=cbars*weight;
    
    //Second round of candy bar outputs
    cout<<"The number of candy bars   = "<<cbars<<endl;
    cout<<"The weight in ounces       = "<<weight<<endl;
    cout<<"The total weight in ounces = "<<pWeight<<endl<<endl;
    
    //Final output
    cout<<"The total weight of both packages, in ounces, is "<<pWeight+tWeight<<"."<<endl;

    //Exits program
    return 0;
}

