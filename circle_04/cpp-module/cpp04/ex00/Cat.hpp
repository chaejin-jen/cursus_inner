#pragma once
#ifndef __CAT_H__
#define __CAT_H__

#include <iostream>
#include <string>
#include "Animal.hpp"

// ************************************************************************** //
//                               CAT Class                                //
// ************************************************************************** //

class Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat(void);
		std::string const & getType(void) const;
		void makeSound(void) const;
};

#endif /* __CAT_H__ */
