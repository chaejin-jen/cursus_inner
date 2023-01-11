#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <iostream>
#include "Weapon.hpp"

// ************************************************************************** //
//                               HUMANB Class                                //
// ************************************************************************** //

class HumanB {

public:
	HumanB( std::string name);
	~HumanB( void );

	void attack(void) const;
	void setWeapon(Weapon& Weapon);

private:
	std::string _name;
	Weapon* _weapon;
};

#endif /* __HUMANB_H__ */
