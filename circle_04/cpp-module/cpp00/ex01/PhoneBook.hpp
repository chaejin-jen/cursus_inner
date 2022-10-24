// #pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <iostream>
#include "Contact.hpp"

// ************************************************************************** //
//                               PHONEBOOK Class                                //
// ************************************************************************** //

class PhoneBook {

public:
	PhoneBook( void );
	~PhoneBook( void );

	int	add( void );
	void	search( void ) const;

private:
	int	_nb;
	int	_oldestIdx;
	Contact _contacts[8];

	std::string	_getline(void) const;
	void	_display(void) const;
	void	_putf(std::string str) const;
	//bool	_search( void );

};

#endif /* __PHONEBOOK_H__ */
