#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>

// ************************************************************************** //
//                               CONTACT Class                                //
// ************************************************************************** //

class Contact {

public:
	Contact( void );
	~Contact( void );

	int getIdx(void) const;
	std::string getFirstname(void) const;
	std::string getLastname(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNb(void) const;
	std::string getSecret(void) const;

	int setAll(void);
	int setIdx(int idx);
	int setFirstname(const std::string str);
	int setLastname(const std::string str);
	int setNickname(const std::string str);
	int setPhoneNb(const std::string str);
	int setSecret(const std::string str);

private:
	int _idx;
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNb;
	std::string _secret;
	int (Contact::*_setFncPtr[5])(const std::string);
	
	std::string _getline(void) const;
};

#endif /* __CONTACT_H__ */
