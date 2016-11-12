/* File: main
 * Author: Ryan Sorice
 * Created on 2 November 2016 6:46 PM
 * Purpose: Converts pounds to kilograms and ounces to grams; then computes the reverse
 */

//System libraries
#include <iostream>             //Inputs and outputs

using namespace std;            //Name-space in system libraries

//Global variables
const float PDKGCNV=0.45359;    //Pound to Kilogram conversion
const float KGPDCNV=2.2046;     //Kilogram to Pound conversion

//Function prototypes
float cnvKigr(float);           //Kilogram conversion function
float cnvGram(float);           //Gram conversion function
float cnvPnd(float);            //Pound conversion function
float cnvOunc(float);           //Ounce conversion function
float gmOvrFl(float &);         //Gram overflow function
float ocOvrFl(float &);         //Ounce overflow function
void cnvPdKg();
void cnvKgPd();

//Execution begins here
int main(int argc, char** argv) {

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
    
    //Exits program
    return 0;
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