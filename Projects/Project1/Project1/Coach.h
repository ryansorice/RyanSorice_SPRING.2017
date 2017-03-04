#pragma once
#include <string>
class Coach
{
private:
	std::string _name;
public:
	Coach();
	~Coach();
	std::string getCoachName();
};

