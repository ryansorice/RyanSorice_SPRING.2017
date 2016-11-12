/* File: main
 * Author: Ryan Sorice
 * Created on 6 November 2016 7:53 PM
 * Purpose: Write a void function to compute area and perimeter of triangle,(Not semi-perimeter) 
 *          using formulas area=sqrt(s(s-a)(s-b)(s-c)) and semi-perimeter=(a+b+c)/2
 */

//System libraries
#include <iostream>                             //Inputs and outputs
#include <cmath>                                //Math library; Squareroot function

using namespace std;                            //Name-space in system libraries

//User Libraries

//Global variables

//Function prototypes
float triSemP(short,short,short);               //Function for triangle semi-perimeter
void triangl(short,short,short,float,float);    //Function for triangle Area and Perimeter

//Execution begins here
int main(int argc, char** argv) {
    //Declaration of variables
    short a,b,c;                                //Side lengths of triangle
    float area,                                 //Area of the triangle
          sprimtr;                              //Semi-perimeter/Perimeter of the triangle
    char yesno='y';                             //Character to continue/break loop
    
    //Initial output
    cout<<"This program will compute the area and perimeter of your triangle!\n";
    
    while(yesno=='y'||yesno=='Y'){              //Loop to run triangle calculations
        //Output; Variable initiation
        cout<<"What is the first length of your triangle?\n";
        cin>>a;
        cout<<"What is the next length of your triangle?\n";
        cin>>b;
        cout<<"What is the last length of your triangle?\n";
        cin>>c;

        //Process inputs to get outputs
        sprimtr=triSemP(a,b,c);                //Gets value of semi-perimeter from function
        //If any length is greater than semi-perimeter; Output invalid
        if(a>sprimtr||b>sprimtr||c>sprimtr) cout<<"Those are not valid lengths of a triangle!\n";
        //Else try to compute triangle
        else triangl(a,b,c,sprimtr,area);      //Prints area/perimeter of triangle, if valid, from function
        cout<<"Do you have another triangle? Enter 'Y'-Yes 'N'-No\n";
        cin>>yesno;                            //User initiates loop again or breaks loop
    }
    //Exits program
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   triangl ****************************************
//Purpose:  Calculate Area and Perimeter of triangle
//Inputs:   a,b,c; shorts for side lengths. sprimtr,area; floats for semi-p&area
//Output:   area,sprimtr; floats for area value and perimeter value
//******************************************************************************
void triangl(short a,short b, short c, float sprimtr, float area){
    area=sqrt((sprimtr*(sprimtr-a)*(sprimtr-b)*(sprimtr-c)));//Computes area of the triangle
    sprimtr=a+b+c;                                           //Changes Semi-perimeter value to value of the perimeter
    //If triangles lengths do not make a valid triangle
    if((area<=0)||(a==0)||(b==0)||(c==0)) cout<<"Those are not valid lengths of a triangle!\n";
    else{                                                    //Else output area and perimeter of the triangle
        cout<<"The area of your triangle = "<<area<<endl;
        cout<<"The perimeter of your triangle = "<<sprimtr<<endl;
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   triSemP ****************************************
//Purpose:  Calculate semi-perimeter of triangle
//Inputs:   a,b,c; shorts for side lengths of triangle
//Output:   semiP; float for semi-perimeter of triangle
//******************************************************************************
float triSemP(short a,short b,short c){
    float semiP=(a+b+c)/2;           //Computer semi-perimeter of triangle
    return semiP;                    //Returns value of semi-perimeter
}