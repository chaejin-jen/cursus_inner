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

	int add( void );
	void search( void ) const;
	// int (Contact::*setFncPtr[5])(std::string);
	// int (Contact::*setFncPtr[5])(std::string) {Contact::setFirstname, Contact::setLastname, Contact::setNickname, Contact::setPhoneNb, Contact::setSecret};

private:
	int _nb;
	int _oldestIdx;
	Contact _contacts[8];

	// void _create(void);
	int _getidx(void) const;
	void _display(void) const;
	void _putf(std::string str) const;
	//bool _search( void );

};

#endif /* __PHONEBOOK_H__ */
