#pragma once
#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <iostream>
#include <string>

namespace claptrap{
	enum e_max {
		MAX_HP = 10,
		MAX_EP = 10,
		MAX_AD = 0 
	};
}

// ************************************************************************** //
//                               CLAPTRAP Class                                //
// ************************************************************************** //

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void) const;
		unsigned int getHitPoints(void) const;
		unsigned int getAttackDamage(void) const;
		void putStatus(void) const;
		
	private:
		std::string _name;
		unsigned int _hp; // hit_points
		unsigned int _ep; // energy_points
		unsigned int _ad; // attack_damage
};

#endif /* __CLAPTRAP_H__ */
