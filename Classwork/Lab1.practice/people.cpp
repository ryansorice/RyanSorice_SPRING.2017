/*
 * File:  people
 * Author: Ryan Sorice
 * Created on 15 February 2017 10:54 AM
 */

#include "Character.h"

string Character::Greet()
{
	return "Hi! My name is " + name + " and I am " + to_string(age) + " years old!\n";
}

bool Character::SetAge(int iAge)
{
	if(iAge<1) return false;
	age=iAge;
}

Character::Character(string iName, int iAge)
{
	name=iName;
	age=iAge;	
}

Character::Character(string iName, int iAge, string iRace)
{	
	name=iName;
	age=iAge;
	race=iRace;	
{

Character::~Character
