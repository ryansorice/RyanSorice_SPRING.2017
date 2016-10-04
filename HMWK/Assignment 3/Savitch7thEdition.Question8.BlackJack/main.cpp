/* File: main
 * 
 * Author: Ryan Sorice
 *
 * Created on 4 October 2016 3:09 PM
 * 
 * Purpose: Score a Black Jack hand
 */

//System libraries
#include <iostream>

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration of variables
    short hand, //Amount of cards user has
          totVal=0; //Total value of user's hand
    char crd1,crd2,crd3,crd4,crd5; //Character variables to represent user's cards
    
    //Initial output to user; initiation of variables
    cout<<"How many cards do you have?\n";
    cin>>hand;
    cout<<"What are you cards values? Note* 2-9 are entered as normal\n";
    cout<<"integers; if you have a 10 enter it as t. The face cards read\n";
    cout<<"in as j,q,k,a. Enter any Aces last!\n";
    
    //Switch statement to initiate amount of cards user entered for their hand
    switch(hand)
    {
        case 2: cin>>crd1,
                cin>>crd2; break;
        case 3: cin>>crd1,
                cin>>crd2,
                cin>>crd3; break;
        case 4: cin>>crd1,
                cin>>crd2,
                cin>>crd3,
                cin>>crd4; break;
        case 5: cin>>crd1,
                cin>>crd2,
                cin>>crd3,
                cin>>crd4,
                cin>>crd5; break;
                
    }
    //First block of is statements to convert card 1 into a numerical value
    if((crd1=='t'||crd1=='T')||(crd1=='j'||crd1=='J')||(crd1=='q'||crd1=='Q')||(crd1=='k'||crd1=='K')){
        totVal=totVal+10;
    }else if(crd1=='2'){
        totVal=totVal+2;
    }else if(crd1=='3'){
        totVal=totVal+3;
    }else if(crd1=='4'){
        totVal=totVal+4;
    }else if(crd1=='5'){
        totVal=totVal+5;
    }else if(crd1=='6'){
        totVal=totVal+6;
    }else if(crd1=='7'){
        totVal=totVal+7;
    }else if(crd1=='8'){
        totVal=totVal+8;
    }else if(crd1=='9'){
        totVal=totVal+9;
    }else if(crd1=='a'||crd1=='A'){
        totVal=totVal+11;
        //Nested if to convert a to value of 1 over 11
        if(totVal>21){
            totVal=totVal-10;}
    }
    
    //Next block of is statements to convert card 2 into a numerical value
    if((crd2=='t'||crd2=='T')||(crd2=='j'||crd2=='J')||(crd2=='q'||crd2=='Q')||(crd2=='k'||crd2=='K')){
        totVal=totVal+10;
    }else if(crd2=='2'){
        totVal=totVal+2;
    }else if(crd2=='3'){
        totVal=totVal+3;
    }else if(crd2=='4'){
        totVal=totVal+4;
    }else if(crd2=='5'){
        totVal=totVal+5;
    }else if(crd2=='6'){
        totVal=totVal+6;
    }else if(crd2=='7'){
        totVal=totVal+7;
    }else if(crd2=='8'){
        totVal=totVal+8;
    }else if(crd2=='9'){
        totVal=totVal+9;
    }else if(crd2=='a'||crd2=='A'){
        totVal=totVal+11;
        //Nested if to convert a to value of 1 over 11
        if(totVal>21){
            totVal=totVal-10;}
    }
    
    //Next block of is statements to convert card 3 into a numerical value
    if((crd3=='t'||crd3=='T')||(crd3=='j'||crd3=='J')||(crd3=='q'||crd3=='Q')||(crd3=='k'||crd3=='K')){
        totVal=totVal+10;
    }else if(crd3=='2'){
        totVal=totVal+2;
    }else if(crd3=='3'){
        totVal=totVal+3;
    }else if(crd3=='4'){
        totVal=totVal+4;
    }else if(crd3=='5'){
        totVal=totVal+5;
    }else if(crd3=='6'){
        totVal=totVal+6;
    }else if(crd3=='7'){
        totVal=totVal+7;
    }else if(crd3=='8'){
        totVal=totVal+8;
    }else if(crd3=='9'){
        totVal=totVal+9;
    }else if(crd3=='a'||crd3=='A'){
        totVal=totVal+11;
        //Nested if to convert a to value of 1 over 11
        if(totVal>21){
            totVal=totVal-10;}
    }
    
    //Next block of is statements to convert card 4 into a numerical value
    if((crd4=='t'||crd4=='T')||(crd4=='j'||crd4=='J')||(crd4=='q'||crd4=='Q')||(crd4=='k'||crd4=='K')){
        totVal=totVal+10;
    }else if(crd4=='2'){
        totVal=totVal+2;
    }else if(crd4=='3'){
        totVal=totVal+3;
    }else if(crd4=='4'){
        totVal=totVal+4;
    }else if(crd4=='5'){
        totVal=totVal+5;
    }else if(crd4=='6'){
        totVal=totVal+6;
    }else if(crd4=='7'){
        totVal=totVal+7;
    }else if(crd4=='8'){
        totVal=totVal+8;
    }else if(crd4=='9'){
        totVal=totVal+9;
    }else if(crd4=='a'||crd4=='A'){
        totVal=totVal+11;
        //Nested if to convert a to value of 1 over 11
        if(totVal>21){
            totVal=totVal-10;}
    }
    
    //Next block of is statements to convert card 5 into a numerical value
    if((crd5=='t'||crd5=='T')||(crd5=='j'||crd5=='J')||(crd5=='q'||crd5=='Q')||(crd5=='k'||crd5=='K')){
        totVal=totVal+10;
    }else if(crd5=='2'){
        totVal=totVal+2;
    }else if(crd5=='3'){
        totVal=totVal+3;
    }else if(crd5=='4'){
        totVal=totVal+4;
    }else if(crd5=='5'){
        totVal=totVal+5;
    }else if(crd5=='6'){
        totVal=totVal+6;
    }else if(crd5=='7'){
        totVal=totVal+7;
    }else if(crd5=='8'){
        totVal=totVal+8;
    }else if(crd5=='9'){
        totVal=totVal+9;
    }else if(crd5=='a'||crd5=='A'){
        totVal=totVal+11;
        //Nested if to convert a to value of 1 over 11
        if(totVal>21){
            totVal=totVal-10;}
    }
    
    //Final block of if statements to output total value of user's cards
    //If statement for perfect hand
    if(totVal==21){
        cout<<"You have a perfect hand of "<<totVal;
    }
    //If statement if user enters 0 in initiation
    else if(totVal==0){
        cout<<"You had no cards, odd!";
    }
    //If statement for a passing hand
    else if(totVal<21){
        cout<<"Your hand is acceptable with a value of "<<totVal;
    }
    //If statement for a busted hand
    else if(totVal>21){
        cout<<"You busted! The value of your hand is "<<totVal;
    }
    
    //Exit return
    return 0;
}

