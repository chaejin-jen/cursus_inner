#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

// ************************************************************************** //
//                               ZOMBIE Class                                //
// ************************************************************************** //

class Zombie {

public:
	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );

	void announce(void) const;
	void setname(std::string name);

private:
	std::string _name;

};

Zombie* zombieHorde( int N, std::string name );

#endif /* __ZOMBIE_H__ */
