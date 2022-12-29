#pragma once
#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"

namespace fragtrap{
	enum e_max { 
		MAX_HP = 100,
		MAX_EP = 100,
		MAX_AD = 30 
	};
}

// ************************************************************************** //
//                               FRAGTRAP Class                                //
// ************************************************************************** //

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap(void);
		void highFivesGuys(void);
		
	private:
		void _setMaxValue(void);
		void _setStatus(const FragTrap &other);
};

#endif /* __FRAGTRAP_H__ */
