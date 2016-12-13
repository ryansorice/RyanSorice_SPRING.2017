/* File: main
 * Author: Ryan Sorice
 * Created on 1 December 2016 8:18 PM
 * Purpose: Score a 5-card poker hand
 */

//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;                    //Name-space in system libraries

//User Libraries

//Global Variables

//Function Prototypes
void fillAry(string [], char[], int);
void cnvCard(string[], int [], int);
void sorting(int [], char[], int);
string scrHand(int [], char[], int);

//Execution begins here
int main(int argc, char** argv) {
    //Declaration of variables
    int const SIZE=5;
    string cardVal[SIZE],hand;
    char cardSte[SIZE];
    int cardInt[SIZE];
    

    fillAry(cardVal,cardSte,SIZE);
    cnvCard(cardVal,cardInt,SIZE);
    sorting(cardInt,cardSte,SIZE);
    hand=scrHand(cardInt,cardSte,SIZE);
    cout<<"Your hand is "<<hand;
    
    //Exits program
    return 0;
}
string scrHand(int cardI[], char cardS[], int size){
    string score;
    int n=0,count=1,count1=1,count2=1,count3=1;
    for(int m=n+1;m<size;m++){
        if(cardS[m]==cardS[n]) count++;
        if(cardI[m]==cardI[m-1]+1) count1++;
    }
    for(int m=n+1;m<size;n++){
        if(cardI[m]==cardI[n]) count2++;
    }
    for(int a=0;a<size;a++){
        if(cardI[a]==0) a=size;
        else{
            for(int m=n+1;m<size;n++){
                if(cardI[m]==cardI[a]){
                    count3++;
                    cardI[m]=0;
                }
            }
            sorting(cardI,cardS,size);
        }
    }
    if((count==5&&count1==5)&&(cardI[0]==10&&cardI[4]==14)) score="royal flush";
    else if(count==5&&count1==5) score="straight flush";
    else if(count2==4) score="4-of-a-kind";
    else if(count3==4) score="full house";
    else if(count==5) score="flush";
    else if(count1==5) score="straight";
    else if(count3==3) score="three-of-a-kind";
    else if(count3==3) score="two pair";
    else if(count3==2) score="one pair";
    else score="no hand";
    return score;
}
void sorting(int numbs[], char card[], int size){                //Function to sort array Greatest to Least
    for(int n=0;n<size-1;n++){                      //Loop to process each value of array
        for(int m=n+1;m<size;m++){                  //Nested loop to compare each array value to previous value
            if(numbs[n]>numbs[m]){                  //If original array value less than current; perform swap
                numbs[n]=numbs[n]^numbs[m];
                numbs[m]=numbs[n]^numbs[m];
                numbs[n]=numbs[n]^numbs[m];
                card[n]=card[n]^card[m];
                card[m]=card[n]^card[m];
                card[n]=card[n]^card[m];
            }
        }
    }
}
void cnvCard(string cardV[], int card[], int size){
    for(int n=0;n<size;n++){
        if(cardV[n]=="2") card[n]=2;
        else if(cardV[n]=="3") card[n]=3;
        else if(cardV[n]=="4") card[n]=4;
        else if(cardV[n]=="5") card[n]=5; 
        else if(cardV[n]=="6") card[n]=6;
        else if(cardV[n]=="7") card[n]=7; 
        else if(cardV[n]=="8") card[n]=8; 
        else if(cardV[n]=="9") card[n]=9; 
        else if(cardV[n]=="10") card[n]=10; 
        else if(cardV[n]=="J") card[n]=11; 
        else if(cardV[n]=="Q") card[n]=12; 
        else if(cardV[n]=="K") card[n]=13; 
        else if(cardV[n]=="A"&&n==0) card[n]=1;
        else if(cardV[n]=="A") card[n]=14;
    }
}
void fillAry(string cardV[],char cardS[], int size){
    for(int n=0;n<size;n++){
        cout<<"Enter card value. 2-10,J,Q,K,A\n";
        cin>>cardV[n];
        cout<<"Enter suite of that card. S(spade),D(diamond),H(heart),C(club)\n";
        cin>>cardS[n];
    }
}