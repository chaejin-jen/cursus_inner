#pragma once
#ifndef __ICE_H__
#define __ICE_H__

#include <string>
#include "AMateria.hpp"

// ************************************************************************** //
//                               ICE Class                                //
// ************************************************************************** //

class Ice : public AMateria{
public:
	Ice(void);
	Ice(std::string const & type);
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);
	~Ice(void);

	Ice* clone() const;
	void use(ICharacter& target);
};

#endif /* __ICE_H__ */
