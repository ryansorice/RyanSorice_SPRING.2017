#pragma once
#include <string>

class Ninja
{
private:
	std::string _name;
public:
	Ninja();
	~Ninja();
	bool alive();
};

