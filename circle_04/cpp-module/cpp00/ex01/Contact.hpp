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

	int setIdx(int idx);
	int setFirstname(std::string str);
	int setLastname(std::string str);
	int setNickname(std::string str);
	int setPhoneNb(std::string str);
	int setSecret(std::string str);
	int (*setFncPtr[5])(std::string);
	//int (Contact::*setFncPtr[5])(std::string) {setFirstname, setLastname, setNickname, setPhoneNb, setSecret};

private:
	int				_idx;
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickname;
	std::string		_phoneNb;
	std::string		_secret;
};

#endif /* __CONTACT_H__ */
