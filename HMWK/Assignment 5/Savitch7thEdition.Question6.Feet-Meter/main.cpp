/* File: main
 * Author: Ryan Sorice
 * Created on 2 November 2016 4:13 PM
 * Purpose: Converts feet to meters and inches to centimeters; then computes the reverse
 */

//System libraries
#include <iostream>             //Inputs and outputs

using namespace std;            //Name-space in system libraries

//Global variables
const float FTMTCNV=0.3048;     //Feet to Meter conversion
const float MTFTCNV=3.28084;    //Meter to Feet conversion

//Function prototypes
float cnvMtr(float);            //Meter conversion function
float cnvCmtr(float);           //Centimeter conversion function
float cnvFeet(float);           //Feet conversion function
float cnvInch(float);           //Inch conversion function
float cmOvrFl(float &);         //Cm overflow function
float inOvrFl(float &);         //Inch overflow function
void cnvFtMt();                 //Feet to Meter conversion function
void cnvMtFt();                 //Meter to Feet conversion function

//Execution begins here
int main(int argc, char** argv) {

    //Declaration/Initiation of variable
    int menuItm;            //Choice from menu
    
    //Loop until users exits
    do{
        //Prompt for game mode for user input
        cout<<"1.  Type 1  for Feet to Meter - Inch to Centimeter Conversion"<<endl;
        cout<<"2.  Type 2  for Meter to Feet - Centimeter to Inch Conversion"<<endl;
        cin>>menuItm;

        //Go to the Game mode
        switch(menuItm){
            case 1:cnvFtMt();break;
            case 2:cnvMtFt();break;
            default: break;
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<3);//Ends the Do-While Loop
    
    //Exits program
    return 0;
}
//Meter to feet conv. function
void cnvMtFt(){
    //Declaration/Initiation of variable
    float extraF;                               //Overflow of feet
    char yesno='y';                             //Variable to continue or break loop
    
    while(yesno=='y'||yesno=='Y'){              //Loop to run meter-centimeter to feet-inch conversion
        //Declare loop variables
        float feet,inches,                      //Converted lengths; feet&inches
              meters,cMeters;                   //User's input lengths; meters&centimeters
        
        //Next output and initiation
        cout<<"How many meters?\n";
        cin>>meters;
        cout<<"How many centimeters?\n";
        cin>>cMeters;

        //Process values
        feet=cnvFeet(meters);                   //Converts meters to feet with function
        inches=cnvInch(cMeters);                //Converts centimeters to inches with function
        
        //If centimeters overflows to create additional meters
        if(inches>=12){                         //Centimeters equal to or greater than 100                
            extraF=inOvrFl(inches);             //Gets additional meters from function; carries new cm value
            feet=feet+extraF;                   //Adds additional meters to total meters
        }

        //Final output
        cout<<"Your foot conversion = "<<feet<<" feet\n";
        cout<<"Your inch conversion = "<<inches<<" inches\n";
        cout<<"Would you like to do another Meter-CM to Feet-Inch conversion? Enter 'Y'-Yes 'N'-No\n";
        cin>>yesno;                             //User initializes or breaks loop
    }
}
//Feet to meter conv. function
void cnvFtMt(){
    //Declaration/Initiation of variable
    float extraM;                               //Overflow of meters
    char yesno='y';                             //Variable to continue or break loop
    
    while(yesno=='y'||yesno=='Y'){              //Loop to run feet-inch to meter-centimeter conversion
        //Declare loop variables
        float feet,inches,                      //User's input lengths; feet&inches
              meters,cMeters;                   //Converted lengths; meters&centimeters
        
        //Initial output to user; Initiation of variables
        cout<<"How many feet?\n";
        cin>>feet;
        cout<<"How many inches?\n";
        cin>>inches;

        //Process values
        meters=cnvMtr(feet);                    //Converts feet to meters with function
        cMeters=cnvCmtr(inches);                //Converts inches to centimeters with function
        
        //If centimeters overflows to create additional meters
        if(cMeters>=100){                       //Centimeters equal to or greater than 100                
            extraM=cmOvrFl(cMeters);            //Gets additional meters from function; carries new cm value
            meters=meters+extraM;               //Adds additional meters to total meters
        }

        //Final output
        cout<<"Your meter conversion      = "<<meters<<" meters\n";
        cout<<"Your centimeter conversion = "<<cMeters<<" centimeters\n";
        cout<<"Would you like to do another Feet-Inch to Meter-CM conversion? Enter 'Y'-Yes 'N'-No\n";
        cin>>yesno;                             //User initializes or breaks loop
    }
}
//Inch overflow function
float inOvrFl(float &inches){              
    static float extraF=0;                 //Declare/initiate return variable
    while(inches>=12){                     //Loop to get extra feet from inch overflow
        inches-=12;                        //Subtract 12 from inches for every foot
        extraF+=1;                         //Add 1 to extra feet for every 12 inches
    }
    return extraF;                         //Return extra feet to function
}
//Cm overflow function
float cmOvrFl(float &cMeters){
    static float extraM=0;                 //Declare/initiate return variable
    while(cMeters>=100){                   //Loop to get extra meter from cm overflow
        cMeters-=100;                      //Subtract 100 from cm for every meter
        extraM+=1;                         //Add 1 to extra meters for every 100 cms
    }
    return extraM;                         //Return extra meters to function
}
//Cm to inches conv.
float cnvInch(float cMeters){
    float inches=(cMeters*0.393701);       //Declare/process return variable
    return inches;                         //Return value of inches to function
}
//Meter to feet conv.
float cnvFeet(float meters){    
    float feet=(meters*MTFTCNV);           //Declare/process return variable
    return feet;                           //Return value of feet to function
}
//Inch to cm conv.
float cnvCmtr(float inches){
    float cMeters=((FTMTCNV/12)*inches)*100;//Declare/process return variable
    return cMeters;                         //Return value of cms to function
}
//Feet to meter conv.
float cnvMtr(float feet){
    float meters=feet*FTMTCNV;             //Declare/process return variable
    return meters;                         //Return value of meters to function
}