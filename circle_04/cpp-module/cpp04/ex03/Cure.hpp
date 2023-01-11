#pragma once
#ifndef __CURE_H__
#define __CURE_H__

#include "AMateria.hpp"

// ************************************************************************** //
//                               CURE Class                                //
// ************************************************************************** //

class Cure : public AMateria{
public:
	Cure(void);
	Cure(std::string const & type);
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure(void);

	Cure* clone() const;
	void use(ICharacter& target);
};

#endif /* __CURE_H__ */
