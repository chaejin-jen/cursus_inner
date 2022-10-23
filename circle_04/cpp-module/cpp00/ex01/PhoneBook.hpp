// #pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

// #include <iomanip>
#include <iostream>

// ************************************************************************** //
//                               PHONEBOOK Class                                //
// ************************************************************************** //

class PHONEBOOK {

public:
	static int	getNbPHONEBOOKs( void );
	static int	getTotalAmount( void );
	static int	getNbContacts( void );
	static int	getNbWithdrawals( void );
	static void	displayPHONEBOOKsInfos( void );

	PHONEBOOK( int initial_Contact );
	~PHONEBOOK( void );

	void	addContact( int Contact );
	bool	searchContact( int withdrawal );
	int		checkValid( void ) const;
	void	displayContact( void ) const;
	void	exitProgram( void );

private:
	static int	_nbPHONEBOOKs;

	// static void	_displayTimestamp( void );

	int				_PHONEBOOKIndex;
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickname;
	std::string		_phoneNb;
	std::string		_secret;

};

#endif /* __PHONEBOOK_H__ */