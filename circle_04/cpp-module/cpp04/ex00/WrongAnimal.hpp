#pragma once
#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

#include <iostream>
#include <string>

// ************************************************************************** //
//                               WRONGANIMAL Class                                //
// ************************************************************************** //

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal(void);
		std::string const & getType(void) const;
		void makeSound(void) const;

	protected:
		std::string	_type;
};

#endif /* __WRONGANIMAL_H__ */
