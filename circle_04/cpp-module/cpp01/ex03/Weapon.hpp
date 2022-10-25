#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>

// ************************************************************************** //
//                               WEAPON Class                                //
// ************************************************************************** //

class Weapon {

public:
	// Weapon( void );
	Weapon( std::string type );
	~Weapon( void );

	std::string getType(void) const;
	void setType(std::string str);

private:
	std::string _type;

};

Weapon* newWeapon( std::string name );
Weapon* WeaponHorde( int N, std::string name );
void randomChump( std::string name );

#endif /* __WEAPON_H__ */
