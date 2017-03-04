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

using namespace std;

//Execution begins here
int main() {

	//Variables
	string name, description;
	Coach coach = Coach();
	Roster roster = Roster();
	
	cout << "What is your team's name?\n";
	getline(cin, name);
	cout << "What is your team's motto?\n";
	getline(cin, description);
	Team team = Team(name, description, coach);

	cout << team.getTeamInfo() << endl;

	cout << "Enter first player's name.\n";
	cin >> name;
	Player player1 = Player(name);

	cout << "Enter first player's name.\n";
	cin >> name;
	Player player2 = Player(name);

	roster.setPlayer(player1, 0);
	roster.setPlayer(player2, 1);

	cout << roster.getRoster()<<endl;

	//Exits program
	return 0;
}