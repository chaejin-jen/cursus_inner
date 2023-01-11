#pragma once
#ifndef __DOG_H__
#define __DOG_H__

#include <iostream>
#include <string>
#include "Animal.hpp"

// ************************************************************************** //
//                               Dog Class                                //
// ************************************************************************** //

class Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog(void);
		std::string const & getType(void) const;
		void makeSound(void) const;
};

#endif /* __DOG_H__ */
