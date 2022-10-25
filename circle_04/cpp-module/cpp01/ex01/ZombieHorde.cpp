#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieH;

	zombieH = new Zombie[N];
	for (int i = 0; i < N ; i++)
	{
		zombieH[i].setname(name);
		zombieH[i].announce();
	}
	return zombieH;
}
