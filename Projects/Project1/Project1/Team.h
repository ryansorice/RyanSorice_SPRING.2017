#pragma once
#include <string>
#include "Coach.h"

class Team
{
private:
	std::string _name;
	std::string _motto;
	Coach _coach;
public:
	Team(std::string name, std::string motto, Coach theCoach);
	~Team();
	std::string getTeamInfo();
};

