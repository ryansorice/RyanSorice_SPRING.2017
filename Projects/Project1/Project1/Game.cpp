/*
Author: Ryan Sorice
Created on: 27 February 2017
Purpose: Fill a team roster with players and coach.
*/

//System Libraries
#include <iostream>
#include <string>
//User Libraries
#include "Roster.h"
#include "Coach.h"
#include "Player.h"
#include "Team.h"
#include "Coin.h"

using namespace std;

//Execution begins here
int main() {

	//Variables
	string name, description;
	auto coach = Coach();
	auto roster = Roster();
	Coin coin;
	
	cout << "What is your team's name?\n";
	getline(cin, name);
	cout << "What is your team's motto?\n";
	getline(cin, description);
	auto team = Team(name, description, coach);

	cout << team.getTeamInfo() << endl;

	cout << "Enter first player's name.\n";
	cin >> name;
	auto player1 = Player(name);

	cout << "Enter first player's name.\n";
	cin >> name;
	auto player2 = Player(name);

	roster.setPlayer(player1, 0);
	roster.setPlayer(player2, 1);

	cout << roster.getRoster()<<endl;

	cout << "The players will now compete in coin tosses til they reach 5 points!\n";
	while (player1.totalScore < 5 && player2.totalScore < 5) 
	{
		if (coin.winLose() == true)
		{
			cout << "HEADS!\n";
			player1.totalScore += 1;
		}
		else
		{
			cout << "TAILS!\n";
			player2.totalScore += 1;
		}
		
		cout << player1.getName() << " " << player1.totalScore << " " << player2.getName() << " " << player2.totalScore << endl;
		getchar();
	}
	
	if (player1.totalScore > player2.totalScore) 
	{
		cout << player1.getName() << " wins!\n";
	}
	else cout << player2.getName() << " wins!\n";

	getchar();

	//Exits program
	return 0;
}