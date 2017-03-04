#include "Roster.h"
#include "Coach.h"
#include "Player.h"
#include <string>
using namespace std;


Roster::Roster()
{
	_name = "Roster/Line-up:";
}


Roster::~Roster()
{
}

void Roster::setPlayer(Player player, int position)
{
	if (position < 2) 
	{
		_players[position] = player;
	}
}

string Roster::getRoster()
{
	string info = _name + "\n";
	info += "Coach: " + _coach.getCoachName() + "\n"; 
	info += "Players: ";
	for (int n = 0; n < 2; n++) 
	{
		info += _players[n].getName() + "\n"; 
	}
	return info;
}

