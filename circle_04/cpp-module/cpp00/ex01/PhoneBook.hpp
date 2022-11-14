#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <iostream>
#include <cstdio>
#include "Contact.hpp"

// ************************************************************************** //
//                               PHONEBOOK Class                                //
// ************************************************************************** //

class PhoneBook {

public:
	PhoneBook( void );
	~PhoneBook( void );

	int add( void );
	void search( void ) const;

private:
	int _nb;
	int _oldestIdx;
	Contact _contacts[8];

	int _getidx(void) const;
	void _display(void) const;
	void _putf(std::string str) const;
};

#endif /* __PHONEBOOK_H__ */
