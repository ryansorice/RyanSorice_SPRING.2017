/* File: main
 * Author: Ryan Sorice
 * Created on 15 November 2016 2:43 PM
 * Purpose: Add two hexadecimal numerals
 */

//System Libraries
#include <iostream>

using namespace std;        //Name-space in system libraries

//Global variables

//Function prototypes
int hexaVal(int []);        //Gets integer value of hexadecimal numeral
void cnvAry(char [],int[]); //Converts char array values into integer array values

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int const DIGIT=10;
    int intHex[DIGIT],intHex1[DIGIT],sum1,sum2,totsum;
    char hexDec[DIGIT],hexDec1[DIGIT];
    
    //Initial output
    cout<<"Enter your first hexadecimal numeral (10 characters or less).\n";
    cin>>hexDec;
    cout<<"Enter your second hexadecimal numeral (10 characters or less).\n";
    cin>>hexDec1;
    
    //Process values with functions
    cnvAry(hexDec,intHex);
    cnvAry(hexDec1,intHex1);
    sum1=hexaVal(intHex); cout<<sum1<<endl;
    sum2=hexaVal(intHex1); cout<<sum2<<endl;
    totsum=sum1+sum2;
    
    //Final output
    if(totsum>999999999) cout<<"OOPS!!! Addition overflow!\n";
    else cout<<"The sum of your hexadecimal numerals = "<<totsum<<endl;

    //Exits program
    return 0;
}

int hexaVal(int hex[]){
    int val;
    for(int n=0;n<10;n++){
        if(hex[n+1]==0&&n==0){
            val=hex[n];
            n=10;
        }
        else if(hex[n+1]!=0&&n==0) val=(hex[n]*16)+hex[n+1];
        else if(hex[n+1]!=0) val=(val*16)+hex[n+1];
        else if(hex[n+1]==0) n=10;
    }
    return val;
}
void cnvAry(char hex[],int hexa[]){
    for(int n=0;n<10;n++){
        if(hex[n]<=0) hexa[n]=0;   
        else{
            switch(hex[n]){
                case '1': hexa[n]=1; break;
                case '2': hexa[n]=2; break;
                case '3': hexa[n]=3; break;
                case '4': hexa[n]=4; break;
                case '5': hexa[n]=5; break;
                case '6': hexa[n]=6; break;
                case '7': hexa[n]=7; break;
                case '8': hexa[n]=8; break;
                case '9': hexa[n]=9; break;
                case 'a': hexa[n]=10; break;
                case 'b': hexa[n]=11; break;
                case 'c': hexa[n]=12; break;
                case 'd': hexa[n]=13; break;
                case 'e': hexa[n]=14; break;
                case 'f': hexa[n]=15; break;
            }
        }
    }
}