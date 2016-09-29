/*  File:  main
 * 
 * Author: Ryan Sorice
 *
 * Created on 29 September  2016 2:21 PM
 * 
 * Purpose: To play rock paper scissors as many times as the user's would like.
 */

//System libraries
#include <iostream>

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {
    
    //Declaration/Initiation of variables
    short score1=0, //Player 1 score
          score2=0; //Player 2 score
    char yesno='y'; //Variable for continuing/ending program
    char play1, //Player 1s pick
         play2; //Player 2s pick
    
    //Initial output to user
    cout<<"Welcome to the game of Rock-Paper-Scissors!\n";
    
    //Loop to play game as often as user's would like
    while(yesno=='y'||yesno=='Y')
    {
        //Output that initiates the game between two players
        cout<<"Player 1, what is your pick? Enter 'r','p' or 's'\n";
        cin>>play1;
        cout<<"Player 2, what is your pick? Enter 'r','p' or 's'\n";
        cin>>play2;
    
        //First if statement if the game is a draw
        if(play1==play2)
        {
            cout<<"It is a draw!\n";
        }
        //Next if statement
        else if((play1=='r'||play1=='R')&&(play2=='p'||play2=='P'))
        {
            //Output round win player 2 paper/rock
            cout<<"Player 2 wins!\n";
            cout<<"Paper covers Rock.\n";
            score2++; //Adds 1 point to player 2 score
        }
        //Next if statement
        else if((play1=='r'||play1=='R')&&(play2=='s'||play2=='S'))
        {
            //Output round win player 1 rock/scissor
            cout<<"Player 1 wins!\n";
            cout<<"Rock breaks Scissors.\n";
            score1++; //Adds 1 point to player 1 score
        }
        //Next if statement
        else if((play1=='p'||play1=='P')&&(play2=='r'||play2=='R'))
        {
            //Output round win player 1 paper/rock
            cout<<"Player 1 wins!\n";
            cout<<"Paper covers Rock\n";
            score1++; //Adds 1 point to player 1 score
        }
        //Next if statement
        else if((play1=='p'||play1=='P')&&(play2=='s'||play2=='S'))
        {
            //Output round win player 2 scissors/paper
            cout<<"Player 2 wins!\n";
            cout<<"Scissors cut Paper.\n";
            score2++; //Adds 1 point to player 2 score
        }
        //Next if statement
        else if((play1=='s'||play1=='S')&&(play2=='r'||play2=='R'))
        {
            //Output round win player 2 rock/scissors
            cout<<"Player 2 wins!\n";
            cout<<"Rock breaks Scissors.\n";
            score2++; //Adds 1 point to player 2 score
        }
        //Next if statement
        else if((play1=='s'||play1=='S')&&(play2=='p'||play2=='P'))
        {
            //Output round win player 1 scissors/paper
            cout<<"Player 1 wins!\n";
            cout<<"Scissors cut Paper.\n";
            score1++; //Adds 1 point to player 1 score
        }
        //Output if user would like to continue or end program
        cout<<"Would you like to play again? Enter 'Y' or 'N'\n";
        cin>>yesno;
    }
    //First if statement if game is a draw
    if(score1==score2)
    {
        cout<<"The game is a draw! "<<score1<<" - "<<score2<<".\n";
    }
    //Next if statement if player 1 wins
    else if(score1>score2)
    {
        cout<<"Player 1 wins! "<<score1<<" - "<<score2<<".\n";
    }
    //Next if statement player 2 wins
    else if(score1<score2)
    {
        cout<<"Player 2 wins! "<<score1<< " - "<<score2<<".\n";
    }

    //Exits program
    return 0;
}

