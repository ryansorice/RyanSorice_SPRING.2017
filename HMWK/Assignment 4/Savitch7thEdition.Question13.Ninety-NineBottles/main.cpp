/* File: main
 * Author: Ryan Sorice
 * Created on 12 October 2016 9:11 AM
 * Purpose: Output the song Ninety-Nine Bottles of Beer on the wall until there
 *          are 0 beers on the wall.                                               */

//System libraries
#include <iostream> //Inputs and outputs

using namespace std; //Namespace in system library

//Execution begins here
int main(int argc, char** argv) {

    //Declaration of variables
    string  tenDig, //Tenth digit string
            sglDig, //Single digit string
            tenDig1, //Secondary Tenth digit string
            sglDig1, //Secondary Single digit string
            teens, //Ten-Nineteen string
            teens1; //Secondary Ten-Nineteen string
    short n=99; //Counter for loop
    
    //Loop to output each phrase of 99 bottles (99->0)
    while(n>0){
        switch(n/10){ //First switch
            case 9:tenDig="Ninety";tenDig1="Eighty";break;
            case 8:tenDig="Eighty";tenDig1="Seventy";break;
            case 7:tenDig="Seventy";tenDig1="Sixty";break;
            case 6:tenDig="Sixty";tenDig1="Fifty";break;
            case 5:tenDig="Fifty";tenDig1="Forty";break;
            case 4:tenDig="Forty";tenDig1="Thirty";break;
            case 3:tenDig="Thirty";tenDig1="Twenty";break;
            case 2:tenDig="Twenty";break;
            case 0:tenDig="Ninety";break;
        }
        switch(n%10){ //Second switch
            case 9:sglDig="Nine";sglDig1="Eight";teens="Eighteen";teens1="Nineteen";break;
            case 8:sglDig="Eight";sglDig1="Seven";teens="Seventeen";teens1="Eighteen";break;
            case 7:sglDig="Seven";sglDig1="Six";teens="Sixteen";teens1="Seventeen";break;
            case 6:sglDig="Six";sglDig1="Five";teens="Fifteen";teens1="Sixteen";break;
            case 5:sglDig="Five";sglDig1="Four";teens="Fourteen";teens1="Fifteen";break;
            case 4:sglDig="Four";sglDig1="Three";teens="Thirteen";teens1="Fourteen";break;
            case 3:sglDig="Three";sglDig1="Two";teens="Twelve";teens1="Thirteen";break;
            case 2:sglDig="Two";sglDig1="One";teens="Eleven";teens1="Twelve";break;
            case 1:sglDig="One";sglDig1="Zero";teens="Ten";teens1="Eleven";break;
            case 0:sglDig="Zero";sglDig1="Nine";teens="Nineteen";teens1="Ten";break;
        }
        if(n>20&&n<100){ //Bottle count between 100 and 20
            //End of current tenth
            if(sglDig=="One"){
                cout<<tenDig<<"-"<<sglDig<<" bottles of beer on the wall,\n";
                cout<<tenDig<<"-"<<sglDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<tenDig<<" bottles of beer on the wall!\n"<<endl;
            }
            //End of current tenth--> beginning of next
            else if(sglDig=="Zero"){
                cout<<tenDig<<" bottles of beer on the wall,\n";
                cout<<tenDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<tenDig1<<"-"<<sglDig1<<" bottles of beer on the wall!\n"<<endl;
            }
            //Body of current tenth
            else{
                cout<<tenDig<<"-"<<sglDig<<" bottles of beer on the wall,\n";
                cout<<tenDig<<"-"<<sglDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<tenDig<<"-"<<sglDig1<<" bottles of beer on the wall!\n"<<endl;
            }
        }
        else if(n>9&&n<=20){//Bottle count between 9 and 21
            //21 bottles --> 20 bottles
            if(n/10==2&&sglDig=="One"){
                cout<<tenDig<<"-"<<sglDig<<" bottles of beer on the wall,\n";
                cout<<tenDig<<"-"<<sglDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<tenDig<<" bottles of beer on the wall!\n"<<endl;
            }
            //Ends 10-19 bottles --> 9 bottles
            else if(n/10==1&&sglDig=="One"){
                cout<<teens1<<" bottles of beer on the wall,\n";
                cout<<teens1<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<teens<<" bottles of beer on the wall!\n"<<endl;
            }
            //Beginning of 19 bottles (20-->19)
            else if(n/10==2&&sglDig=="Zero"){
                cout<<tenDig<<" bottles of beer on the wall,\n";
                cout<<tenDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<teens<<" bottles of beer on the wall!\n"<<endl;
            }
            //Beginning of final count (10-->9-0)
            else if(n/10==1&&sglDig=="Zero"){
                cout<<teens1<<" bottles of beer on the wall,\n";
                cout<<teens1<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<sglDig1<<" bottles of beer on the wall!\n"<<endl;
            }
            //19 Bottles to 10 bottles
            else{
                cout<<teens1<<" bottles of beer on the wall,\n";
                cout<<teens1<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<teens<<" bottles of beer on the wall!\n"<<endl;
            }  
        }
        else{ //9 Bottles to 0 bottles
            //Format text "bottle/bottles for one bottle (2->1)
            if(sglDig1=="One"){
                cout<<sglDig<<" bottles of beer on the wall,\n";
                cout<<sglDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<sglDig1<<" bottle of beer on the wall!\n"<<endl;
            }
            //Format text "bottle/bottles for one bottle (1->0)
            else if(sglDig=="One"){
                cout<<sglDig<<" bottle of beer on the wall,\n";
                cout<<sglDig<<" bottle of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<sglDig1<<" bottles of beer on the wall!\n"<<endl;
            }
            //9 Bottles -> 2
            else{
                cout<<sglDig<<" bottles of beer on the wall,\n";
                cout<<sglDig<<" bottles of  beer!\n";
                cout<<"Take one down, pass it around,\n";
                cout<<sglDig1<<" bottles of beer on the wall!\n"<<endl;
            }
        }
        n--; //Decrement loop counter
    }
    //Exits program
    return 0;
}