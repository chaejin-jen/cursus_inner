#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>

#define LEVEL_NUM 4

#define DEBUG_MSG "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"

#define INFO_MSG "I cannot believe adding extra bacon costs more money.\
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"

#define WARNING_MSG "I think I deserve to have some extra bacon for free.\
I’ve been coming for years whereas you started working here since last month."

#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

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

typedef	void (Harl::*functionPtr[LEVEL_NUM])(void);

#endif /* __HARL_H__ */
