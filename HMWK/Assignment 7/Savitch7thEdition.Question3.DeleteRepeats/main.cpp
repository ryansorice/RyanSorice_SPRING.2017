/* File: main
 * Author: Ryan Sorice
 * Created on 18 November 2016 1:24 PM
 * Purpose: Delete repeated integers in an array; Move integers to fill any blank
 *          spaces.
 */

//System libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;        //Name-space in system libraries

//User Libraries

//Global variables

//Function Prototypes
void fillAry(char [],int);
char delRep(char [],int);
void fillBnk(char[],char [],int);

//Execution begins here
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of array size variable
    int const SIZE=50;
    char repAry[SIZE],delAry[SIZE],newAry[SIZE];

    //Process functions
    fillAry(repAry,SIZE);
    for(int n=0;n<SIZE;n++){ 
        if(n==0)delAry[n]=repAry[n];
        else delAry[n]=delRep(repAry,n);       
    }
    fillBnk(delAry,newAry,SIZE);
    
    //Output
    for(int n=0;n<SIZE;n++) cout<<repAry[n]<<"  "<<delAry[n]<<"  "<<newAry[n]<<endl;
    
    //Exits program
    return 0;
}
void fillBnk(char rep[],char rep1[],int SIZE){
    for(int n=0;n<SIZE;n++){
        static int q=n;
        if(n==0){
            rep1[q]=rep[n];
            q++;
        }
        else{
            if(rep[n]==' '){
                for(int m=n+1;m<SIZE;m++){
                    if(rep[m]!=' '){
                        rep1[q]=rep[m];
                        m=SIZE;
                        q++;
                        n++;
                    }
                    else n++;
                }    
            }
            else{
                rep1[q]=rep[n];
                q++;
            }
        }
    }
}
char delRep(char rep[],int pos){
    char temp;
    for(int n=0;n<pos;n++){ 
        if(rep[n]==rep[pos]){ 
            temp=' ';
            n=pos;
        }
        else temp=rep[pos];
    }
    return temp;
}

void fillAry(char rep[],int SIZE){
    int numb;
    for(int n=0;n<SIZE;n++){
        numb=(rand()%26)+1;
        if(n>SIZE-5) rep[n]=0;
        else{
            switch(numb){
                case 1: rep[n]='a'; break;
                case 2: rep[n]='b'; break;
                case 3: rep[n]='c'; break;
                case 4: rep[n]='d'; break;
                case 5: rep[n]='e'; break;
                case 6: rep[n]='f'; break;
                case 7: rep[n]='g'; break;
                case 8: rep[n]='h'; break;
                case 9: rep[n]='i'; break;
                case 10: rep[n]='j'; break;
                case 11: rep[n]='k'; break;
                case 12: rep[n]='l'; break;
                case 13: rep[n]='m'; break;
                case 14: rep[n]='n'; break;
                case 15: rep[n]='o'; break;
                case 16: rep[n]='p'; break;
                case 17: rep[n]='q'; break;
                case 18: rep[n]='r'; break;
                case 19: rep[n]='s'; break;
                case 20: rep[n]='t'; break;
                case 21: rep[n]='u'; break;
                case 22: rep[n]='v'; break;
                case 23: rep[n]='w'; break;
                case 24: rep[n]='x'; break;
                case 25: rep[n]='y'; break;
                case 26: rep[n]='z'; break;
            }
        }
    }
}