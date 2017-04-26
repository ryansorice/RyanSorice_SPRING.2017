#pragma once
#include <string>
#include <vector>
#include "Coach.h"
#include "Player.h"

class Team
{
private:
	std::string _name;
	std::string _motto;
	Coach _coach;
	std::vector<Player> _players;
public:
	Team(std::string name, std::string motto, Coach theCoach);
	~Team();
	std::string getTeamInfo();
	void AddPlayer(Player newPlayer) { _players.push_back(newPlayer); }
};

