#pragma once
#ifndef __IMATERIASOURCE_H__
#define __IMATERIASOURCE_H__

#include <iostream>
#include <string>
#include "AMateria.hpp"

// ************************************************************************** //
//                               IMATERIASOURCE Class                                //
// ************************************************************************** //

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif /* __IMATERIASOURCE_H__ */
