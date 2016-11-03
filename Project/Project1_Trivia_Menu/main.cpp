/* File: main.cpp
 * Author: Ryan Sorice
 * Created on 25 October 2016 4:27 PM
 * Purpose: Menu to play both Trivia games (Lightning-Chain Trivia&Random Trivia)
 */

//System libraries
#include <cstdlib>          //Random numbers
#include <iostream>         //Inputs and outputs
#include <ctime>            //Time library

using namespace std;        //Namespace used in system libraries

//Global constants
const float PERCENT=100;    //Percentage conversion

//Function prototypes
void game1();               //Flash-Lightning Trivia Game Function
void game2();               //Random Trivia Game Function

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declaration of Variables
    int menuItm;            //Choice from menu
    
    //Loop until users exits
    do{
        //Prompt for game mode for user input
        cout<<"1.  Type 1  for Lightning-Chain Trivia(1 player)"<<endl;
        cout<<"2.  Type 2  for Random Trivia(2 players)"<<endl;
        cout<<"3.  Type 0 to exit."<<endl;
        cin>>menuItm;

        //Go to the Game mode
        switch(menuItm){
            case 1:game1();break;
            case 2:game2(); break;
            default: break;
        }//End the Switch/Case
    }while(menuItm>0&&menuItm<=10);//Ends the Do-While Loop

    //Exit Program
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Lightning-Chain Trivia ****************************************
//Purpose:  Play Game Mode #1: Lightning-Chain Trivia (1 player)
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void game1(){
    cout<<"Lightning-Chain Trivia"<<endl;
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration of variables
    short n=1,                                      //Counter for loop
          score=0,                                  //Player's initial score
          randQ,dice;                               //Variables for random questions; dice rolls
    float pMoney=0;                                 //Starting value of player's winnings
    char answer, pAnswer,                           //Answer to each question; Player's answer
                   yesno;                           //Variable to determine Double or Nothing wager
    string round1="Round 1: Pop Culture",           //String to display Round 1
           round2="Round 2: Geography",             //String to display Round 2
           round3="Round 3: Science",               //String to display Round 3
           round4="Round 4: History",               //String to display Round 4
           round5="Round 5: Random",                //String to display Round 5
           comAnsr;                                 //String to hold full question answers
    
    //Initial output
    cout<<"Welcome to Lightning-Chain Trivia!\n"<<endl;
    cout<<"There are a total of 5 rounds of Trivia questions and each round\n";
    cout<<"has a different theme/genre of Trivia! You must get 5 questions correct\n";
    cout<<"to advance to the next round. If you get even a single question wrong,\n";
    cout<<"your game will be over and you will have to try again. In addition, each\n";
    cout<<"round that is successfully completed will earn you a Cash bonus!!!\n";
    cout<<"The only way to win is to do a full chain of correct answers.(25)\n"<<endl;
    cout<<round1<<endl;
    
    while(n!=0){                                                        //Loop for game
        if(score>-1&&score<5){                                          //If for the first round of questions
            randQ=rand()%10+1;                                          //Gets number of random question
            switch(randQ){                                              //Round 1 Pop Culture switch(10 questions)
                case 1: answer='b'; comAnsr="b. a sword"; cout<<"What kind of weapon is a falchion?\n"; 
                    cout<<"a. a gun b. a sword c. a staff d. a bomb\n"; break;
                case 2: answer='a'; comAnsr="a. Peter Jackson"; cout<<"Who is the director of the Lord of the Rings trilogy.?\n"; 
                    cout<<"a. Peter Jackson b. Guillermo del Toro c. Quentin Tarantino d. Steven Spielberg\n"; break;
                case 3: answer='a'; comAnsr="a. CNN"; cout<<"Which TV news channel began telecast in 1980?\n"; 
                    cout<<"a. CNN b. Fox News c. BBC d. Star News\n"; break;
                case 4: answer='d'; comAnsr="d. Spotlight"; cout<<"Which movie won the Oscar for Best Picture at the 2016 Academy Awards ceremony?\n"; 
                    cout<<"a. The Martian b. The Big Short c. Bridge of Spies d. Spotlight\n"; break;
                case 5: answer='d'; comAnsr="d. The Big Boss"; cout<<"Which was Bruce Lee's first film in a major roll?\n"; 
                    cout<<"a. Way of the Dragon b. The Game of Death c. Return of the Dragon d. The Big Boss\n"; break;
                case 6: answer='a'; comAnsr="a. Rio de Janeiro"; cout<<"The 2016 Summer Olympics took place in which South American city?\n"; 
                    cout<<"a. Rio de Janeiro b. Buenos Aires c. Santiago d. Sao Paulo\n"; break;
                case 7: answer='a'; comAnsr="a. Citius, Altius, Fortius"; cout<<"What is the motto of Olympics?\n"; 
                    cout<<"a. Citius, Altius, Fortius b. Veni, Vedi, Veci c. Semper idem d. Cogito ergo sum\n"; break;
                case 8: answer='d'; comAnsr="d. Disturbed"; cout<<"What heavy metal band had a hit with a cover of the 1964 Simon and Garfunkel hit song 'The Sound of Silence'.\n"; 
                    cout<<"a. Godsmack b. Slipknot c. Korn d. Disturbed\n"; break;
                case 9: answer='c'; comAnsr="c. Taylor Swift"; cout<<"Which artist won the Grammy for Album of the Year with her album 1989 at the 2016 Grammy Awards?\n"; 
                    cout<<"a. Adele b. Jennifer Lopez c. Taylor Swift d. Meghan Trainor\n"; break;
                case 10: answer='d'; comAnsr="d. Mark Moseley, Redskins"; cout<<"Who was the only 'pure' kicker in NFL history to win the MVP award?\n";
                    cout<<"a. Morten Andersen, Falcons b. Adam Vinatieri, Patriots c. Robbie Gould, Bears d. Mark Moseley, Redskins\n"; break;
            }
            cout<<"What is your answer?\n";                                 //Output; Initiate answer to question
            cin>>pAnswer;
            if(pAnswer==answer){                                            //If player's answer is correct
                cout<<"CORRECT!!! "<<comAnsr<<" was the right answer!\n";   
                score++;                                                    //Score incremented by 1
                if(5-score>0){                                              //If player has more questions to answer for the round
                    cout<<5-score<<" questions to go!\n";                   //Output # questions to go
                    cout<<"Current Score: "<<score<<endl;                   //Output player's score    
                }
                else{                                                       //Else if player completed round
                    cout<<"You made it to "<<round2<<endl;                  //Output advancement to next round
                    cout<<"Current Score: "<<score<<endl;                   //Output player's score
                    pMoney+=500;                                            //$500 added to player's earnings
                    cout<<"You earn $500!\n";
                    cout<<"Your total is $"<<pMoney<<endl;                  //Output; Total earnings
                    cout<<"Would you like to roll a dice cube for Double or Nothing?\n";//Output; Initiate Double or Nothing
                    cout<<"1-3 Lose it all; 4-6 Double your winnings. Enter 'Y'-Yes 'N'-No\n";
                    cin>>yesno;
                    if(yesno=='y'||yesno=='Y'){                             //If player says yes to DoN
                        dice=rand()%6+1;                                    //Gets number of dice roll
                        if(dice>0&&dice<4){                                 //If player loses
                            pMoney=0;                                       //Money resets
                            cout<<"You rolled a "<<dice<<". OUCH!!! Your total is $"<<pMoney<<endl;
                            cout<<round2<<endl;                             //Output name of next round
                        }
                        else if(dice>3&&dice<7){                            //Else if player wins
                           pMoney*=2;                                       //Double player's earning
                           cout<<"You rolled a "<<dice<<". YIPPEE!!! Your total is $"<<pMoney<<endl;
                           cout<<round2<<endl;                              //Output name of next round
                        }
                    }
                    else{                                                   //Else if player says no to DoN
                        cout<<round2<<endl;                                 //Output name of next round
                    }
                }
            }
            else{                                                           //Else player answers incorrectly
                cout<<"WRONG! "<<comAnsr<<" was the right answer!\n"<<endl; //Output correct answer; End of game
                cout<<"G A M E  O V E R\n";
                n=0;                                                        //Set n to 0 to end loop
            }
        }    
        else if(score>4&&score<10){                                         //Else if points qualify for 2nd round
            randQ=rand()%10+1;                                              //Gets number of random question
            switch(randQ){                                                  //Round 2 Geography switch(10 questions)
                case 1: answer='b'; comAnsr="b. Red Sea"; cout<<"Which sea separates Egypt from Saudi Arabia?\n"; 
                    cout<<"a. Black Sea b. Red Sea c. Yellow Sea d. Dead Sea\n"; break;
                case 2: answer='a'; comAnsr="a. Lake Superior"; cout<<"What is the largest freshwater lake in the world?\n"; 
                    cout<<"a. Lake Superior b. Lake Michigan c. Great Bear Lake d. Lake Baikal\n"; break;
                case 3: answer='b'; comAnsr="b. Albania"; cout<<"Tirana is the capital of which country?\n"; 
                    cout<<"a. Romania b. Albania c. Bosnia d. Slovakia\n"; break;
                case 4: answer='d'; comAnsr="d. Finland"; cout<<"Which country is known as Suomi?\n"; 
                    cout<<"a. Norway b. Italy c. France d. Finland\n"; break;
                case 5: answer='d'; comAnsr="d. Death Valley"; cout<<"Which is the lowest point in California?\n"; 
                    cout<<"a. Yap Trench b. Rift Valley c. Mariana Trench d. Death Valley\n"; break;
                case 6: answer='c'; comAnsr="c. 38th"; cout<<"Which parallel divides North Korea and South Korea?\n"; 
                    cout<<"a. 23rd b. 27th c. 38th d. 42nd\n"; break;
                case 7: answer='d'; comAnsr="d. Sacramento"; cout<<"Which is the capital of California?\n"; 
                    cout<<"a. San Diego b. Los Angeles c. San Francisco d. Sacramento\n"; break;
                case 8: answer='d'; comAnsr="d. Bradford"; cout<<"Which British city does not have an underground rail system?\n"; 
                    cout<<"a. Liverpool b. London c. Glasgow d. Bradford\n"; break;
                case 9: answer='b'; comAnsr="b. Shamrock"; cout<<"Which is the national flower of Ireland?\n"; 
                    cout<<"a. Marigold b. Shamrock c. Daffodil d. Jasmine\n"; break;
                case 10: answer='c'; comAnsr="c. South Africa"; cout<<"Which country has 11 official languages?\n"; 
                    cout<<"a. USA b. Canada c. South Africa d. India\n"; break;
            }
            cout<<"What is your answer?\n";                                 //Output; Initiate answer to question
            cin>>pAnswer;
            if(pAnswer==answer){                                            //If player's answer is correct                                              
                cout<<"CORRECT!!! "<<comAnsr<<" was the right answer!\n";
                score++;                                                    //Score incremented by 1
                if(10-score>0){                                             //If player has more questions to answer for the round
                    cout<<10-score<<" questions to go!\n";                  //Output # questions to go
                    cout<<"Current Score: "<<score<<endl;                   //Output player's score
                }
                else{                                                       //Else if player completed round
                    cout<<"You made it to "<<round3<<endl;                  //Output advancement to next round
                    cout<<"Current Score: "<<score<<endl;                   //Output player's score
                    pMoney+=1000;                                           //$1000 added to player's earnings
                    cout<<"You earn $1000!\n";
                    cout<<"Your total is $"<<pMoney<<endl;                  //Output; Total earnings
                    cout<<"Would you like to roll a dice cube for Double or Nothing?\n";//Output; Initiate Double or Nothing
                    cout<<"1-3 Lose it all; 4-6 Double your winnings. Enter 'Y'-Yes 'N'-No\n";
                    cin>>yesno;
                    if(yesno=='y'||yesno=='Y'){                             //If player says yes to DoN
                        dice=rand()%6+1;                                    //Gets number of dice roll
                        if(dice>0&&dice<4){                                 //If player loses
                            pMoney=0;                                       //Money resets
                            cout<<"You rolled a "<<dice<<". OUCH!!! Your total is $"<<pMoney<<endl;
                            cout<<round3<<endl;                             //Output name of next round
                        }
                        else if(dice>3&&dice<7){                            //Else if player wins
                           pMoney*=2;                                       //Double player's earning
                           cout<<"You rolled a "<<dice<<". YIPPEE!!! Your total is $"<<pMoney<<endl;
                           cout<<round3<<endl;                              //Output name of next round
                        }
                    }
                    else{                                                   //Else player says no to DoN
                        cout<<round3<<endl;                                 //Output name of next round
                    }
                }
            }
            else{                                                           //If player answers incorrectly
                cout<<"WRONG! "<<comAnsr<<" was the right answer!\n"<<endl; //Output correct answer; End of game
                cout<<"G A M E  O V E R\n";
                n=0;                                                        //Set n to 0 to end loop
            }
        }    
        else if(score>9&&score<15){                                         //Else if points qualify for 3rd round
            randQ=rand()%10+1;                                              //Gets number of random question
            switch(randQ){                                                  //Round 3 Science switch
                case 1: answer='a'; comAnsr="a. 8,000 miles"; cout<<"What is the diameter of Earth?\n"; 
                    cout<<"a. 8,000 miles b. 15,000 miles c. 5,000 miles d. 20,000 miles\n"; break;
                case 2: answer='a'; comAnsr="a. Velocity"; cout<<"In physics, 'the rate of change of position' is a basic definition of what term?\n"; 
                    cout<<"a. Velocity b. Momentum c. Force d. Acceleration\n"; break;
                case 3: answer='b'; comAnsr="b. Mercury"; cout<<"Which of the following is not a gas?\n"; 
                    cout<<"a. Helium b. Mercury c. Nitrogen d. Oxygen\n"; break;
                case 4: answer='c'; comAnsr="c. Silicon"; cout<<"What is the second most abundant element in the Earth's crust?\n"; 
                    cout<<"a. Calcium b. Carbon c. Silicon d. Iron\n"; break;
                case 5: answer='b'; comAnsr="b. Magnetism"; cout<<"The Weber and Tesla (standard international) measurement units apply to:\n"; 
                    cout<<"a. Sound b. Magnetism c. Rigidity d. Sweetness\n"; break;
                case 6: answer='d'; comAnsr="d. Mariner 4"; cout<<"Which spacecraft first visited Mars?\n"; 
                    cout<<"a. Pioneer 7 b. Viking 2 c. Ulysses d. Mariner 4\n"; break;
                case 7: answer='b'; comAnsr="b. Spiral"; cout<<"What type of galaxy is the Milky Way?\n"; 
                    cout<<"a. Lenticular b. Spiral c. Elliptical d. Irregular\n"; break;
                case 8: answer='c'; comAnsr="c. 1921"; cout<<"When did Albert Einstein win the Nobel Prize for Physics?\n"; 
                    cout<<"a. 1922 b. 1928 c. 1921 d. 1926\n"; break;
                case 9: answer='c'; comAnsr="c. Uranus"; cout<<"What is the seventh planet from the sun?\n"; 
                    cout<<"a. Saturn b. Neptune c. Uranus d. Mercury\n"; break;
                case 10: answer='b'; comAnsr="b. Herbert Spencer"; cout<<"Who coined the phrase Survival of the fittest?\n"; 
                    cout<<"a. Charles Darwin b. Herbert Spencer c. Thomas Huxley d. Joseph Hooker\n"; break;
            }
            cout<<"What is your answer?\n";                                 //Output; Initiate answer to question
            cin>>pAnswer;
            if(pAnswer==answer){                                            //If player's answer is correct
                cout<<"CORRECT!!! "<<comAnsr<<" was the right answer!\n";
                score++;                                                    //Score incremented by 1
                if(15-score>0){                                             //If player has more questions to answer for the round
                    cout<<15-score<<" questions to go!\n";                  //Output # questions to go
                    cout<<"Current Score: "<<score<<endl;                   //Output player's score
                }
                else{                                                       //Else if player completed round
                    cout<<"You made it to "<<round4<<endl;                  //Output advancement to next round
                    cout<<"Current Score: "<<score<<endl;                   //Output player's score
                    pMoney+=2000;                                           //$2000 added to player's earnings
                    cout<<"You earn $2000!\n";                              
                    cout<<"Your total is $"<<pMoney<<endl;                  //Output; Total earnings
                    cout<<"Would you like to roll a dice cube for Double or Nothing?\n";//Output; Initiate Double or Nothing        
                    cout<<"1-3 Lose it all; 4-6 Double your winnings. Enter 'Y'-Yes 'N'-No\n";
                    cin>>yesno;                                             
                    if(yesno=='y'||yesno=='Y'){                             //If player says yes to DoN
                        dice=rand()%6+1;                                    //Gets number of dice roll
                        if(dice>0&&dice<4){                                 //If player loses
                            pMoney=0;                                       //Money resets
                            cout<<"You rolled a "<<dice<<". OUCH!!! Your total is $"<<pMoney<<endl;
                            cout<<round4<<endl;                             //Output name of next round
                        }
                        else if(dice>3&&dice<7){                            //Else if player wins
                           pMoney*=2;                                       //Double player's earning
                           cout<<"You rolled a "<<dice<<". YIPPEE!!! Your total is $"<<pMoney<<endl;
                           cout<<round4<<endl;                              //Output name of next round
                        }
                    }
                    else{                                                   //Else player says no to DoN
                        cout<<round4<<endl;                                 //Output name of next round
                    }
                }
            }
            else{                                                           //If player answers incorrectly
                cout<<"WRONG! "<<comAnsr<<" was the right answer!\n"<<endl; //Output correct answer; End of game
                cout<<"G A M E  O V E R\n";                                 
                n=0;                                                        //Set n to 0 to end loop
            }
        }    
        else if(score>14&&score<20){                                        //Else if points qualify for 4th round
            randQ=rand()%10+1;                                              //Gets number of random question
            switch(randQ){                                                  //Round 4 History switch
                case 1: answer='a'; comAnsr="a. 1989"; cout<<"What year did the Cold War officially end?\n"; 
                    cout<<"a. 1989 b. 1987 c. 1986 d. 1988\n"; break;
                case 2: answer='b'; comAnsr="b. Portugal"; cout<<"Which European country ceased to be a monarchy in 1910?\n"; 
                    cout<<"a. France b. Portugal c. Italy d. Austria\n"; break;
                case 3: answer='d'; comAnsr="d. American Civil War"; cout<<"The Battle of Antietam was fought during which war?\n"; 
                    cout<<"a. WWI b. WWII c. Boer War d. American Civil War\n"; break;
                case 4: answer='d'; comAnsr="d. George Washington"; cout<<"Who was the first president of the United States?\n"; 
                    cout<<"a. James Monroe b. John Adams c. Thomas Jefferson d. George Washington\n"; break;
                case 5: answer='d'; comAnsr="d. Abraham Lincoln"; cout<<"Which United States president ended slavery in America?\n"; 
                    cout<<"a. Andrew Jackson b. James Buchanan c. Thomas Jefferson d. Abraham Lincoln\n"; break;
                case 6: answer='c'; comAnsr="c. Luxembourg"; cout<<"Which of the following countries is a founding member of NATO?\n"; 
                    cout<<"a. Greece b. Spain c. Luxembourg d. Turkey\n"; break;
                case 7: answer='c'; comAnsr="c. Trinidad"; cout<<"Ferdinand Magellan began his voyage around the world with five ships. Which did he command?\n"; 
                    cout<<"a. Conception b. Santiago c. Trinidad d. Victoria\n"; break;
                case 8: answer='a'; comAnsr="a. Sveinn Bjornsson"; cout<<"Who was Iceland’s first president?\n"; 
                    cout<<"a. Sveinn Bjornsson b. Jon Sigurdsson c. Olaf Tryggvvason d. Vigdis Finnbogadottir\n"; break;
                case 9: answer='a'; comAnsr="a. Moses and Monotheism"; cout<<"Which historical novel was written by Sigmund Freud?\n"; 
                    cout<<"a. Moses and Monotheism b. Ben Hur c. Waverley d. Gladiator\n"; break;
                case 10: answer='b'; comAnsr="b. Douglas MacArthur"; cout<<"After Japan's defeat in WWII, who was in command of Japan?\n"; 
                    cout<<"a. George Patton b. Douglas MacArthur c. Jeremiah Boyle d. Robert Lee\n"; break;
            }
            cout<<"What is your answer?\n";                                 //Output; Initiate answer to question
            cin>>pAnswer;
            if(pAnswer==answer){                                            //If player's answer is correct
                cout<<"CORRECT!!! "<<comAnsr<<" was the right answer!\n";   
                score++;                                                    //Score incremented by 1
                if(20-score>0){                                             //If player has more questions to answer for the round
                    cout<<20-score<<" questions to go!\n";                  //Output # questions to go
                    cout<<"Current Score: "<<score<<endl;                   //Output player's score
                }
                else{                                                       //Else if player completed round
                    cout<<"You made it to "<<round5<<endl;                  //Output of advancement to next round
                    cout<<"Current Score: "<<score<<endl;                   //Output player's score
                    pMoney+=5000;                                           //$5000 added to player's earnings
                    cout<<"You earn $5000!\n";                              
                    cout<<"Your total is $"<<pMoney<<endl;                  //Output; Total earnings
                    cout<<"Would you like to roll a dice cube for Double or Nothing?\n";//Output; Initiate Double or Nothing
                    cout<<"1-3 Lose it all; 4-6 Double your winnings. Enter 'Y'-Yes 'N'-No\n";
                    cin>>yesno;
                    if(yesno=='y'||yesno=='Y'){                             //If player says yes to DoN
                        dice=rand()%6+1;                                    //Gets number of dice roll
                        if(dice>0&&dice<4){                                 //If player loses
                            pMoney=0;                                       //Money resets
                            cout<<"You rolled a "<<dice<<". OUCH!!! Your total is $"<<pMoney<<endl;
                            cout<<round5<<endl;                             //Output name of next round
                        }
                        else if(dice>3&&dice<7){                            //Else if player wins
                           pMoney*=2;                                       //Double player's earning
                           cout<<"You rolled a "<<dice<<". YIPPEE!!! Your total is $"<<pMoney<<endl;
                           cout<<round5<<endl;                              //Output name of next round
                        }
                    }
                    else{                                                   //Else player says no to DoN
                        cout<<round5<<endl;                                 //Output name of next round
                    }
                }
            }
            else{                                                           //If player answers incorrectly 
                cout<<"WRONG! "<<comAnsr<<" was the right answer!\n"<<endl; //Output correct answer; End of game
                cout<<"G A M E  O V E R\n";
                n=0;                                                        //Set n to 0 to end loop
            }
        }    
        else if(score>19&&score<25){                                        //Else if points qualify for 5th(final) round 
            randQ=rand()%10+1;                                              //Gets number of random question
            switch(randQ){                                                  //Round 5 Random switch
                case 1: answer='c'; comAnsr="c. Violet"; cout<<"Which of the following is not a secondary color?\n"; 
                    cout<<"a. Purple b. Green c. Violet d. Orange\n"; break;
                case 2: answer='d'; comAnsr="d. 4"; cout<<"How many strings does a cello have?\n"; 
                    cout<<"a. 8 b. 5 c. 6 d. 4\n"; break;
                case 3: answer='c'; comAnsr="c. Greek"; cout<<"What nationality of soldiers wear a white kilt?\n"; 
                    cout<<"a. Scandinavian b. Polish c. Greek d. Dutch\n"; break;
                case 4: answer='d'; comAnsr="d. Amnon"; cout<<"In the bible, who is the eldest son of David?\n"; 
                    cout<<"a. Solomon b. Absalom c. Jonathan d. Amnon\n"; break;
                case 5: answer='c'; comAnsr="c. Jane Austen"; cout<<"Who is the author of Pride and Prejudice?\n"; 
                    cout<<"a. Agatha Christie b. Bernard Shaw c. Jane Austen d. William Shakespeare\n"; break;
                case 6: answer='a'; comAnsr="a. Five"; cout<<"How many lines are in a limerick?\n"; 
                    cout<<"a. Five b. Seven c. Ten d. Twelve\n"; break;
                case 7: answer='a'; comAnsr="a. Yellow"; cout<<"What color jersey is worn by the winners of each stage of the Tour De France?\n"; 
                    cout<<"a. Yellow b. Blue c. Red d. White\n"; break;
                case 8: answer='b'; comAnsr="b. 64"; cout<<"How many squares are there on a chess board?\n"; 
                    cout<<"a. 48 b. 64 c. 81 d. 100\n"; break;
                case 9: answer='a'; comAnsr="a. Pasta"; cout<<"Orzo is what type of foodstuff?\n"; 
                    cout<<"a. Pasta b. Cheese c. Berry d. Meat\n"; break;
                case 10: answer='a'; comAnsr="a. a half"; cout<<"What is the square root of a quarter?\n"; 
                    cout<<"a. a half b. an eighth c. a sixteenth Lake d. a third\n"; break;
            }
            cout<<"What is your answer?\n";                                 //Output; Initiate answer to question
            cin>>pAnswer;                                                   
            if(pAnswer==answer){                                            //If player's answer is correct
                cout<<"CORRECT!!! "<<comAnsr<<" was the right answer!\n";   
                score++;                                                    //Score incremented by 1
                if(25-score){                                               //If player has more questions to answer for the round
                    cout<<25-score<<" questions to go!\n";                  //Output # questions to go
                    cout<<"Current Score: "<<score<<endl;                   //Output player's score
                }
                else{                                                       //Else if player completed round
                    cout<<"Current Score: "<<score<<endl;                   //Output player's score
                    pMoney+=10000;                                          //$10000 added to player's earnings
                    cout<<"You earn $10000!\n";                             
                    cout<<"Your total is $"<<pMoney<<endl;                  //Output; Total earnings
                    cout<<"Would you like to roll a dice cube for Double or Nothing?\n";//Output; Initiate Double or Nothing
                    cout<<"1-3 Lose it all; 4-6 Double your winnings. Enter 'Y'-Yes 'N'-No\n";
                    cin>>yesno;
                    if(yesno=='y'||yesno=='Y'){                             //If player says yes to DoN
                        dice=rand()%6+1;                                    //Gets number of dice roll
                        if(dice>0&&dice<4){                                 //If player loses
                            pMoney=0;                                       //Money resets
                            cout<<"You rolled a "<<dice<<". OUCH!!! Your total is $"<<pMoney<<endl;
                        }
                        else if(dice>3&&dice<7){                            //Else if player wins
                           pMoney*=2;                                       //Double player's earning
                           cout<<"You rolled a "<<dice<<". YIPPEE!!! Your total is $"<<pMoney<<endl;
                        }
                    }
                    cout<<"Game Completed!\n";                              //Output game completion
                }
            }
            else{                                                           //If player answers incorrectly
                cout<<"WRONG! "<<comAnsr<<" was the right answer!\n"<<endl; //Output correct answer; End of game
                cout<<"G A M E  O V E R\n";                                 
                n=0;                                                        //Set n to 0 to end loop
            }
            if(pAnswer==answer&&score==25){                                 //If statement to end game if player has completed all rounds
                n=0;                                                        //Set n to 0 to end loop
            }
        }    
    }
    if(score==25){                                                          //If player has won the game
        cout<<"Congratulations! You won Lightning Trivia!\n"<<endl;         //Output; Winnings
        cout<<"Your total winnings are $"<<pMoney<<endl;                                        
        cout<<"W I N N E R!   W I N N E R!   W I N N E R!\n";               
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//*************************   Random Trivia ****************************************
//Purpose:  Play Game Mode #2: Random Trivia (2 players)
//Inputs:   Inputs to the function here  -> Description, Range, Units
//Output:   Outputs to the function here -> Description, Range, Units
//******************************************************************************
void game2(){
    cout<<"Random Trivia"<<endl;
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declaration of variables
    short score1=0,score2=0,                //Initial scores for players 1 and 2
          randNum;                          //Random number to select Trivia Question
    float questC=0;                         //Counts total number of questions asked during the game
    char answer,                            //Letter of answer of each question (a,b,c,d)
         guess1,guess2;                     //Players 1 and 2 guess at each question
    string fullAns;                         //String for letter of answer plus definition of answer
    
    //Initial output
    cout<<"Welcome to the Random Trivia Game!\n"<<endl;
    cout<<"Each round a Trivia question will be presented with 4 different answers\n";
    cout<<"and both players will take a guess at the answer(Enter a,b,c, or d).\n";
    cout<<"If either player guesses right, they will earn 1 point for the round. The\n";
    cout<<"first player that achieves 25 points will be declared the winner.\n"<<endl;
    
    while(score1<25&&score2<25){            //Loop to play Trivia while either player is under 25 points
        randNum=rand()%100+1;               //Gets random number between 1 and 100
        switch(randNum){                    //Switch for 1-100 Trivia questions
            case 1: answer='a'; fullAns="a. Lake Superior"; cout<<"What is the largest freshwater lake in the world?\n"; 
                cout<<"a. Lake Superior b. Lake Michigan c. Great Bear Lake d. Lake Baikal\n"; break;
            case 2: answer='b'; fullAns="b. a sword"; cout<<"What kind of weapon is a falchion?\n"; 
                cout<<"a. a gun b. a sword c. a staff d. a bomb\n"; break;
            case 3: answer='c'; fullAns="c. Uranus"; cout<<"What is the seventh planet from the sun?\n"; 
                cout<<"a. Saturn b. Neptune c. Uranus d. Mercury\n"; break;
            case 4: answer='d'; fullAns="d. Bradford"; cout<<"Which British city does not have an underground rail system?\n"; 
                cout<<"a. Liverpool b. London c. Glasgow d. Bradford\n"; break;
            case 5: answer='a'; fullAns="a. Peter Jackson"; cout<<"Who is the director of the Lord of the Rings trilogy.?\n"; 
                cout<<"a. Peter Jackson b. Guillermo del Toro c. Quentin Tarantino d. Steven Spielberg\n"; break;
            case 6: answer='b'; fullAns="b. the Bishop"; cout<<"Which chess piece can only move diagonally?\n"; 
                cout<<"a. the Pawn b. the Bishop c. the Queen d. the Rook\n"; break;
            case 7: answer='a'; fullAns="a. Yellow"; cout<<"What color jersey is worn by the winners of each stage of the Tour De France?\n"; 
                cout<<"a. Yellow b. Blue c. Red d. White\n"; break;
            case 8: answer='c'; fullAns="c. Violet"; cout<<"Which of the following is not a secondary color?\n"; 
                cout<<"a. Purple b. Green c. Violet d. Orange\n"; break;
            case 9: answer='d'; fullAns="d. Three"; cout<<"How many valves does a trumpet have?\n"; 
                cout<<"a. Four b. Five c. Two d. Three\n"; break;
            case 10: answer='a'; fullAns="a. 1989"; cout<<"What year did the Cold War officially end?\n"; 
                cout<<"a. 1989 b. 1987 c. 1986 d. 1988\n"; break;
            case 11: answer='b'; fullAns="b. 1999"; cout<<"What year did the euro get introduced as legal currency on the world market?\n"; 
                cout<<"a. 1995 b. 1999 c. 2001 d. 1997\n"; break;
            case 12: answer='a'; fullAns="a. 8,000 miles"; cout<<"What is the diameter of Earth?\n"; 
                cout<<"a. 8,000 miles b. 15,000 miles c. 5,000 miles d. 20,000 miles\n"; break;
            case 13: answer='b'; fullAns="b. 64"; cout<<"How many squares are there on a chess board?\n"; 
                cout<<"a. 48 b. 64 c. 81 d. 100\n"; break;
            case 14: answer='d'; fullAns="d. 4"; cout<<"How many strings does a cello have?\n"; 
                cout<<"a. 8 b. 5 c. 6 d. 4\n"; break;
            case 15: answer='c'; fullAns="c. Greek"; cout<<"What nationality of soldiers wear a white kilt?\n"; 
                cout<<"a. Scandinavian b. Polish c. Greek d. Dutch\n"; break;
            case 16: answer='b'; fullAns="b. 12"; cout<<"How many sides does a dodecagon have?\n"; 
                cout<<"a. 10 b. 12 c. 11 d. 14\n"; break;
            case 17: answer='c'; fullAns="c. 9"; cout<<"How many symphonies did Beethoven compose?\n"; 
                cout<<"a. 7 b. 8 c. 9 d. 10\n"; break;
            case 18: answer='a'; fullAns="a. Frank Whittle"; cout<<"Who invented the jet engine?\n"; 
                cout<<"a. Frank Whittle b. Richard Trevithick c. Karl Benz d. Rudolf Diesel\n"; break;
            case 19: answer='d'; fullAns="d. Elysian Fields"; cout<<"In Greek mythology, what was the final resting place of the souls of the heroic and the virtuous?\n"; 
                cout<<"a. Safaniya Fields b. Fields of Hyrule c. Strawberry Fields d. Elysian Fields\n"; break;
            case 20: answer='b'; fullAns="b. Portugal"; cout<<"Which European country ceased to be a monarchy in 1910?\n"; 
                cout<<"a. France b. Portugal c. Italy d. Austria\n"; break;
            case 21: answer='c'; fullAns="c. Silicon"; cout<<"What is the second most abundant element in the Earth's crust?\n"; 
                cout<<"a. Calcium b. Carbon c. Silicon d. Iron\n"; break;
            case 22: answer='a'; fullAns="a. Velocity"; cout<<"In physics, 'the rate of change of position' is a basic definition of what term?\n"; 
                cout<<"a. Velocity b. Momentum c. Force d. Acceleration\n"; break;
            case 23: answer='a'; fullAns="a. Pasta"; cout<<"Orzo is what type of foodstuff?\n"; 
                cout<<"a. Pasta b. Cheese c. Berry d. Meat\n"; break;
            case 24: answer='b'; fullAns="b. Albania"; cout<<"Tirana is the capital of which country?\n"; 
                cout<<"a. Romania b. Albania c. Bosnia d. Slovakia\n"; break;
            case 25: answer='c'; fullAns="c. Teflon"; cout<<"Polytetrafluoroethylene (PTFE) is better known by what DuPont brand name?\n"; 
                cout<<"a. Corian b. Kevlar c. Teflon d. Tyvek\n"; break;
            case 26: answer='d'; fullAns="d. American Civil War"; cout<<"The Battle of Antietam was fought during which war?\n"; 
                cout<<"a. WWI b. WWII c. Boer War d. American Civil War\n"; break;
            case 27: answer='d'; fullAns="d. a tree"; cout<<"A dendogram is a diagram of what shape?\n"; 
                cout<<"a. an egg b. a diamond c. a pyramid d. a tree\n"; break;
            case 28: answer='a'; fullAns="a. a half"; cout<<"What is the square root of a quarter?\n"; 
                cout<<"a. a half b. an eighth c. a sixteenth Lake d. a third\n"; break;
            case 29: answer='b'; fullAns="b. Tennessee Williams"; cout<<"Who is the author of “A Streetcar Named Desire?\n"; 
                cout<<"a. Ian Fleming b. Tennessee Williams c. Salmon Rushdie d. Jhumpa Lahiri\n"; break;
            case 30: answer='a'; fullAns="a. Sep. 1850"; cout<<"When did California officially become a state of the US?\n"; 
                cout<<"a. Sep. 1850 b. Apr. 1864 c. Dec. 1900 d. Mar 1872\n"; break;
            case 31: answer='d'; fullAns="d. Sacramento"; cout<<"Which is the capital of California?\n"; 
                cout<<"a. San Diego b. Los Angeles c. San Francisco d. Sacramento\n"; break;
            case 32: answer='d'; fullAns="d. Death Valley"; cout<<"Which is the lowest point in California?\n"; 
                cout<<"a. Yap Trench b. Rift Valley c. Mariana Trench d. Death Valley\n"; break;
            case 33: answer='b'; fullAns="b. Magnetism"; cout<<"The Weber and Tesla (standard international) measurement units apply to:\n"; 
                cout<<"a. Sound b. Magnetism c. Rigidity d. Sweetness\n"; break;
            case 34: answer='c'; fullAns="c. 3"; cout<<"How many miles is a league?\n"; 
                cout<<"a. 2 b. 4 c. 3 d. 5\n"; break;
            case 35: answer='b'; fullAns="b. Shamrock"; cout<<"Which is the national flower of Ireland?\n"; 
                cout<<"a. Marigold b. Shamrock c. Daffodil d. Jasmine\n"; break;
            case 36: answer='c'; fullAns="c. John Wilkes Booth"; cout<<"Who killed US President Abraham Lincoln?\n"; 
                cout<<"a. Lee Harvey Oswald b. John Hinckley c. John Wilkes Booth d. Michael Schiavo\n"; break;
            case 37: answer='a'; fullAns="a. CNN"; cout<<"Which TV news channel began telecast in 1980?\n"; 
                cout<<"a. CNN b. Fox News c. BBC d. Star News\n"; break;
            case 38: answer='b'; fullAns="b. Mercury"; cout<<"Which of the following is not a gas?\n"; 
                cout<<"a. Helium b. Mercury c. Nitrogen d. Oxygen\n"; break;
            case 39: answer='a'; fullAns="a. Ivory"; cout<<"What are the tusks of elephants made of?\n"; 
                cout<<"a. Ivory b. Gold c. Bone d. Silver\n"; break;
            case 40: answer='d'; fullAns="d. Finland"; cout<<"Which country is known as Suomi?\n"; 
                cout<<"a. Norway b. Italy c. France d. Finland\n"; break;
            case 41: answer='c'; fullAns="c. Jane Austen"; cout<<"Who is the author of Pride and Prejudice?\n"; 
                cout<<"a. Agatha Christie b. Bernard Shaw c. Jane Austen d. William Shakespeare\n"; break;
            case 42: answer='d'; fullAns="d. Amnon"; cout<<"In the bible, who is the eldest son of David?\n"; 
                cout<<"a. Solomon b. Absalom c. Jonathan d. Amnon\n"; break;
            case 43: answer='a'; fullAns="a. Euclid"; cout<<"Who is considered the father of geometry?\n"; 
                cout<<"a. Euclid b. Alexander c. Socrates d. Pythagoras\n"; break;
            case 44: answer='b'; fullAns="b. Red Sea"; cout<<"Which sea separates Egypt from Saudi Arabia?\n"; 
                cout<<"a. Black Sea b. Red Sea c. Yellow Sea d. Dead Sea\n"; break;
            case 45: answer='c'; fullAns="c. South Africa"; cout<<"Which country has 11 official languages?\n"; 
                cout<<"a. USA b. Canada c. South Africa d. India\n"; break;
            case 46: answer='a'; fullAns="a. Five"; cout<<"How many lines are in a limerick?\n"; 
                cout<<"a. Five b. Seven c. Ten d. Twelve\n"; break;
            case 47: answer='a'; fullAns="a. salt"; cout<<"What is sodium chloride?\n"; 
                cout<<"a. salt b. onion c. pepper d. vinegar\n"; break;
            case 48: answer='d'; fullAns="d. George Washington"; cout<<"Who was the first president of the United States?\n"; 
                cout<<"a. James Monroe b. John Adams c. Thomas Jefferson d. George Washington\n"; break;
            case 49: answer='c'; fullAns="c. Thomas Jefferson"; cout<<"Whose portrait appears on the $2 note?\n"; 
                cout<<"a. Alexander Hamilton b. Ulysses Grant c. Thomas Jefferson d. Abraham Lincoln\n"; break;
            case 50: answer='a'; fullAns="a. Sensible"; cout<<"What is the antonym of daft?\n"; 
                cout<<"a. Sensible b. Light c. Swoon d. Peak\n"; break;
            case 51: answer='d'; fullAns="d. The Big Boss"; cout<<"Which was Bruce Lee's first film in a major roll?\n"; 
                cout<<"a. Way of the Dragon b. The Game of Death c. Return of the Dragon d. The Big Boss\n"; break;
            case 52: answer='d'; fullAns="d. 1791"; cout<<"What year did Wolfgang Amadeus Mozart die?\n"; 
                cout<<"a. 1796 b. 1800 c. 1792 d. 1791\n"; break;
            case 53: answer='b'; fullAns="b. Spring"; cout<<"During which season do apple flowers bloom?\n"; 
                cout<<"a. Autumn b. Spring c. Winter d. Summer\n"; break;
            case 54: answer='c'; fullAns="c. John Wheeler"; cout<<"Who coined the term black hole?\n"; 
                cout<<"a. John Mitchell b. Pierre Simon Laplace c. John Wheeler d. Isaac Newton\n"; break;
            case 55: answer='a'; fullAns="a. Evolution"; cout<<"Which theory was propounded by Charles Darwin?\n"; 
                cout<<"a. Evolution b. Gravity c. Planetary Motion d. Atoms\n"; break;
            case 56: answer='b'; fullAns="b. Herbert Spencer"; cout<<"Who coined the phrase Survival of the fittest?\n"; 
                cout<<"a. Charles Darwin b. Herbert Spencer c. Thomas Huxley d. Joseph Hooker\n"; break;
            case 57: answer='a'; fullAns="a. Animalia"; cout<<"Which is the kingdom of dog?\n"; 
                cout<<"a. Animalia b. Protesta c. Fungi d. Monera\n"; break;
            case 58: answer='c'; fullAns="c. Smell"; cout<<"Which sense of dog is most highly developed?\n"; 
                cout<<"a. Taste b. Touch c. Smell d. Sight\n"; break;
            case 59: answer='c'; fullAns="c. Trinidad"; cout<<"Ferdinand Magellan began his voyage around the world with five ships. Which did he command?\n"; 
                cout<<"a. Conception b. Santiago c. Trinidad d. Victoria\n"; break;
            case 60: answer='d'; fullAns="d. Force"; cout<<"What does newton measure?\n"; 
                cout<<"a. Electric Charge b. Length c. Power d. Force\n"; break;
            case 61: answer='c'; fullAns="c. Felidae"; cout<<"Which is the family of lion?\n"; 
                cout<<"a. Chicldae b. Canidae c. Felidae d. Mustelidae\n"; break;
            case 62: answer='b'; fullAns="b. Spiral"; cout<<"What type of galaxy is the Milky Way?\n"; 
                cout<<"a. Lenticular b. Spiral c. Elliptical d. Irregular\n"; break;
            case 63: answer='d'; fullAns="d. Democritus"; cout<<"Who is credited with the discovery of the Milky Way?\n"; 
                cout<<"a. Aristotle b. Plato c. Socrates d. Democritus\n"; break;
            case 64: answer='b'; fullAns="b. Douglas MacArthur"; cout<<"After Japan's defeat in WWII, who was in command of Japan?\n"; 
                cout<<"a. George Patton b. Douglas MacArthur c. Jeremiah Boyle d. Robert Lee\n"; break;
            case 65: answer='d'; fullAns="d. God of War"; cout<<"Who is Mars in mythology?\n"; 
                cout<<"a. God of Weather b. King of Peace c. God of Hunting d. God of War\n"; break;
            case 66: answer='d'; fullAns="d. Mariner 4"; cout<<"Which spacecraft first visited Mars?\n"; 
                cout<<"a. Pioneer 7 b. Viking 2 c. Ulysses d. Mariner 4\n"; break;
            case 67: answer='c'; fullAns="c. Fear"; cout<<"What is the meaning of phobos?\n"; 
                cout<<"a. Love b. Envy c. Fear d. Greed\n"; break;
            case 68: answer='c'; fullAns="c. Siberian"; cout<<"Which is the largest species of tiger?\n"; 
                cout<<"a. Bengal b. Indochinese c. Siberian d. Sumatran\n"; break;
            case 69: answer='c'; fullAns="c. William Herschel"; cout<<"Who discovered Uranus?\n"; 
                cout<<"a. Gerard Kuiper b. Pervical Lowell c. William Herschel d. James Watt\n"; break;
            case 70: answer='b'; fullAns="b. Propose marriage to men"; cout<<"What, according to tradition, were women allowed to do on February 29th?\n"; 
                cout<<"a. Swim b. Propose marriage to men c. Wear men's clothes d. Ride horses\n"; break;
            case 71: answer='b'; fullAns="b. Beware the Ides of March."; cout<<"What was the warning given to Julius Caesar?\n"; 
                cout<<"a. Hell had no fury like a woman scorned. b. Beware the Ides of March. c. A sword is hanging over your head. d. Goose is cooked.\n"; break;
            case 72: answer='a'; fullAns="a. Cleopatra"; cout<<"Who gave birth to Julius Caesar’s son Caesarian?\n"; 
                cout<<"a. Cleopatra b. Constantia c. Messalina d. Octavia\n"; break;
            case 73: answer='a'; fullAns="a. Sveinn Bjornsson"; cout<<"Who was Iceland’s first president?\n"; 
                cout<<"a. Sveinn Bjornsson b. Jon Sigurdsson c. Olaf Tryggvvason d. Vigdis Finnbogadottir\n"; break;
            case 74: answer='c'; fullAns="c. South Land"; cout<<"What is the meaning of Australia?\n"; 
                cout<<"a. North Land b. East Land c. South Land d. West Land\n"; break;
            case 75: answer='c'; fullAns="c. Kangaroo"; cout<<"Which animal carries its babies in a pouch?\n"; 
                cout<<"a. Lion b. Tiger c. Kangaroo d. Zebra\n"; break;
            case 76: answer='c'; fullAns="c. Luxembourg"; cout<<"Which of the following countries is a founding member of NATO?\n"; 
                cout<<"a. Greece b. Spain c. Luxembourg d. Turkey\n"; break;
            case 77: answer='c'; fullAns="c. 248"; cout<<"How many years does Pluto take to orbit the Sun?\n"; 
                cout<<"a. 160 b. 184 c. 248 d. 512\n"; break;
            case 78: answer='a'; fullAns="a. Bull Shark"; cout<<"Which shark is the most frequent attacker of people?\n"; 
                cout<<"a. Bull Shark b. Tiger Shark c. Blue Shark d. Nurse Shark\n"; break;
            case 79: answer='a'; fullAns="a. African pygmy squirrel"; cout<<"Which is the smallest species of squirrel?\n"; 
                cout<<"a. African pygmy squirrel b. Red squirrel c. Flying squirrel d. Fox squirrel\n"; break;
            case 80: answer='b'; fullAns="b. Beluga"; cout<<"Which whales are known as sea canaries because of their songs?\n"; 
                cout<<"a. Orca b. Beluga c. Fin d. Killer\n"; break;
            case 81: answer='a'; fullAns="a. Moses and Monotheism"; cout<<"Which historical novel was written by Sigmund Freud?\n"; 
                cout<<"a. Moses and Monotheism b. Ben Hur c. Waverley d. Gladiator\n"; break;
            case 82: answer='c'; fullAns="c. 38th"; cout<<"Which parallel divides North Korea and South Korea?\n"; 
                cout<<"a. 23rd b. 27th c. 38th d. 42nd\n"; break;
            case 83: answer='a'; fullAns="a. Citius, Altius, Fortius"; cout<<"What is the motto of Olympics?\n"; 
                cout<<"a. Citius, Altius, Fortius b. Veni, Vedi, Veci c. Semper idem d. Cogito ergo sum\n"; break;
            case 84: answer='c'; fullAns="c. Continents"; cout<<"What do the five rings on Olympic flag represent?\n"; 
                cout<<"a. Fingers b. Toes c. Continents d. Oceans\n"; break;
            case 85: answer='d'; fullAns="d. Ten"; cout<<"What is the number of biblical plagues?\n"; 
                cout<<"a. Six b. Four c. Twelve d. Ten\n"; break;
            case 86: answer='b'; fullAns="b. 24"; cout<<"How many teeth are in a crocodile jaw?\n"; 
                cout<<"a. 12 b. 24 c. 16 d. 32\n"; break;
            case 87: answer='d'; fullAns="d. 1519"; cout<<"What year did Spain invade Mexico?\n"; 
                cout<<"a. 1492 b. 1498 c. 1511 d. 1519\n"; break;
            case 88: answer='b'; fullAns="b. Four satellites of Jupiter"; cout<<"What did Galileo Galilei discover in 1610?\n"; 
                cout<<"a. Two satellites of Uranus b. Four satellites of Jupiter c. Pluto d. Neptune\n"; break;
            case 89: answer='c'; fullAns="c. Valentina Tereshkova"; cout<<"Who was the first woman in space?\n"; 
                cout<<"a. Sunita Williams b. Kalpana Chawla c. Valentina Tereshkova d. Nadia Petrova\n"; break;
            case 90: answer='a'; fullAns="a. Rouble"; cout<<"Which is the currency of Russia?\n"; 
                cout<<"a. Rouble b. Dollar c. Yen d. Pound\n"; break;
            case 91: answer='b'; fullAns="b. Leo Tolstoy"; cout<<"Who wrote War and Peace?\n"; 
                cout<<"a. Maxim Gorky b. Leo Tolstoy c. Karl Marx d. Fyodor Dostoevsky\n"; break;
            case 92: answer='c'; fullAns="c. 1921"; cout<<"When did Albert Einstein win the Nobel Prize for Physics?\n"; 
                cout<<"a. 1922 b. 1928 c. 1921 d. 1926\n"; break;
            case 93: answer='b'; fullAns="b. Saul"; cout<<"Who was the first King of the Jews?\n"; 
                cout<<"a. Samuel b. Saul c. David d. Solomon\n"; break;
            case 94: answer='c'; fullAns="c. Taylor Swift"; cout<<"Which artist won the Grammy for Album of the Year with her album 1989 at the 2016 Grammy Awards?\n"; 
                cout<<"a. Adele b. Jennifer Lopez c. Taylor Swift d. Meghan Trainor\n"; break;
            case 95: answer='d'; fullAns="d. Spotlight"; cout<<"Which movie won the Oscar for Best Picture at the 2016 Academy Awards ceremony?\n"; 
                cout<<"a. The Martian b. The Big Short c. Bridge of Spies d. Spotlight\n"; break;
            case 96: answer='a'; fullAns="a. Rio de Janeiro"; cout<<"The 2016 Summer Olympics took place in which South American city?\n"; 
                cout<<"a. Rio de Janeiro b. Buenos Aires c. Santiago d. Sao Paulo\n"; break;
            case 97: answer='d'; fullAns="d. Disturbed"; cout<<"What heavy metal band had a hit with a cover of the 1964 Simon and Garfunkel hit song 'The Sound of Silence'.\n"; 
                cout<<"a. Godsmack b. Slipknot c. Korn d. Disturbed\n"; break;
            case 98: answer='a'; fullAns="a. Franklin D. Roosevelt"; cout<<"Which United States president founded Social Security?\n"; 
                cout<<"a. Franklin D. Roosevelt b. Herbert Hoover c. Abraham Lincoln d. Harry S. Truman\n"; break;
            case 99: answer='d'; fullAns="d. Abraham Lincoln"; cout<<"Which United States president ended slavery in America?\n"; 
                cout<<"a. Andrew Jackson b. James Buchanan c. Thomas Jefferson d. Abraham Lincoln\n"; break;
            case 100: answer='a'; fullAns="a. 841"; cout<<"What is 29^2?\n"; 
                cout<<"a. 841 b. 900 c. 784 d. 961\n"; break;
        }
        //Output to players to initiate their answer to the question
        cout<<"Player 1, what is your guess?\n";
        cin>>guess1;
        cout<<"Player 2, what is your guess?\n";
        cin>>guess2;
        //If both players answer correctly
        if(guess1==answer&&guess2==answer){
            cout<<"Both players are correct! "<<fullAns<<" was the correct answer.\n";
            cout<<"You each earn a point.\n"<<endl;
            score1++;       //Adds 1 point to player 1s score
            score2++;       //Adds 1 point to player 2s score
        }
        //If player 1 is correct; Not player 2
        else if(guess1==answer&&guess2!=answer){
            cout<<"Player 1 is correct! "<<fullAns<<" was the correct answer.\n";
            cout<<"Player 1 earns a point.\n"<<endl;
            score1++;       //Adds 1 point to player 1s score
        }
        //If player 2 is correct; Not player 1
        else if(guess1!=answer&&guess2==answer){
            cout<<"Player 2 is correct! "<<fullAns<<" was the correct answer.\n";
            cout<<"Player 2 earns a point.\n"<<endl;
            score2++;       //Adds 1 point to player 2s score
        }
        //If both players are wrong
        else if(guess1!=answer&&guess2!=answer){
            cout<<"Both players are incorrect! "<<fullAns<<" was the correct answer.\n";
            cout<<"No one earns a point.\n"<<endl;
        }
        //Output of the current score
        cout<<"Player 1  |  Player 2\n";
        cout<<"    "<<score1<<"            "<<score2<<endl<<endl;
        
        questC++; //Counts total questions presented
        
        //If no one has reached 25 point goal; Output
        if(score1!=25&&score2!=25){
            cout<<"Next Question!\n"<<endl;
        }
        //Else Output; Game Over
        else{
            cout<<"Game Complete!\n"<<endl;
        }
    }
    //Output of correct question percentage
    cout<<"Player 1 had a "<<(score1/questC)*PERCENT<<"% correct response rate!\n";
    cout<<"Player 2 had a "<<(score2/questC)*PERCENT<<"% correct response rate!\n";
    //If both players win; Tie at 25 points
    if(score1==25&&score2==25){
        cout<<"Wow both players achieved 25 points at the same time!!!\n";
        cout<<"You both win!\n";
    }
    //If player one has won
    else if(score1==25&&score2!=25){
        cout<<"Player 1 is the first to achieve 25 points!\n";
        cout<<"Player 1 is the victor!\n";
    }
    //Else player 2 has won
    else{
        cout<<"Player 2 is the first to achieve 25 points!\n";
        cout<<"Player 2 is the victor!\n";
    }
}

