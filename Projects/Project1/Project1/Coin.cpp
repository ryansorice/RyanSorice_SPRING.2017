#include "Coin.h"
#include <ctime>
#include <cstdlib>

Coin::Coin()
{
	_name = "Coin";
}


Coin::~Coin()
{
}

bool Coin::flip()
{
	srand(static_cast<unsigned int>(time(0)));
	int _flip = rand() % 2 + 1;
	if(_flip==1) return false;
	else return true;
}
