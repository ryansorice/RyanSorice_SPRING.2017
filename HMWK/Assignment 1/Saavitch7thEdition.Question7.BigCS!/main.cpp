/* 
 * Author: Ryan Sorice
 * Created on 15 September 2016
 * Purpose: Write a program that prints out C S ! in large block letters inside
   a border of *s followed by two blank lines then the message Computer Science 
   is Cool Stuff.
 */

//System Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//Execution begins here
int main(int argc, char** argv) {
    
    //Defining needed variables for execution
    char a,b,c,d,e;
    
    //Setting values for the variables
    a=' ';
    d='!';
    e='0';
    
    //Displays output for user, asking for two inputs
    cout<<"What character would you like to use for C?"<<endl;
    cin>>b;
    cout<<"What character would you like to use for S"<<endl;
    cin>>c;
    
    //Display of inputs and previously defined variables
    cout<<"* * * * * * * * * * * *"<<endl;
    cout<<a<<a<<a<<b<<b<<b<<a<<a<<a<<a<<c<<c<<c<<c<<a<<a<<a<<d<<a<<d<<endl;
    cout<<a<<a<<b<<a<<a<<a<<b<<a<<a<<c<<a<<a<<a<<a<<c<<a<<a<<d<<a<<d<<endl;
    cout<<a<<b<<a<<a<<a<<a<<a<<a<<c<<a<<a<<a<<a<<a<<a<<a<<a<<d<<a<<d<<endl;
    cout<<b<<a<<a<<a<<a<<a<<a<<a<<a<<c<<a<<a<<a<<a<<a<<a<<a<<d<<a<<d<<endl;
    cout<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<c<<c<<c<<c<<a<<a<<a<<d<<a<<d<<endl;
    cout<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<c<<a<<a<<d<<a<<d<<endl;
    cout<<a<<b<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a<<c<<a<<a<<a<<a<<endl;
    cout<<a<<a<<b<<a<<a<<a<<b<<a<<a<<c<<a<<a<<a<<a<<c<<a<<a<<a<<a<<a<<endl;
    cout<<a<<a<<a<<b<<b<<b<<a<<a<<a<<a<<c<<c<<c<<c<<a<<a<<a<<e<<a<<e<<endl;
    cout<<"* * * * * * * * * * * *"<<endl;
    cout<<"Computer Science is Cool Stuff!!!";
    
    //Exits program
    return 0;
}

