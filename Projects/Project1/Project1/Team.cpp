#include "Team.h"
#include <string>

Team::Team(std::string name, std::string motto, Coach theCoach) : _name(name), _motto(motto), _coach(theCoach)
{
}

Team::~Team()
{
}

std::string Team::getTeamInfo()
{
	std::string info = "Team Name: " + _name + "\n";
	info += "Coach: " + _coach.getCoachName() + "\n";
	info += "Motto: " + _motto + "\n";
	return info;
}

