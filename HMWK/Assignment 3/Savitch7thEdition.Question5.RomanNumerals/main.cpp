/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 4 October 2016 11:47 AM
 * 
 * Purpose: Convert a year(1000-3000) to Roman numerals
 */

//System libraries
#include <iostream>

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    short usrYear;
    
    //Initial output to user; usrYear initialization
    cout<<"Enter a year between 0 and 3999.\n";
    cin>>usrYear;
    
    //Processing of variables map inputs to output
    short thousnd=(usrYear/1000)*1000,
          hundred=(usrYear/100)*100,
          ten=(usrYear/10)*10,
          dig3=hundred-thousnd,
          dig2=ten-(hundred-thousnd)-thousnd,
          dig1=usrYear-thousnd-(hundred-thousnd)-(ten-(hundred-thousnd)-thousnd);
    //First switch statement for 4th digit Roman numeral
    switch(thousnd)
    {
        case 1000:cout<<"M"; break;
        case 2000:cout<<"MM"; break;
        case 3000:cout<<"MMM"; break;
    }
    //Next switch statement for 3rd digit Roman numeral
    switch(dig3)
    {
        case 100:cout<<"C"; break;
        case 200:cout<<"CC"; break;
        case 300:cout<<"CCC"; break;
        case 400:cout<<"CD"; break;
        case 500:cout<<"D"; break;
        case 600:cout<<"DC"; break;
        case 700:cout<<"DCC"; break;
        case 800:cout<<"DCCC"; break;
        case 900:cout<<"CM"; break;
    }
    //Next switch statement for 3rd digit Roman numeral
    switch(dig2)
    {
        case 10:cout<<"X"; break;
        case 20:cout<<"XX"; break;
        case 30:cout<<"XXX"; break;
        case 40:cout<<"XL"; break;
        case 50:cout<<"L"; break;
        case 60:cout<<"LX"; break;
        case 70:cout<<"LXX"; break;
        case 80:cout<<"LXXX"; break;
        case 90:cout<<"XC"; break;
    }
    //Next switch statement for 3rd digit Roman numeral
    switch(dig1)
    {
        case 0: break;
        case 1:cout<<"I"; break;
        case 2:cout<<"II"; break;
        case 3:cout<<"III"; break;
        case 4:cout<<"IV"; break;
        case 5:cout<<"V"; break;
        case 6:cout<<"VI"; break;
        case 7:cout<<"VII"; break;
        case 8:cout<<"VIII"; break;
        case 9:cout<<"IX"; break;
    }

    //Exits Program
    return 0;
}

