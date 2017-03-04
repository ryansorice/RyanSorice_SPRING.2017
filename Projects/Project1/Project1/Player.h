#pragma once
#include <string>

class Player
{
private:
	std::string _name;
public:
	int totalScore = 0;
	Player();
	Player(std::string name);
	~Player();
	std::string getName();
};

