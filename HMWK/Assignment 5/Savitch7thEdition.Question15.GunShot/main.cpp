/* File: main
 * Author: Ryan Sorice
 * Created on 9 November 2016 7:15 PM
 * Purpose: Write a program that simulates a duel between 3 players
 *          that have different levels of accuracy and each take turns
 *          shooting at the person with the most accuracy, until only
 *          one player stands. Repeat 1000 times.
 */

//System libraries
#include <cstdlib>                          //Random seed
#include <iostream>                         //Inputs and outputs
#include <ctime>                            //Time library

using namespace std;                        //Name-space in system libraries

//User libraries

//Global variables

//Function prototypes
void shoot(bool &, float);                  //Function to simulate a player shooting

//Execution begins here
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare/initiate variables
    float accrcy,                               //Variable to declare each player's accuracy
          scor1=0,scor2=0,scor3=0;              //Initial score of each player
    
    for(int round=0;round<1000;round++){        //Loop to repeat 3-way duel 1000 times
        //Declare/initiate variables
        bool play1=true,play2=true,play3=true;  //Booleans to determine whether player is dead or alive  
        short alive=3,turn=1;                   //Counter variables
        
        while(alive>1){                         //Loop while player's are still dueling
            if(turn==3){                        //If player 3 turn
                if(play2==true){                //If player 2 alive
                    cout<<"BOOM! Player 3 shot Player 2!!!\n";
                    play2=false;                //Player 2 set to false(dead)
                    alive--;                    //Alive counter down by 1
                    turn=1;                     //Set turn to player 1
                }
                else if(play1==true){           //Else If player 2 dead and player 1 alive
                    cout<<"BOOM! Player 3 shot Player 1!!!\n";
                    play1=false;                //Player 1 set to false(dead)
                    alive--;                    //Alive counter down by 1; Game over here
                }
            }
            else if(turn==2){                   //If player 2 turn
                accrcy=0.5;                     //Accuracy of player 2 is 50%
                if(play3==true){                //If player 3 alive
                    shoot(play3,accrcy);        //Get player 3 dead/alive from function
                    if(play3==false){           //If player 3 dead
                        cout<<"BOOM! Player 2 shot Player 3!!!\n";
                        alive--;                //Alive counter down by 1
                        turn=1;                 //Set turn to player 1
                    }
                    else turn=3;                //Else set turn to player 3
                }
                else{                           //Else if player 3 dead and player 1 alive
                    shoot(play1,accrcy);        //Get player 1 dead/alive from function
                    if(play1==false){           //If player 1 dead
                        cout<<"BOOM! Player 2 shot Player 1!!!\n";
                        alive--;                //Alive counter down by 1; Game over here
                    }
                    else turn=1;                //Else set turn to player 1
                }    
            }
            else if(turn==1){                   //If player 1 turn
                accrcy=0.33;                    //Accuracy of player 1 is 33%
                if(play3==true){                //If player 3 is alive
                    shoot(play3,accrcy);        //Get player 3 dead/alive from function
                    if(play3==false){           //If player 3 dead
                        cout<<"BOOM! Player 1 shot Player 3!!!\n";
                        alive--;                //Alive counter down by 1
                        turn=2;                 //Set turn to player 2
                    }
                    else if(play2==true) turn=2;//Else if player 3 dead and player 2 alive; set turn to player 2
                    else turn=3;                //Else set turn to player 3 (player 2 dead)
                }
                else if(play2==true){           //Else if player 3 dead and player 2 alive
                    shoot(play2,accrcy);        //Get player 2 dead/alive from function
                    if(play2==false){           //If player 2 dead
                        cout<<"BOOM! Player 1 shot Player 2!!!\n";
                        alive--;                //Alive counter down by 1; Game over here
                    }
                    else turn=2;                //Else set turn to player 2
                }
            }
        }
        if(play1==true) scor1++;                //If player 1 won the duel round; their score +1
        else if(play2==true) scor2++;           //Else If player 2 won the duel round; their score +1
        else if(play3==true) scor3++;           //Else If player 3 won the duel round; their score +1
    }
    //Final output of each player's wins and win-rate
    cout<<endl<<"Player 1 won "<<scor1<<" times with a win-rate\n";
    cout<<"of "<<(scor1/1000)*100.0f<<"%\n";
    cout<<"Player 2 won "<<scor2<<" times with a win-rate\n";
    cout<<"of "<<(scor2/1000)*100.0f<<"%\n";
    cout<<"Player 3 won "<<scor3<<" times with a win-rate\n";
    cout<<"of "<<(scor3/1000)*100.0f<<"%\n";
    //Exits program
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   shoot ********************************************
//Purpose:  3-way Gun Duel between players 1000 times
//Inputs:   targAlv; bool to determine alive or dead
//          accrcy; float to determine players accuracy
//Output:   targAlv; bool true or false (dead or alive)
//******************************************************************************
void shoot(bool &targAlv,float accrcy){
    //Declare/Initiate variable
    float rndnmbr=(rand()%100+1)/100.0f;        //Gets random number between 0 and 1
    if(rndnmbr<=accrcy) targAlv=false;          //If random number is less than or equal to accuracy, the target is shot
    else targAlv=true;                          //Else target remains alive
}