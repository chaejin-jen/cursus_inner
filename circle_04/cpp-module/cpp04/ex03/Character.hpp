#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include "ICharacter.hpp"

// ************************************************************************** //
//                               CHARACTER Class                                //
// ************************************************************************** //

class Character : public ICharacter{
public:
	Character(void);
	Character(std::string name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

protected:
	std::string _name;
	AMateria *_slot[4];
	//AMateria **_slot;
};

#endif /* __CHARACTER_H__ */
