#include "Coin.h"
#include <ctime>
#include <cstdlib>

Coin::Coin()
{
}


Coin::~Coin()
{
}

bool Coin::winLose()
{
	srand(static_cast<unsigned int>(time(0)));
	int headsTails = rand() % 2;
	if (headsTails > 0)
	{
		return true;
	}
	else return false;
}
