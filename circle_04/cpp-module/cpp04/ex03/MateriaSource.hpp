#pragma once
#ifndef __MATERIASOURCE_H__
#define __MATERIASOURCE_H__

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

// ************************************************************************** //
//                               MATERIASOURCE Class                                //
// ************************************************************************** //

class MateriaSource : public IMateriaSource{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif /* __MATERIASOURCE_H__ */
