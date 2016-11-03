/* File: main
 * Author: Ryan Sorice
 * Created on 26 October 2016 8:00 AM
 * Purpose: work on my project
 */

//system libraries
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std; //Namespace in system libraries

//Execution begins here
int main(int argc, char** argv) {

    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of variables
    short n=1,score=0,randQ,dice;
    float pMoney=0;
    char answer, pAnswer,yesno;
    string round1="Round 1: Pop Culture",
           round2="Round 2: Mathematics",
           round3="Round 3: Science",
           round4="Round 4: Language",
           round5="Round 5: History",
           comAnsr;
    
    //Initial output
    cout<<"Welcome to Lightning-Chain Trivia!\n"<<endl;
    cout<<"There are a total of 5 rounds of Trivia questions and each round\n";
    cout<<"has a different theme/genre of Trivia! You must get 5 questions correct\n";
    cout<<"to advance to the next round. If you get even a single question wrong,\n";
    cout<<"your game will be over and you will have to try again. In addition, each\n";
    cout<<"round that is successfully completed will earn you a Cash bonus!!!\n";
    cout<<"The only way to win is to do a full chain of correct answers.(25)\n"<<endl;
    cout<<round1<<endl;
    //Loop for game
    while(n!=0){
        if(score>-1&&score<5){
            randQ=rand()%10+1;
            switch(randQ){                                              //Round 1 switch
                case 1: answer='a'; comAnsr="a. Fill It In"; break;
                case 2: answer='a'; comAnsr="a. Fill It In"; break;
                case 3: answer='a'; comAnsr="a. Fill It In"; break;
                case 4: answer='a'; comAnsr="a. Fill It In"; break;
                case 5: answer='a'; comAnsr="a. Fill It In"; break;
                case 6: answer='a'; comAnsr="a. Fill It In"; break;
                case 7: answer='a'; comAnsr="a. Fill It In"; break;
                case 8: answer='a'; comAnsr="a. Fill It In"; break;
                case 9: answer='a'; comAnsr="a. Fill It In"; break;
                case 10: answer='a'; comAnsr="a. Fill It In"; break;
            }
            cout<<"What is your answer?\n";
            cin>>pAnswer;
            if(pAnswer==answer){
                cout<<"CORRECT!!! "<<comAnsr<<" was the right answer!\n";
                score++;
                if(5-score>0){
                    cout<<5-score<<" questions to go!\n";
                    cout<<"Current Score: "<<score<<endl;
                }
                else{
                    cout<<"Current Score: "<<score<<endl;
                    pMoney+=500;
                    cout<<"You earn $500!\n";
                    cout<<"Your total is $"<<pMoney<<endl;
                    cout<<"Would you like to roll a dice cube for Double or Nothing?\n";
                    cout<<"1-3 Lose it all; 4-6 Double your winnings. Enter 'Y'-Yes 'N'-No\n";
                    cin>>yesno;
                    if(yesno=='y'||yesno=='Y'){
                        dice=rand()%6+1;
                        if(dice>0&&dice<4){
                            pMoney=0;
                            cout<<"You rolled a "<<dice<<". OUCH!!! Your total is $"<<pMoney<<endl;
                            cout<<round2<<endl;
                        }
                        else if(dice>3&&dice<7){
                           pMoney*=2; 
                           cout<<"You rolled a "<<dice<<". YIPPEE!!! Your total is $"<<pMoney<<endl;
                           cout<<round2<<endl;
                        }
                    }
                    else{
                        cout<<round2<<endl;
                    }
                }
            }
            else{
                cout<<"WRONG! "<<comAnsr<<" was the right answer!\n"<<endl;
                cout<<"G A M E  O V E R";
                n=0;
            }
        }    
        else if(score>4&&score<10){
            randQ=rand()%10+1;
            switch(randQ){                                              //Round 2 switch
                case 1: answer='a'; comAnsr="a. Fill It In"; break;
                case 2: answer='a'; comAnsr="a. Fill It In"; break;
                case 3: answer='a'; comAnsr="a. Fill It In"; break;
                case 4: answer='a'; comAnsr="a. Fill It In"; break;
                case 5: answer='a'; comAnsr="a. Fill It In"; break;
                case 6: answer='a'; comAnsr="a. Fill It In"; break;
                case 7: answer='a'; comAnsr="a. Fill It In"; break;
                case 8: answer='a'; comAnsr="a. Fill It In"; break;
                case 9: answer='a'; comAnsr="a. Fill It In"; break;
                case 10: answer='a'; comAnsr="a. Fill It In"; break;
            }
            cout<<"What is your answer?\n";
            cin>>pAnswer;
            if(pAnswer==answer){
                cout<<"CORRECT!!! "<<comAnsr<<" was the right answer!\n";
                score++;
                if(10-score>0){
                    cout<<10-score<<" questions to go!\n";
                    cout<<"Current Score: "<<score<<endl;
                }
                else{
                    cout<<"Current Score: "<<score<<endl;
                    pMoney+=1000;
                    cout<<"You earn $1000!\n";
                    cout<<"Your total is $"<<pMoney<<endl;
                    cout<<"Would you like to roll a dice cube for Double or Nothing?\n";
                    cout<<"1-3 Lose it all; 4-6 Double your winnings. Enter 'Y'-Yes 'N'-No\n";
                    cin>>yesno;
                    if(yesno=='y'||yesno=='Y'){
                        dice=rand()%6+1;
                        if(dice>0&&dice<4){
                            pMoney=0;
                            cout<<"You rolled a "<<dice<<". OUCH!!! Your total is $"<<pMoney<<endl;
                            cout<<round3<<endl;
                        }
                        else if(dice>3&&dice<7){
                           pMoney*=2; 
                           cout<<"You rolled a "<<dice<<". YIPPEE!!! Your total is $"<<pMoney<<endl;
                           cout<<round3<<endl;
                        }
                    }
                    else{
                        cout<<round3<<endl;
                    }
                }
            }
            else{
                cout<<"WRONG! "<<comAnsr<<" was the right answer!\n"<<endl;
                cout<<"G A M E  O V E R";
                n=0;
            }
        }    
        else if(score>9&&score<15){
            randQ=rand()%10+1;
            switch(randQ){                                              //Round 3 switch
                case 1: answer='a'; comAnsr="a. Fill It In"; break;
                case 2: answer='a'; comAnsr="a. Fill It In"; break;
                case 3: answer='a'; comAnsr="a. Fill It In"; break;
                case 4: answer='a'; comAnsr="a. Fill It In"; break;
                case 5: answer='a'; comAnsr="a. Fill It In"; break;
                case 6: answer='a'; comAnsr="a. Fill It In"; break;
                case 7: answer='a'; comAnsr="a. Fill It In"; break;
                case 8: answer='a'; comAnsr="a. Fill It In"; break;
                case 9: answer='a'; comAnsr="a. Fill It In"; break;
                case 10: answer='a'; comAnsr="a. Fill It In"; break;
            }
            cout<<"What is your answer?\n";
            cin>>pAnswer;
            if(pAnswer==answer){
                cout<<"CORRECT!!! "<<comAnsr<<" was the right answer!\n";
                score++;
                if(15-score>0){
                    cout<<15-score<<" questions to go!\n";
                    cout<<"Current Score: "<<score<<endl;
                }
                else{
                    cout<<"Current Score: "<<score<<endl;
                    pMoney+=2000;
                    cout<<"You earn $2000!\n";
                    cout<<"Your total is $"<<pMoney<<endl;
                    cout<<"Would you like to roll a dice cube for Double or Nothing?\n";
                    cout<<"1-3 Lose it all; 4-6 Double your winnings. Enter 'Y'-Yes 'N'-No\n";
                    cin>>yesno;
                    if(yesno=='y'||yesno=='Y'){
                        dice=rand()%6+1;
                        if(dice>0&&dice<4){
                            pMoney=0;
                            cout<<"You rolled a "<<dice<<". OUCH!!! Your total is $"<<pMoney<<endl;
                            cout<<round4<<endl;
                        }
                        else if(dice>3&&dice<7){
                           pMoney*=2;
                           cout<<"You rolled a "<<dice<<". YIPPEE!!! Your total is $"<<pMoney<<endl;
                           cout<<round4<<endl;
                        }
                    }
                    else{
                        cout<<round4<<endl;
                    }
                }
            }
            else{
                cout<<"WRONG! "<<comAnsr<<" was the right answer!\n"<<endl;
                cout<<"G A M E  O V E R";
                n=0;
            }
        }    
            else if(score>14&&score<20){
            randQ=rand()%10+1;
            switch(randQ){                                              //Round 4 switch
                case 1: answer='a'; comAnsr="a. Fill It In"; break;
                case 2: answer='a'; comAnsr="a. Fill It In"; break;
                case 3: answer='a'; comAnsr="a. Fill It In"; break;
                case 4: answer='a'; comAnsr="a. Fill It In"; break;
                case 5: answer='a'; comAnsr="a. Fill It In"; break;
                case 6: answer='a'; comAnsr="a. Fill It In"; break;
                case 7: answer='a'; comAnsr="a. Fill It In"; break;
                case 8: answer='a'; comAnsr="a. Fill It In"; break;
                case 9: answer='a'; comAnsr="a. Fill It In"; break;
                case 10: answer='a'; comAnsr="a. Fill It In"; break;
            }
            cout<<"What is your answer?\n";
            cin>>pAnswer;
            if(pAnswer==answer){
                cout<<"CORRECT!!! "<<comAnsr<<" was the right answer!\n";
                score++;
                if(20-score>0){
                    cout<<20-score<<" questions to go!\n";
                    cout<<"Current Score: "<<score<<endl;
                }
                else{
                    cout<<"You made it to "<<round5<<endl;
                    cout<<"Current Score: "<<score<<endl;
                    pMoney+=5000;
                    cout<<"You earn $5000!\n";
                    cout<<"Your total is $"<<pMoney<<endl;
                    cout<<"Would you like to roll a dice cube for Double or Nothing?\n";
                    cout<<"1-3 Lose it all; 4-6 Double your winnings. Enter 'Y'-Yes 'N'-No\n";
                    cin>>yesno;
                    if(yesno=='y'||yesno=='Y'){
                        dice=rand()%6+1;
                        if(dice>0&&dice<4){
                            pMoney=0;
                            cout<<"You rolled a "<<dice<<". OUCH!!! Your total is $"<<pMoney<<endl;
                            cout<<round5<<endl;
                        }
                        else if(dice>3&&dice<7){
                           pMoney*=2;
                           cout<<"You rolled a "<<dice<<". YIPPEE!!! Your total is $"<<pMoney<<endl;
                           cout<<round5<<endl;
                        }
                    }
                    else{
                        cout<<round5<<endl;
                    }
                }
            }
            else{
                cout<<"WRONG! "<<comAnsr<<" was the right answer!\n"<<endl;
                cout<<"G A M E  O V E R";
                n=0;
            }
        }    
            else if(score>19&&score<25){
            randQ=rand()%10+1;
            switch(randQ){                                              //Round 5 switch
                case 1: answer='a'; comAnsr="a. Fill It In"; break;
                case 2: answer='a'; comAnsr="a. Fill It In"; break;
                case 3: answer='a'; comAnsr="a. Fill It In"; break;
                case 4: answer='a'; comAnsr="a. Fill It In"; break;
                case 5: answer='a'; comAnsr="a. Fill It In"; break;
                case 6: answer='a'; comAnsr="a. Fill It In"; break;
                case 7: answer='a'; comAnsr="a. Fill It In"; break;
                case 8: answer='a'; comAnsr="a. Fill It In"; break;
                case 9: answer='a'; comAnsr="a. Fill It In"; break;
                case 10: answer='a'; comAnsr="a. Fill It In"; break;
            }
            cout<<"What is your answer?\n";
            cin>>pAnswer;
            if(pAnswer==answer){
                cout<<"CORRECT!!! "<<comAnsr<<" was the right answer!\n";
                score++;
                if(25-score){
                    cout<<25-score<<" questions to go!\n";
                    cout<<"Current Score: "<<score<<endl;
                }
                else{
                    cout<<"Current Score: "<<score<<endl;
                    pMoney+=10000;
                    cout<<"You earn $10000!\n";
                    cout<<"Your total is $"<<pMoney<<endl;
                    cout<<"Would you like to roll a dice cube for Double or Nothing?\n";
                    cout<<"1-3 Lose it all; 4-6 Double your winnings. Enter 'Y'-Yes 'N'-No\n";
                    cin>>yesno;
                    if(yesno=='y'||yesno=='Y'){
                        dice=rand()%6+1;
                        if(dice>0&&dice<4){
                            pMoney=0;
                            cout<<"You rolled a "<<dice<<". OUCH!!! Your total is $"<<pMoney<<endl;
                        }
                        else if(dice>3&&dice<7){
                           pMoney*=2; 
                           cout<<"You rolled a "<<dice<<". YIPPEE!!! Your total is $"<<pMoney<<endl;
                        }
                    }
                    cout<<"Game Completed!\n";
                }
            }
            else{
                cout<<"WRONG! "<<comAnsr<<" was the right answer!\n"<<endl;
                cout<<"G A M E  O V E R";
                n=0;
            }
            if(pAnswer==answer&&score==25){
                n=0;
            }
        }    
    }
    if(score==25){
        cout<<"Congratulations! You won Lightning Trivia!\n"<<endl;
        cout<<"Your total winnings are $"<<pMoney<<endl;
        cout<<"W I N N E R!   W I N N E R!   W I N N E R!\n";
    }
    //Exits program
    return 0;
}