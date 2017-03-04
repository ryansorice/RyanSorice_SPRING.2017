#pragma once
#include <string>

class Player
{
private:
	std::string _name;
public:
	Player();
	Player(std::string name);
	~Player();
	std::string getName();
};

