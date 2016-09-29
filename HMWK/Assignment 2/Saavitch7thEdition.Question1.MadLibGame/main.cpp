/* File: main
 *
 * Author: Ryan Sorice
 * 
 * Created on 28 September 2016 9:49 AM
 * 
 * Purpose: The game of Mad Lib.
 */

//System library
#include <iostream>

using namespace std; //Namespace in system library

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    string insName, //String for the first or last name of professor
            fName, //String for the user's first name
            lName, //String for user's last name
            food, //String for a food
            number, //String for a number between 100 and 120
            adjctv, //String for an adjective
            color, //String for a color
            animal; //String for an animal
    
    //First output to user;initializes all the string variables
    cout<<"Welcome to the game of Mad Lib!\n";
    cout<<"What is the first OR last name of your instructor?\n";
    cin>>insName;
    cout<<"What is your first name?\n";
    cin>>fName;
    cout<<"What is your last name?\n";
    cin>>lName;
    cout<<"Enter a type of food.\n";
    cin>>food;
    cout<<"Enter a number between 100 and 120.\n";
    cin>>number;
    cout<<"Enter an adjective.\n";
    cin>>adjctv;
    cout<<"Enter a color.\n";
    cin>>color;
    cout<<"Finally, enter a type of animal.\n";
    cin>>animal;
    
    //Final output of the strings in the Mad Lib game outline
    cout<<"Dear instructor "<<insName<<",\n"<<endl;
    cout<<"I am sorry that I am unable to turn in my homework at this time. First, I\n";
    cout<<"ate a rotten "<<food<<", which made me turn "<<color<<" and extremely ill.\n";
    cout<<"I came down with a fever of "<<number<<". Next, my "<<adjctv<<" pet "<<animal<<" must have\n";
    cout<<"smelled the remains of the "<<food<<" on my homework, because he ate it.\n";
    cout<<"I am currently rewriting my homework and hope you will accept it late.\n"<<endl;
    cout<<"Sincerely,\n";
    cout<<fName<<" "<<lName;
    

    //Exits program
    return 0;
}

