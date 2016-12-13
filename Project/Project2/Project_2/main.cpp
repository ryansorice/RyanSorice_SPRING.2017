/* File: main
 * Author: Ryan Sorice
 * Created on 4 December 2016 11:23 AM
 * Purpose: Dungeon Survival Game
 */

//System Libraries
#include <string>                   //Library for strings/string arrays
#include <iostream>                 //Library for inputs and outputs
#include <ctime>                    //Time library for random numbers
#include <cstdlib>                  //Library for random numbers

using namespace std;                //Name-space in system libraries

//User Libraries

//Global Variables

//Function Prototypes
void statFil(int [], string[], int, short);     //Function to fill player's initial statistics
void initMap(char[][80], int, int);             //Function to create/fill initial game map
void mapDisp(char [][80], int, int);            //Function to display current game map
void pStats(int [], string [], int, string,int);//Function to display player's current stats

//Function to play in the Dungeon (the mode to complete the game)
void fight(int [], int, int &, int &, int, int, char[][80], string, int &, bool &);
void shop(int[], int &);                        //Function to display/access game shop
void mgkFite(int [], int[], int, int[]);        //Function to fight with magic power
void atkFite(int [], int[], int, int[]);        //Function to fight with attack power

//Execution begins here
int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declaration/Initiation of variables
    int const STATSZE=3,MAPSIZ1=10,MAPSIZ2=80;                      //Array sizes (map sizes, stat size)
    string player,                                                  //String for player's name
           statNam[STATSZE];                                        //String array for stat names
    int stats[STATSZE],                                             //Int array for player's stats
        menuItm,                                                    //Int to control game menu
        gold=0,                                                     //Int for player's gold
        level=1,sublvl=1,                                           //Ints for level/sublevel
        atkPwr=1.5,mgkPwr=5.0;                                      //Ints for magic and attack powers
    short attrib;                                                   //Short for attribute value
    char map[MAPSIZ1][MAPSIZ2];                                     //Character array for game map
    bool victory=false,exit=false;                                  //Booleans to control the game ending
    
    //Initial output/User initiates their character's name
    cout<<"Welcome to the Dungeon Survival game!\n"<<endl<<"In this game, you and your character will\n";
    cout<<"venture through a total of 7 levels, conquering formidable enemies,\n";
    cout<<"powering up and earning the chance to reap great rewards!\n"<<endl;
    cout<<"First, what is your character's name?\n";
    cin>>player;
    //Output; User initiates prefered attribute
    cout<<"Alright "<<player<<", your adventure begins now!\n"<<endl;
    cout<<"What attribute is most important to you? Enter '1' for Strength, '2'\n";
    cout<<"for Intelligence, '3' for Endurance\n";
    cin>>attrib;
    
    //Fill players stats/Display stats
    statFil(stats,statNam,STATSZE,attrib);
    cout<<"Your stats have been set.\n"<<endl;
    pStats(stats,statNam,STATSZE,player,gold);
    
    //Creates game map/Outputs to user
    initMap(map,MAPSIZ1,MAPSIZ2);
    cout<<"This is your dungeon(map).\n"<<endl;
    mapDisp(map,MAPSIZ1,MAPSIZ2);
    
    //Do-while loop to play agme
    do{   
        //Which feature to access on the game menu
        cout<<"Game Map       - (Press '1')[View your game progress]\n";
        cout<<"Player's Stats - (Press '2')[View your strength]\n";
        cout<<"The Dungeon    - (Press '3')[Fight with your character to win the game]\n";
        cout<<"The Shop       - (Press '4')[Source of extra power]\n";
        cout<<"Quit Game      - (Press '5')[Quit your existing game]\n";
        cin>>menuItm;
        //Switch statement for selected game menu
        switch(menuItm){
            case 1:mapDisp(map,MAPSIZ1,MAPSIZ2);break;
            case 2:pStats(stats,statNam,STATSZE,player,gold);break;
            case 3:fight(stats,STATSZE,level,sublvl,atkPwr,mgkPwr,map,player,gold,victory);break;
            case 4:shop(stats,gold); break;
            case 5:exit=true;
        }//End the Switch/Case
    }while(victory==false&&exit==false);//Ends the Do-While Loop
    
    //If player completed the game/dungeon
    if(victory==true){
        //Output victory title and game credits
        cout<<"You have been victorious in your Adventure!\n"<<endl;
        cout<<"You earned the title 'Master of the Universe!'\n"<<endl;
        cout<<"Credits: \n"<<"Ryan Sorice - Concept/Engineering\n"<<endl;
    }
    cout<<"Come play again!";           //Final output
    
    //Exits program
    return 0;
}
//Function to perform attack(strength) based fight
void atkFite(int stats[], int enemy[], int atkPwr, int tmpStat[]){
    int bonus=rand()%3+1,eBonus=rand()%3+1;             //Variables to apply random damage bonus for enemy/user
    enemy[0]-=(stats[1]*(atkPwr*bonus));                //Enemy HP subtracted by player's damage multiplied by bonus
    tmpStat[0]-=(enemy[1]*eBonus);                      //User HP subtracted by enemy's damage multiplied by bonus
}
//Function to perform magic(intelligence) based fight
void mgkFite(int stats[], int enemy[], int mgkPwr, int tmpStat[]){
    int youGues,cpuGues=rand()%3+1,                     //Variables for enemy and player magic guess
        eBonus=rand()%3+1;                              //Variable for enemy damage bonus
    //Output which element user wants to summon; User initiates 1, 2 or 3
    cout<<"Choose an element:\n"<<"Fire '1'\n"<<"Water '2'\n"<<"Earth '3'\n";
    cin>>youGues;
    if(youGues==cpuGues) enemy[0]-=(stats[2]*mgkPwr);   //If player guesses right; Damage with magik pwr multiplied by INT
    else enemy[0]-=(stats[2]*1.25);                     //Else player guesses wrong; Damage with mgk mult. by 1.25
    tmpStat[0]-=(enemy[1]*eBonus);                      //User damaged by enemy's attack mult. by bonus
}
//Function to display and utilize shop
void shop(int stats[], int &pGold){
    int item=1;                                             //Variable to control which buff is purchased
    //Do-while loop to access shop
    do{
        //Output all 9 item buffs with gold prices
        cout<<"G: 3500   "<<"G: 3500   "<<"G: 3500\n";
        cout<<"ATK +35   "<<"INT +35   "<<"HP +450\n";
        cout<<"  (1)     "<<"  (2)     "<<"  (3)  \n"<<endl;
        cout<<"G: 7500   "<<"G: 7500   "<<"G: 7500\n";
        cout<<"ATK +75   "<<"INT +75   "<<"HP +1000\n";
        cout<<"  (4)     "<<"  (5)     "<<"  (6)  \n"<<endl;
        cout<<"G: 15000   "<<"G: 15000   "<<"G: 15000\n";
        cout<<"ATK +175   "<<"INT +175   "<<"HP +2000\n";
        cout<<"  (7)     "<<"   (8)    "<<"    (9)  \n"<<endl;
        cout<<"Gold: "<<pGold<<endl;                                //Output user's gold
        cout<<"(0) to Exit\n";                                      //Output how to exit shop
        cin>>item;                                                  //User initiates what item to buy
        //Switch to purchase player's selected buff
        switch(item){
            case 1: if(pGold<3500) cout<<"Insufficient Funds!\n";   //If gold insufficient
                    else {                                          //Else apply buff/subtract gold cost
                        stats[1]+=35;
                        pGold-=3500;
                    }break;
            case 2: if(pGold<3500) cout<<"Insufficient Funds!\n";   //If gold insufficient
                    else {                                          //Else apply buff/subtract gold cost
                        stats[2]+=35;
                        pGold-=3500;
                    }break;
            case 3: if(pGold<3500) cout<<"Insufficient Funds!\n";   //If gold insufficient
                    else {                                          //Else apply buff/subtract gold cost
                        stats[0]+=450;
                        pGold-=3500;
                    }break;
            case 4: if(pGold<7500) cout<<"Insufficient Funds!\n";   //If gold insufficient
                    else {                                          //Else apply buff/subtract gold cost
                        stats[1]+=75;
                        pGold-=7500;
                    }break;
            case 5: if(pGold<7500) cout<<"Insufficient Funds!\n";   //If gold insufficient
                    else {                                          //Else apply buff/subtract gold cost
                        stats[2]+=75;
                        pGold-=7500;
                    }break;
            case 6: if(pGold<7500) cout<<"Insufficient Funds!\n";   //If gold insufficient
                    else {                                          //Else apply buff/subtract gold cost
                        stats[0]+=1000;
                        pGold-=7500;
                    }break;
            case 7: if(pGold<15000) cout<<"Insufficient Funds!\n";  //If gold insufficient
                    else {                                          //Else apply buff/subtract gold cost
                        stats[1]+=175;
                        pGold-=15000;
                    }break;
            case 8: if(pGold<15000) cout<<"Insufficient Funds!\n";  //If gold insufficient
                    else {                                          //Else apply buff/subtract gold cost
                        stats[2]+=175;
                        pGold-=15000;
                    }break;
            case 9: if(pGold<15000) cout<<"Insufficient Funds!\n";  //If gold insufficient
                    else {                                          //Else apply buff/subtract gold cost
                        stats[0]+=2500;
                        pGold-=15000;
                    }
        }
    }while(item>0&&item<10);
}
//Function to fight in the dungeon/complete the game
void fight(int stats[], int statSze, int &level, int &sublvl, int atkPwr, int mgkPwr, char map[][80], 
    string player, int &gold, bool &victory){
    int tmpStat[statSze],enemy[statSze],    //Arrays for player stats and enemy stats
        attack;                             //Variable to control atk or mgk fighting
    char yesno='y';                         //Variable to control dungeon loop
    while(yesno=='y'||yesno=='Y'){          //Loop to play dungeon
        bool sub=false,lvlwin=false;        //Booleans to control sublevel/level completed
        tmpStat[0]=stats[0];                //Fill temporary stats with player's stats; HP
        tmpStat[1]=stats[1];                //Fill temporary stats with player's stats; ATK
        tmpStat[2]=stats[2];                //Fill temporary stats with player's stats; INT
        //If player on level 1
        if(level==1){
            //If player on sublevel 1
            if(sublvl==1){                                                  
                cout<<"Level 1 - 1\n";                                  //Output level and sublevel
                enemy[0]=500; enemy[1]=5;                               //Set enemy stats
                while(enemy[0]>0&&tmpStat[0]>0){                        //Loop to fight
                    //Output enemy and player HP
                    cout<<"Knight I    "<<player<<endl<<"HP :"<<enemy[0]<<"     HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";//Output atk or mgk
                    cin>>attack;                                        //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);  //If atk; damage function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat);//Else if mgk; damage function
                    else cout<<"Enter 1 or 2!\n";                       //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                          //If sublevel complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";             //Output player wins
                    //Output rewards and buffs earned
                    cout<<"You earned 500 Gold!\n"<<"HP +50\n"<<"ATK +3\n"<<"INT +3\n";
                    gold+=500; stats[0]+=50; stats[1]+=3; stats[2]+=3;  //Add rewards and buffs to totals
                    map[5][0]='X';                                      //Map position of sublevel 'X' for complete
                    sub=true;                                           //Sublevel boolean true
                }
                else cout<<"DEFEAT..!\n";                               //Else sublevel incomplete
            }
            //Else if player on sublevel 2
            else if(sublvl==2){
                cout<<"Level 1 - 2\n";                                  //Output level and sublevel
                enemy[0]=750; enemy[1]=30;                              //Set enemy stats
                while(enemy[0]>0&&tmpStat[0]>0){                        //Loop to fight
                    //Output enemy and player HP
                    cout<<"Knight II    "<<player<<endl<<"HP :"<<enemy[0]<<"      HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";//Output atk or mgk
                    cin>>attack;                                        //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);  //If atk; damage function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat);//Else if mgk; damage function
                    else cout<<"Enter 1 or 2!\n";                       //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                          //If sublevel/level complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";             //Output player wins
                    //Output rewards and buffs earned
                    cout<<"You earned 1000 Gold!\n"<<"HP +100\n"<<"ATK +5\n"<<"INT +5\n";
                    gold+=1000; stats[0]+=100; stats[1]+=5; stats[2]+=5;//Add rewards and buffs to totals
                    map[5][1]='X';                                      //Map position of sublevel 'X' for complete
                    lvlwin=true;                                        //Level win boolean true
                }
                else cout<<"DEFEAT..!\n";                               //Else sublevel/level incomplete
            }
        }
        //Else if player on level 2
        else if(level==2){
            //If player on sublevel 1
            if(sublvl==1){
                cout<<"Level 2 - 1\n";                                  //Output level and sublevel
                enemy[0]=1000; enemy[1]=55;                             //Set enemy stats
                while(enemy[0]>0&&tmpStat[0]>0){                        //Loop to fight
                    //Output enemy and user HP
                    cout<<"Knight III    "<<player<<endl<<"HP :"<<enemy[0]<<"       HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";//Output atk or mgk
                    cin>>attack;                                        //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);  //If atk; damage function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat);//Else if mgk; damage function
                    else cout<<"Enter 1 or 2!\n";                       //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                          //If sublevel complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";             //Output player wins
                    //Output rewards and buffs earned
                    cout<<"You earned 1200 Gold!\n"<<"HP +120\n"<<"ATK +6\n"<<"INT +6\n";
                    gold+=1200; stats[0]+=120; stats[1]+=6; stats[2]+=6;//Add rewards and buffs to totals
                    map[3][11]='X';                                     //Map position of sublevel 'X' for complete
                    sub=true;                                           //Sublevel boolean true
                }
                else cout<<"DEFEAT..!\n";                               //Else sublevel incomplete
            }
            //Else if player on sublevel 2
            else if(sublvl==2){
                cout<<"Level 2 - 2\n";                                  //Output level and sublevel
                enemy[0]=1200; enemy[1]=65;                             //Initiate enemy stats
                while(enemy[0]>0&&tmpStat[0]>0){                        //Loop to fight
                    //Output enemy and player HP
                    cout<<"The Dark Knight    "<<player<<endl<<"HP :"<<enemy[0]<<"          HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";//Output atk or mgk
                    cin>>attack;                                        //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);  //If atk; damage function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat);//Else if mgk; damage function
                    else cout<<"Enter 1 or 2!\n";                       //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                          //If sublevel/level complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";             //Output player wins
                    //Output rewards and buffs earned
                    cout<<"You earned 2000 Gold!\n"<<"HP +200\n"<<"ATK +9\n"<<"INT +9\n";
                    gold+=2000; stats[0]+=200; stats[1]+=9; stats[2]+=9;//Add buffs and rewards to totals
                    map[3][12]='X';                                     //Map position of sublevel 'X' for complete
                    lvlwin=true;                                        //Level win boolean true
                }
                else cout<<"DEFEAT..!\n";                               //Else sublevel/level incomplete
            }
        }
        //Else if player on level 3
        else if(level==3){
            //If player on sublevel 1
            if(sublvl==1){
                cout<<"Level 3 - 1\n";                                      //Output level and sublevel
                enemy[0]=1400; enemy[1]=70;                                 //Enemy stats set
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight
                    //Output enemy and user HP
                    cout<<"Assassin 1    "<<player<<endl<<"HP :"<<enemy[0]<<"     HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Outputs atk or mgk
                    cin>>attack;                                            //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output user wins
                    //Output buffs and rewards earned
                    cout<<"You earned 2250 Gold!\n"<<"HP +250\n"<<"ATK +12\n"<<"INT +12\n";
                    gold+=2250; stats[0]+=250; stats[1]+=12; stats[2]+=12;  //Add buffs and rewards to totals
                    map[7][22]='X';                                         //Map position of sublevel 'X' for complete
                    sub=true;                                               //Sublevel boolean true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel incomplete
            }
            //Else if player on sublevel 2
            else if(sublvl==2){                         
                cout<<"Level 3 - 2\n";                                      //Output level and sublevel
                enemy[0]=2500; enemy[1]=78;                                 //Set enemy stats
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight
                    //Output enemy and user HP
                    cout<<"Assassin Leader    "<<player<<endl<<"HP :"<<enemy[0]<<"      HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel/level complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output player wins
                    //Output rewards and buffs earned
                    cout<<"You earned 3000 Gold!\n"<<"HP +320\n"<<"ATK +16\n"<<"INT +16\n";
                    gold+=3000; stats[0]+=320; stats[1]+=16; stats[2]+=16;  //Add buffs and rewards to totals
                    map[7][23]='X';                                         //Map position of sublevel 'X' for complete
                    lvlwin=true;                                            //Level win boolean true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel/level incomplete
            }
        }
        //Else if player on level 4
        else if(level==4){
            //If player on sublevel 1
            if(sublvl==1){
                cout<<"Level 4 - 1\n";                                      //Output level and sublevel
                enemy[0]=3000; enemy[1]=90;                                 //Set enemy stats
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight
                    //Output enemy and player HP
                    cout<<"Bandit 1    "<<player<<endl<<"HP :"<<enemy[0]<<"     HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Ouput player wins
                    //Output rewards and buffs earned
                    cout<<"You earned 3250 Gold!\n"<<"HP +350\n"<<"ATK +18\n"<<"INT +18\n";
                    gold+=3250; stats[0]+=350; stats[1]+=18; stats[2]+=18;  //Add buffs and rewards to totals
                    map[6][33]='X';                                         //Map position of sublevel 'X' for complete
                    sub=true;                                               //Sublevel boolean true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel incomplete
            }
            //Else if player on sublevel 2
            else if(sublvl==2){
                cout<<"Level 4 - 2\n";                                      //Output level and sub
                enemy[0]=3500; enemy[1]=100;                                //Enemy stats set
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight
                    //Output enemy and player HP
                    cout<<"Bandit II    "<<player<<endl<<"HP :"<<enemy[0]<<"     HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output player wins
                    //Output rewards and buffs earned
                    cout<<"You earned 3500 Gold!\n"<<"HP +400\n"<<"ATK +21\n"<<"INT +21\n";
                    gold+=3500; stats[0]+=400; stats[1]+=21; stats[2]+=21;  //Add buffs and rewards to totals
                    map[6][34]='X';                                         //Map position of sublevel 'X' for complete
                    sub=true;                                               //Sublevel boolean true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel incomplete
            }
            //Else if player on sublevel 3
            else if(sublvl==3){
                cout<<"Level 4 - 3\n";                                      //Output level and sublevel
                enemy[0]=4000; enemy[1]=118;                                //Set enemy stat array
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight
                    //Output enemy and player HP
                    cout<<"Bandit King    "<<player<<endl<<"HP :"<<enemy[0]<<"      HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output mgk or atk
                    cin>>attack;                                            //User intiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage with function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage with function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel/level complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output player wins
                    //Output buffs and rewards earned
                    cout<<"You earned 4250 Gold!\n"<<"HP +450\n"<<"ATK +25\n"<<"INT +25\n";
                    gold+=4250; stats[0]+=450; stats[1]+=25; stats[2]+=25;  //Add buffs and rewards to totals
                    map[6][35]='X';                                         //Map position of sublevel 'X' for complete
                    lvlwin=true;                                            //Level win boolean true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel/level incomplete
            }
        }
        //Else if player on level 5
        else if(level==5){
            //If player on sublevel 1
            if(sublvl==1){              
                cout<<"Level 5 - 1\n";                                      //Output level and sublevel
                enemy[0]=4600; enemy[1]=135;                                //Set enemy stat array
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight enemy
                    //Output enemy and user HP
                    cout<<"Demi-God 1    "<<player<<endl<<"HP :"<<enemy[0]<<"      HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage enemy with function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage enemy with function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output player wins
                    //Output rewards and buffs earned
                    cout<<"You earned 4500 Gold!\n"<<"HP +450\n"<<"ATK +25\n"<<"INT +25\n";
                    gold+=4500; stats[0]+=450; stats[1]+=25; stats[2]+=25;  //Add buffs and rewards to totals
                    map[4][44]='X';                                         //Map position of sublevel 'X' for complete
                    sub=true;                                               //Sublevel boolean true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel incomplete
            }
            //Else if player on sublevel 2
            else if(sublvl==2){
                cout<<"Level 5 - 2\n";                                      //Output level and sublevel
                enemy[0]=5100; enemy[1]=150;                                //Set enemy stat array
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight enemy
                    //Output enemy and player HP
                    cout<<"Demi-God II    "<<player<<endl<<"HP :"<<enemy[0]<<"      HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User intiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage enemy with function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage enemy with function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output player wins
                    //Output buffs and rewards earned
                    cout<<"You earned 4500 Gold!\n"<<"HP +450\n"<<"ATK +25\n"<<"INT +25\n";
                    gold+=4500; stats[0]+=450; stats[1]+=25; stats[2]+=25;  //Add buffs and rewards to totals
                    map[4][45]='X';                                         //Map position of sublevel 'X' for complete
                    sub=true;                                               //sublevel boolean true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel incomplete
            }
            //Else if player on sublevel 3
            else if(sublvl==3){
                cout<<"Level 5 - 3\n";                                      //Output level and sublevel
                enemy[0]=6000; enemy[1]=180;                                //Set enemy array stats
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight enemy
                    //Output enemy and player HP
                    cout<<"Fierce Diety    "<<player<<endl<<"HP :"<<enemy[0]<<"        HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage enemy from function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage enemy from function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output player wins
                    //Output buffs and rewards earned
                    cout<<"You earned 5000 Gold!\n"<<"HP +525\n"<<"ATK +30\n"<<"INT +30\n";
                    gold+=5000; stats[0]+=525; stats[1]+=30; stats[2]+=30;  //Add buffs and rewards to totals
                    map[4][46]='X';                                         //Map position of sublevel 'X' for complete
                    lvlwin=true;                                            //Level win boolean true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel/level incomplete
            }
        }
        //Else if player on level 6
        else if(level==6){
            //If player on sublevel 1
            if(sublvl==1){
                cout<<"Level 6 - 1\n";                                      //Output level and sublevel
                enemy[0]=7000; enemy[1]=218;                                //Set enemy stat array
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight enemy
                    //Output enemy and player HP
                    cout<<"Guardian 1    "<<player<<endl<<"HP :"<<enemy[0]<<"        HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage enemy from function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage enemy from function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output player wins
                    //Output buffs and rewards
                    cout<<"You earned 5000 Gold!\n"<<"HP +500\n"<<"ATK +28\n"<<"INT +28\n";
                    gold+=5000; stats[0]+=500; stats[1]+=28; stats[2]+=28;  //Add buffs and rewards to totals
                    map[2][55]='X';                                         //Map position of sublevel 'X' for complete
                    sub=true;                                               //Sublevel boolean true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel incomplete
            }
            //Else if player on sublevel 2
            else if(sublvl==2){
                cout<<"Level 6 - 2\n";                                      //Output level and sublevel
                enemy[0]=8200; enemy[1]=260;                                //Set enemy stat array
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight enemy
                    //Output enemy and player HP
                    cout<<"Guardian II    "<<player<<endl<<"HP :"<<enemy[0]<<"        HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage enemy from function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage enemy from function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output player wins
                    //Output rewards and buffs
                    cout<<"You earned 5000 Gold!\n"<<"HP +500\n"<<"ATK +28\n"<<"INT +28\n";
                    gold+=5000; stats[0]+=500; stats[1]+=28; stats[2]+=28;  //Add buffs and rewards to totals
                    map[2][56]='X';                                         //Map position of sublevel 'X' for complete
                    sub=true;                                               //Set sublevel boolean to true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel incomplete
            }
            //Else if player on sublevel 3
            else if(sublvl==3){
                cout<<"Level 6 - 3\n";                                      //Output level and sublevel
                enemy[0]=9500; enemy[1]=295;                                //Set enemy stat array
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight enemy
                    //Output enemy and player HP
                    cout<<"The Gate Keeper    "<<player<<endl<<"HP :"<<enemy[0]<<"          HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User Initiate attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage enemy with function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage enemy with function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel and level complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output player wins
                    //Output rewards and buffs
                    cout<<"You earned 6000 Gold!\n"<<"HP +600\n"<<"ATK +35\n"<<"INT +35\n";
                    gold+=6000; stats[0]+=600; stats[1]+=35; stats[2]+=35;  //Add rewards and buffs to totals
                    map[2][57]='X';                                         //Map position of sublevel 'X' for complete
                    lvlwin=true;                                            //Level win boolean set to true
                }
                else cout<<"DEFEAT..!\n";                                   //Else level incomplete
            }
        }
        //Else if player on level 7
        else if(level==7){
            //If player on sublevel 1
            if(sublvl==1){
                cout<<"Level 7 - 1\n";                                      //Output level & sublevel
                enemy[0]=11500; enemy[1]=332;                               //Set enemy stats array
                while(enemy[0]>0&&tmpStat[0]>0){                            //While-Loop to fight
                    //Output enemy's & player's HP
                    cout<<"Star Warrior    "<<player<<endl<<"HP :"<<enemy[0]<<"        HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User initiates atk or mgk
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If attack; attack enemy from function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if magic; attack enemy from function
                    else cout<<"Enter 1 or 2!\n";                           //Else if invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel complete
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output user wins
                    //Output rewards and buffs
                    cout<<"You earned 6250 Gold!\n"<<"HP +575\n"<<"ATK +33\n"<<"INT +33\n";
                    gold+=6250; stats[0]+=575; stats[1]+=33; stats[2]+=33;  //Add buffs and gold to totals
                    map[4][66]='X';                                         //Map position of sublevel 'X' for complete
                    sub=true;                                               //Sublevel boolean set to true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel incomplete
            }
            //Else If player on sublevel 2
            else if(sublvl==2){
                cout<<"Level 7 - 2\n";                                      //Output level and sublevel
                enemy[0]=13500; enemy[1]=390;                               //Set enemy array stats
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight enemy
                    //Output enemy and player HP
                    cout<<"The Space Bender    "<<player<<endl<<"HP :"<<enemy[0]<<"         HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage enemy from function
                    else if(attack==2) mgkFite(stats,enemy,mgkPwr,tmpStat); //Else if mgk; damage enemy from function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel completed
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output user wins
                    //Output rewards and buffs
                    cout<<"You earned 6250 Gold!\n"<<"HP +575\n"<<"ATK +33\n"<<"INT +33\n";
                    gold+=6250; stats[0]+=575; stats[1]+=33; stats[2]+=33;  //Add buffs and gold to totals
                    map[4][67]='X';                                         //Map position of sublevel 'X' for complete
                    sub=true;                                               //Sublevel boolean set to true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel incomplete
            }
            //Else If player on sublevel 3
            else if(sublvl==3){
                cout<<"Level 7 - 3\n";                                      //Output level and sublevel
                enemy[0]=17500; enemy[1]=475;                               //Set enemy stats array
                while(enemy[0]>0&&tmpStat[0]>0){                            //Loop to fight enemy
                    //Output enemy and player HP
                    cout<<"The Time Lord    "<<player<<endl<<"HP :"<<enemy[0]<<"          HP :"<<tmpStat[0]<<endl<<endl;
                    cout<<"ATTACK (Enter 1)"<<endl<<"MAGIC  (Enter 2)\n";   //Output atk or mgk
                    cin>>attack;                                            //User initiates attack
                    if(attack==1) atkFite(stats,enemy,atkPwr,tmpStat);      //If atk; damage enemy with function
                    else if(attack==2)mgkFite(stats,enemy,mgkPwr,tmpStat);  //Else if mgk; damage enemy with function
                    else cout<<"Enter 1 or 2!\n";                           //Else invalid entry
                }
                if(enemy[0]<=0&&tmpStat[0]>0){                              //If sublevel and level completed
                    cout<<"VICTORY!\n"<<"Stage Cleared!\n";                 //Output user wins
                    //Output rewards and buffs
                    cout<<"You earned 10000 Gold!\n"<<"HP +1000\n"<<"ATK +50\n"<<"INT +50\n";
                    gold+=10000; stats[0]+=1000; stats[1]+=50; stats[2]+=50;//Add buffs and gold to totals
                    map[4][68]='X';                                         //Map position of sublevel 'X' for complete
                    lvlwin=true;                                            //Level win boolean set to true
                }
                else cout<<"DEFEAT..!\n";                                   //Else sublevel and level incomplete
            }
        }
        if(sub==true) sublvl++;             //If sublevel complete, add 1 to sublevel
        if(lvlwin==true){                   //If level complete
            level++;                        //Add 1 to level
            sublvl=1;                       //Reset sublevel to 1
        }
        if(level==8) {                      //If game/dungeon has been won
            cout<<"DUNGEON COMPLETE!!!\n";  //Output victory to user
            victory=true;                   //Victory boolean set to true to end game loop
            yesno='n';                      //Character set to 'n' to end dungeon function
        }
        else{                               //Else game/dungeon incomplete
            cout<<"Continue fighting?\n";   //Output to user
            cin>>yesno;                     //User initiaties to continue or stop dungeon fighting
        }
    }
}
//Function to Display Player's stats
void pStats(int stats[], string statNme[], int statSiz, string player, int gold){
    char yesno='y';                             //Character to control while-loop
    cout<<player<<"'s Statistics :\n";          //Output player's name
    for(int n=0;n<statSiz;n++){                 //For-loop to display player's stats
        cout<<statNme[n]<<"   "<<stats[n]<<endl;//Output stat name and stat value
    }
    cout<<"Gold: "<<gold<<endl;                 //Output player's gold
    while(yesno=='y'||yesno=='Y'){              //While-loop to view or not view statistics
        //Output; User initiaties to keep viewing
        cout<<"Continue Viewing Stats? ('n' - to exit )\n";
        cin>>yesno;
    }
}
//Function to Display game map
void mapDisp(char gameMap[][80], int mapSiz1, int mapSiz2){
    char yesno='y';                     //Character for while-loop
    for(int n=0;n<mapSiz1;n++){         //Loop to display each row of map array
        for(int m=0;m<mapSiz2;m++){     //Nested-Loop to display each column of map array
            cout<<gameMap[n][m];        //Output each character in array
            if(m==mapSiz2-1) cout<<endl;//If map reaches row length, go to next line
        }
    }
    cout<<endl;                         //Output line space between game map and text
    while(yesno=='y'||yesno=='Y'){      //While-Loop to view or not view game map
        //Output;User initializes to keep viewing or exit
        cout<<"Continue Viewing Map? ('n' - to exit)\n";
        cin>>yesno;
    }
}
//Function to initialize/create the game map
void initMap(char map[][80], int siz1, int siz2){
    for(int n=0;n<siz1;n++){                            //Loop for array map rows
        for(int m=0;m<siz2;m++){                        //Nested-Loop for array map columns
            if(n==0) map[n][m]='#';                     //If to create top map boarder of '#'
            else if(n==2&&m==11) map[n][m]='L';         //Else if 'L' position for 'Lv2'
            else if(n==2&&m==12) map[n][m]='v';         //Else if 'v' position for 'Lv2'
            else if(n==2&&m==13) map[n][m]='2';         //Else if '2' position for 'Lv2'
            else if(n==3&&(m>10&&m<13)) map[n][m]='O';  //Else if 'O' for 'Lv2' sub-levels
            else if(n==4&&m==0) map[n][m]='L';          //Else if 'L' position for 'Lv1'
            else if(n==4&&m==1) map[n][m]='v';          //Else if 'v' position for 'Lv1'
            else if(n==4&&m==2) map[n][m]='1';          //Else if '1' position for 'Lv1'
            else if(n==5&&(m>-1&&m<2)) map[n][m]='O';   //Else if 'O' for 'Lv1' sub-levels
            else if(n==6&&m==22) map[n][m]='L';         //Else if 'L' position for 'Lv3'
            else if(n==6&&m==23) map[n][m]='v';         //Else if 'v' position for 'Lv3'
            else if(n==6&&m==24) map[n][m]='3';         //Else if '3' position for 'Lv3'
            else if(n==7&&(m>21&&m<24)) map[n][m]='O';  //Else if 'O' for 'Lv3' sub-levels
            else if(n==5&&m==33) map[n][m]='L';         //Else if 'L' position for 'Lv4'
            else if(n==5&&m==34) map[n][m]='v';         //Else if 'v' position for 'Lv4'
            else if(n==5&&m==35) map[n][m]='4';         //Else if '4' position for 'Lv4'
            else if(n==6&&(m>32&&m<36)) map[n][m]='O';  //Else if 'O' for 'Lv4' sub-levels
            else if(n==3&&m==44) map[n][m]='L';         //Else if 'L' position for 'Lv5'
            else if(n==3&&m==45) map[n][m]='v';         //Else if 'v' position for 'Lv5'
            else if(n==3&&m==46) map[n][m]='5';         //Else if '5' position for 'Lv5'
            else if(n==4&&(m>43&&m<47)) map[n][m]='O';  //Else if 'O' for 'Lv5' sub-levels
            else if(n==1&&m==55) map[n][m]='L';         //Else if 'L' position for 'Lv6'
            else if(n==1&&m==56) map[n][m]='v';         //Else if 'v' position for 'Lv6'
            else if(n==1&&m==57) map[n][m]='6';         //Else if '6' position for 'Lv6'
            else if(n==2&&(m>54&&m<58)) map[n][m]='O';  //Else if 'O' for 'Lv6' sub-levels
            else if(n==3&&m==66) map[n][m]='L';         //Else if 'L' position for 'Lv7'
            else if(n==3&&m==67) map[n][m]='v';         //Else if 'v' position for 'Lv7'
            else if(n==3&&m==68) map[n][m]='7';         //Else if '7' position for 'Lv7'
            else if(n==4&&(m>65&&m<69)) map[n][m]='O';  //Else if 'O' for 'Lv7' sub-levels
            else if(n==siz1-1) map[n][m]='#';           //Else if to create bottom map boarder of '#'
            else map[n][m]=' ';                         //Else fill map with blanks ' '
        }
    }
}
//Function to fill player's stats based off of selected Attribute
void statFil(int stats[], string statNme[], int size, short att){
    //If attribute is strength
    if(att==1){
        for(int n=0;n<size;n++){            //For-Loop to fill stats array
            if(n==0) {                      //If array is in HP position
                stats[n]=rand()%101+1500;   //Generates random HP number
                statNme[n]="HP\n";          //Sets string array to HP name
            }
            else if(n==1) {                 //Else if array is in ATK position
                stats[n]=rand()%16+40;      //Generates random ATK number
                statNme[n]="ATK\n";         //Sets string array to ATK name
            }
            else if (n==2){                 //Else if array is in INT position
                stats[n]=rand()%11+20;      //Generates random INT number
                statNme[n]="INT\n";         //Sets string array to INT name
            }
        }
    }
    //Else if attribute is Intelligence
    else if(att==2){
        for(int n=0;n<size;n++){            //For-Loop to fill stats array
            if(n==0) {                      //If array is in HP position
                stats[n]=rand()%101+1500;   //Generates random HP number
                statNme[n]="HP\n";          //Sets string array to HP name
            }
            else if(n==1){                  //Else if array is in ATK position
                stats[n]=rand()%11+20;      //Generates random ATK number
                statNme[n]="ATK\n";         //Sets string array to ATK name
            }
            else if(n==2) {                 //Else if array is in INT position
                stats[n]=rand()%16+40;      //Generates random INT number
                statNme[n]="INT\n";         //Sets string array to INT name
            }
        }
    }
    //Else if attribute is endurance
    else if(att==3){
        for(int n=0;n<size;n++){            //For-Loop to fill stats array
            if(n==0) {                      //If array is in HP position
                stats[n]=rand()%151+2000;   //Generates random HP number
                statNme[n]="HP\n";          //Sets string array to HP name
            }
            else if(n==1) {                 //Else if array is in ATK position
                stats[n]=rand()%11+20;      //Generates random ATK number
                statNme[n]="ATK\n";         //Sets string array to ATK name
            }
            else if(n==2) {                 //Else if array is in INT position
                stats[n]=rand()%11+20;      //Generates random INT number
                statNme[n]="INT\n";         //Sets string array to INT name
            }
        }
    }
}