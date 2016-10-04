/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 3 October 2016 6:21 PM
 * 
 * Purpose: Find roots of the Quadratic function
 */

//System libraries
#include <iostream> //Inputs and Outputs
#include <cmath> //Math library

using namespace std; //Namespace in system libraries

//Execution
int main(int argc, char** argv) {
    
    //Declaration/Initiation of variables
    float a,b,c;
    char yesno='y';
    
    //Loop to allow user to solve until they are done
    while(yesno=='y'||yesno=='Y')
    {
        //Initial output; Variable initialization
        cout<<"Lets find the roots of the quadratic equation:\n";
        cout<<"ax^2+bx+c=0\n";
        cout<<"Enter 3 float type integers for a b c.\n";
        cin>>a>>b>>c;
        
        //First if statement if a=0
        if(a==0)
        {
            //First nested if, if b also = 0
            if(b==0)
            {
                cout<<"0+0+"<<c<<"=0 is not a Quadratic Equation and does not make";
                cout<<"logical sense!\n";
            }
            //Next nested if to delete the negative sign on 0
            else if(a==0&&c==0)
            {
                //Nested if to take away negative sign from 0
                if(b>0)
                {
                    cout<<"The root is: "<<(c/b)<<endl;
                }
                //Nested if to take away negative sign from 0
                else if(b<0)
                {
                    cout<<"The root is: "<<-c/b<<endl;
                }
            }
            //Last nested if only a=0
            else
            {
                cout<<"The root is: "<<-c/b<<endl;
            }
        }
        //Next if statement if only 1 root exists
        else if(b*b-4*a*c==0)
        {
            cout<<"The only root of this equation is: "<<(-b+sqrt(b*b-4*a*c))/(2*a)<<endl;
        }
        //Next if statement if there are two normal roots
        else if(b*b-4*a*c>0)
        {
            cout<<"The first root of this equation is: "<<(-b+sqrt(b*b-4*a*c))/(2*a)<<endl;
            cout<<"The second root of this equation is: "<<(-b-sqrt(b*b-4*a*c))/(2*a)<<endl;
        }
        //Next if statement if there are two complex roots
        else if(b*b-4*a*c<0)
        {
            cout<<"The first complex root is: "<<-b/(2*a)<<" + "<<(sqrt(-(b*b-4*a*c))/(2*a))<<"i\n";
            cout<<"The second complex root is: "<<-b/(2*a)<<" + "<<(-sqrt(-(b*b-4*a*c))/(2*a))<<"i\n";
        }
        //Output to user to initiate again or end program
        cout<<"Do you have another set of float type integers? Enter 'Y' or 'N'\n";
        cin>>yesno;
    }

    //Exits program
    return 0;
}

