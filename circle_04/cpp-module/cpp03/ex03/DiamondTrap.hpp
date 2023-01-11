#pragma once
#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

namespace diamondtrap{
	enum e_max { 
		MAX_HP = fragtrap::MAX_HP,
		MAX_EP = scavtrap::MAX_EP,
		MAX_AD = fragtrap::MAX_AD 
	};
}

// ************************************************************************** //
//                               DIAMONDTRAP Class                                //
// ************************************************************************** //

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap(void);
		void whoAmI();
		
	private:
		void _setMaxValue(void);
		void _setStatus(const DiamondTrap &other);
};

#endif /* __DIAMONDTRAP_H__ */
