#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *pzombie(new Zombie(name));
	return pzombie;
}