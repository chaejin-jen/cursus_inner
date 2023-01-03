#pragma once
#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

// ************************************************************************** //
//                               WRONGCAT Class                                //
// ************************************************************************** //

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		~WrongCat(void);
		std::string const & getType(void) const;
		void makeSound(void) const;
};

#endif /* __WRONGCAT_H__ */
