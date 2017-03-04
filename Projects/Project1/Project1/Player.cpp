#include "Player.h"
#include <string>

Player::Player()
{
	_name = "Player";
}

Player::Player(std::string name)
{
	_name = name;
}


Player::~Player()
{
}

std::string Player::getName()
{
	return _name;
}



