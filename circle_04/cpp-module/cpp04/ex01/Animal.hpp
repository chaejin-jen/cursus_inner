#pragma once
#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>
#include <string>

// ************************************************************************** //
//                               ANIMAL Class                                //
// ************************************************************************** //

class Animal {
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal(void);
		std::string const & getType(void) const;
		virtual void makeSound(void) const;

	protected:
		std::string	type;
};

#endif /* __ANIMAL_H__ */
