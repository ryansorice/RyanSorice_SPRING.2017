#pragma once
#include <string>
#include "Player.h"
#include "Coach.h"

class Roster
{
private:
	std::string _name;
	Player _players[2];
	Coach _coach;
public:
	Roster();
	~Roster();
	void setPlayer(Player player, int position);
	std::string getRoster();
};

