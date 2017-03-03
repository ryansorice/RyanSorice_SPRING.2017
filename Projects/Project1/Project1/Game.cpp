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

using namespace std;

//Execution begins here
int main() {

	//Variables
	string name;
	Coach coach = Coach();
	Player player1 = Player();
	Player player2 = Player();
	Roster roster = Roster();
	cout << "Enter first player's name.\n";
	cin >> name;
	player1 = Player(name);
	cout << "Enter first player's name.\n";
	cin >> name;
	player2 = Player(name);

	//Exits program
	return 0;
}