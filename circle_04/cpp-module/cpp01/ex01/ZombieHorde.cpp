#include "Zombie.hpp"
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >\
	(std::ostringstream().seekp(0) << x).str()

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombieH;

	if (N <= 0)
		return NULL;
	zombieH = new Zombie[N];
	for (int i = 0; i < N ; i++)
	{
		std::string newname(SSTR(name + '_' << i));
		zombieH[i].setname(newname);
		zombieH[i].announce();
	}
	return zombieH;
}
