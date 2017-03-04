#include "Coach.h"
#include <string>

Coach::Coach()
{
	_name = "Programmer 000";
}


Coach::~Coach()
{
}

std::string Coach::getCoachName()
{
	return _name;
}

