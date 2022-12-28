#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>
#include <string>

namespace harl{
	const int maxLv = 4;

	const char * const debugMsg = "[DEBUG]\n\
I love having extra bacon \
for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n";

	const char * const infoMsg = "[INFO]\n\
I cannot believe adding extra bacon costs more money.\n\
You didn’t put enough bacon in my burger!\n\
If you did, I wouldn’t be asking for more!\n";

	const char * const warnMsg = "[WARNING]\n\
I think I deserve to have some extra bacon for free.\n\
I’ve been coming for years whereas you started working here since last month.\n";

	const char * const errMsg = "[ERROR]\n\
This is unacceptable! I want to speak to the manager now.\n";
}

// ************************************************************************** //
//                               HARL Class                                //
// ************************************************************************** //

class Harl {

public:
	Harl( void );
	~Harl( void );
	void complain( std::string level );

private:
	static std::string _levels[4];
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	int printmsg(int i);

};

typedef	void (Harl::*functionPtr[harl::maxLv])(void);

#endif /* __HARL_H__ */
