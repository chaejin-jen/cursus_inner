#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>
#include "NullptrFT.hpp"

// ************************************************************************** //
//                               ZOMBIE Class                                //
// ************************************************************************** //

class Zombie {

public:
	Zombie( void );
	Zombie( NullptrFT *ptr );
	Zombie( std::string name );
	~Zombie( void );

	void announce(void) const;

private:
	std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif /* __ZOMBIE_H__ */
