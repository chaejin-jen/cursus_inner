#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"

namespace scavtrap{
	enum e_max { 
		MAX_HP = 100,
		MAX_EP = 50,
		MAX_AD = 20 
	};
}

// ************************************************************************** //
//                               SCAVTRAP Class                                //
// ************************************************************************** //

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap(void);
		void guardGate(void);
		
	private:
		void _setMaxValue(void);
		void _setStatus(const ScavTrap &other);
};

#endif /* __SCAVTRAP_H__ */
