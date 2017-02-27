#pragma once
#include <string>

class Cleric
{
private:
	std::string _name;
public:
	Cleric();
	~Cleric();
	void statAssign(int stats[3]);
};

