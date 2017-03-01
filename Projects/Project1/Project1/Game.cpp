/*
Author: Ryan Sorice
Created on: 27 February 2017
Purpose: Create classes for the beginning of a Dungeon-Style card game
*/

//System Libraries
#include <iostream>
#include <string>

//User Libraries
#include "Ninja.h"
#include "Coin.h"
#include "Warrior.h"

using namespace std;	//Namespace in system libraries

//Global Variables

//Function Prototypes

//Execution begins here
int main() {

	//Variables
	Coin status = Coin();
	Ninja hero = Ninja();

	//Initial output
	cout << "Welcome to the coin flip!\n";

	//Run the game
	while (hero.alive == true) {
		status.flip;
		cout << "The flip is done!\n";
		if (status.flip == false) {
			hero.alive = false;
			cout << "Dead!\n";
		}
		else "You survived another round!\n";
	}

	//Exits program
	return 0;
}