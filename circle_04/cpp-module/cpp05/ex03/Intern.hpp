#pragma once
#ifndef __Intern_H__
#define __Intern_H__

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

// ************************************************************************** //
//                               Intern Class                                //
// ************************************************************************** //

// AForm* newShrubberyCreationForm(std::string name);
// AForm* newRobotomyRequestForm(std::string name);
// AForm* newPresidentialPardonForm(std::string name);

class Intern{
public:
	Intern(void);
	Intern(std::string name);
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern(void);
	
	AForm* makeForm(std::string form_name, std::string b_name) const;
	// static void setFncPtr(void);
	class NonExistentForm : public std::exception {
	public:
		const char* what(void) const throw();
	};

private:
	// static AForm* (Intern::*_newFormFncPtr[3])(std::string name);
	static AForm* _makeShrubberyCreationForm( std::string name );
	static AForm* _makeRobotomyRequestForm( std::string name );
	static AForm* _makePresidentialPardonForm( std::string name );
};

#endif /* __Intern_H__ */
