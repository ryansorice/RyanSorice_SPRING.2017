/* File: main
 * Author: Ryan Sorice
 * Created on  10 October 2016 8:02 AM
 * Purpose: Compute Miles Per Gallon in a vehicle given liters of gasoline and
 *          miles traveled.                                                   */

//System libraries
#include <iostream> //Inputs and outputs

using namespace std; //Namespace in system libraries

//Global constants
float CNGALON=0.264179; //Gallon conversion

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    char yesno='y'; //Counter for loop
    float gasLitr, //Liters of gasoline in user's car
          gallons, //Gallons of gasoline in user's car
          miles, //Miles traveled in user's car
          car1, //Car 1 mpg
          car2; //Car 2 mpg
    
    //Loop to repeat calculation while user says yes
    //'y' 'Y' true, else false
    while(yesno=='y'||yesno=='Y'){
        //Initial output; Initiation of variables
        cout<<"How many liters of gasoline is the first car consuming?\n";
        cin>>gasLitr;
        cout<<"How many miles is this car traveling?\n";
        cin>>miles;
    
        //Process values
        gallons=gasLitr*CNGALON; //Liters to gallons conversion
        car1=miles/gallons; //First car mpg
    
        //Next output to user; Processing mpg of first vehicle
        cout<<"The first car consumed "<<gallons<<" gallons of gasoline.\n";
        cout<<"It traveled at "<<car1<<" mpg.\n"<<endl;

        //Next output; Initiation of variables
        cout<<"How many liters of gasoline is the second car consuming?\n";
        cin>>gasLitr;
        cout<<"How many miles is this car traveling?\n";
        cin>>miles;

        //Process values
        gallons=gasLitr*CNGALON; //Liters to gallons conversion
        car2=miles/gallons; //Second car mpg

        //Next output to user; Processing mpg of first vehicle
        cout<<"The second car consumed "<<gallons<<" gallons of gasoline.\n";
        cout<<"It traveled at "<<car2<<" mpg.\n"<<endl;

        //If statement car 1 better fuel efficiency
        if(car1>car2){
            cout<<"Car 1 has the best fuel efficiency!\n"<<endl;
        }
        //Next if statement car 2 better fuel efficiency
        else if (car1<car2){
            cout<<"Car 2 has the best fuel efficiency!\n"<<endl;
        }
        //Final if statement car 1 same fuel efficiency as car 2
        else{
            cout<<"Wow, the cars have the same fuel efficiency!\n"<<endl;
        }
        //User initiates to continue loop or end program
        cout<<"Would you like to repeat this process? Enter 'Y'-Yes or 'N'-No\n";
        cin>>yesno;
    }
    //Exits program
    return 0;
}

