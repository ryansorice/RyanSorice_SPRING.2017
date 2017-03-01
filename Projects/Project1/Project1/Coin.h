#pragma once
#include <string>
class Coin
{
private:
	std::string _name;
public:
	Coin();
	~Coin();
	bool flip();
};

