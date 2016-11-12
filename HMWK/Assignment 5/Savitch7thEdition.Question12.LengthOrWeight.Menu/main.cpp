/* File: main
 * Author: Ryan Sorice
 * Created on 3 November 2016 12:13 PM
 * Purpose: Full menu to allow user to convert weights or lengths
 */

//System libraries
#include <iostream>             //Inputs and outputs

using namespace std;            //Name-space in system libraries

//User Libraries

//Global variables
const float FTMTCNV=0.3048;     //Feet to Meter conversion
const float MTFTCNV=3.28084;    //Meter to Feet conversion
const float PDKGCNV=0.45359;    //Pound to Kilogram conversion
const float KGPDCNV=2.2046;     //Kilogram to Pound conversion

//Function prototypes
float cnvMtr(float);            //Meter conversion function
float cnvCmtr(float);           //Centimeter conversion function
float cnvFeet(float);           //Feet conversion function
float cnvInch(float);           //Inch conversion function
float cmOvrFl(float &);         //Cm overflow function
float inOvrFl(float &);         //Inch overflow function
float cnvKigr(float);           //Kilogram conversion function
float cnvGram(float);           //Gram conversion function
float cnvPnd(float);            //Pound conversion function
float cnvOunc(float);           //Ounce conversion function
float gmOvrFl(float &);         //Gram overflow function
float ocOvrFl(float &);         //Ounce overflow function
void cnvFtMt();                 //Feet to Meter conversion function
void cnvMtFt();                 //Meter to Feet conversion function
void cnvPdKg();                 //Pound to Kilogram conversion function
void cnvKgPd();                 //Kilogram to Pound conversion function
void length();                  //Length conversion function
void weight();                  //Weight conversion function

//Execution begins here
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm;            //Choice from menu
    
    //Loop until users exits
    do{
        //Prompt for game mode for user input
        cout<<"1.  Type 1  for Length Conversion"<<endl;
        cout<<"2.  Type 2  for Weight Conversion"<<endl;
        cin>>menuItm;

        //Go to the Game mode
        switch(menuItm){
            case 1:length();break;
            case 2:weight(); break;
            default: break;
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<3);//Ends the Do-While Loop
    
    //Exits program
    return 0;
}
//Weight conv. function
void weight(){
    //Declaration/Initiation of variable
    int menuItm;            //Choice from menu
    
    //Loop until users exits
    do{
        //Prompt for game mode for user input
        cout<<"1.  Type 1  for Pound to Kilogram - Ounce to Gram Conversion"<<endl;
        cout<<"2.  Type 2  for Kilogram to Pound - Gram to Ounce Conversion"<<endl;
        cin>>menuItm;

        //Go to the Game mode
        switch(menuItm){
            case 1:cnvPdKg();break;
            case 2:cnvKgPd();break;
            default: break;
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<3);//Ends the Do-While Loop    
}
//Length conv. function
void length(){
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
}
//Kilogram to pound conv. function
void cnvKgPd(){
    //Declaration/Initiation of variable
    float extraPd;                              //Overflow of pounds
    char yesno='y';                             //Variable to continue or break loop
    
    while(yesno=='y'||yesno=='Y'){              //Loop to run kilogram-gram to pound-ounces conversion
        //Declare loop variables
        float pounds,ounces,                    //Converted lengths; pounds&ounces
              kilgram,grams;                    //User's input lengths; kilograms&grams
        
        //Next output and initiation
        cout<<"How many kilograms?\n";
        cin>>kilgram;
        cout<<"How many grams?\n";
        cin>>grams;

        //Process values
        pounds=cnvPnd(kilgram);                 //Converts kilograms to pounds with function
        ounces=cnvOunc(grams);                  //Converts grams to ounces with function
        
        //If ounces overflows to create additional pounds
        if(ounces>=16){                         //Ounces equal to or greater than 16                
            extraPd=ocOvrFl(ounces);            //Gets additional pounds from function; carries new ounce value
            pounds=pounds+extraPd;              //Adds additional pounds to total pounds
        }

        //Final output
        cout<<"Your pound conversion   = "<<pounds<<" pounds\n";
        cout<<"Your ounce conversion   = "<<ounces<<" ounces\n";
        cout<<"Would you like to run again? Enter 'Y'-Yes 'N'-No\n";
        cin>>yesno;                             //User initializes or breaks loop
    }
}
//Pound to kilogram conv. function
void cnvPdKg(){
    //Declaration/Initiation of variable
    float extraKg;                              //Overflow of kilograms
    char yesno='y';                             //Variable to continue or break loop
    
    while(yesno=='y'||yesno=='Y'){              //Loop to run pound-ounces to kilogram-gram conversion
        //Declare loop variables
        float pounds,ounces,                    //User's input lengths; pounds&ounces
              kilgram,grams;                    //Converted lengths; kilograms&grams
        
        //Initial output to user; Initiation of variables
        cout<<"How many pounds?\n";
        cin>>pounds;
        cout<<"How many ounces?\n";
        cin>>ounces;

        //Process values
        kilgram=cnvKigr(pounds);                //Converts pounds to kilograms with function
        grams=cnvGram(ounces);                  //Converts ounces to grams with function
        
        //If grams overflow to create additional kilograms
        if(grams>=1000){                        //Grams equal to or greater than 1000                
            extraKg=gmOvrFl(grams);             //Gets additional kilograms from function; carries new gram value
            kilgram=kilgram+extraKg;            //Adds additional kilograms to total kilograms
        }
        //Final output
        cout<<"Your kilogram conversion      = "<<kilgram<<" kilograms\n";
        cout<<"Your grams conversion         = "<<grams<<" grams\n";
        cout<<"Would you like to run again? Enter 'Y'-Yes 'N'-No\n";
        cin>>yesno;                             //User initializes or breaks loop
    }
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
//Ounce overflow function
float ocOvrFl(float &ounces){
    static float extraPd=0;                 //Declare/initiate return variable             
    while(ounces>=16){                      //Loop to get extra pounds from ounces overflow
        ounces-=16;                         //Subtract 16 from ounces for every pound
        extraPd+=1;                         //Add 1 to extra pounds every 16 ounces
    }
    return extraPd;                         //Return extra pounds value to function
}
//Gram overflow function
float gmOvrFl(float &grams){            
    static float extraKg=0;                 //Declare/initiate return variable
    while(grams>=1000){                     //Loop to get extra kilograms from gram overflow
        grams-=1000;                        //Subtract 1000 from grams for every kilogram
        extraKg+=1;                         //Add 1 to extra kilograms every 1000 grams
    }
        return extraKg;                     //Return extra kilograms value to function
}
//Grams to ounces conv.
float cnvOunc(float grams){
    float ounces=(grams*0.03527);           //Declare/process return variable
    return ounces;                          //Return value of ounces to function
}
//Kilograms to pounds conv.
float cnvPnd(float kilgram){
    float pounds=(kilgram*KGPDCNV);         //Declare/process return variable
    return pounds;                          //Return value of pounds to function
}
//Ounces to grams conv.
float cnvGram(float ounces){
    float grams=((PDKGCNV/16)*ounces)*1000;//Declare/process return variable
    return grams;                          //Return value of grams to function
}
//Pounds to kilogram conv.
float cnvKigr(float pounds){
    float kilgram=pounds*PDKGCNV;          //Declare/process return variable
    return kilgram;                        //Return value of kilograms to function
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