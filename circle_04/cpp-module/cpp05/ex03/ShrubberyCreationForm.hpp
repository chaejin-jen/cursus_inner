#pragma once
#ifndef __SHRUBBERYCREATIONFORM_H__
#define __SHRUBBERYCREATIONFORM_H__

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

// ************************************************************************** //
//                               SHRUBBERYCREATIONFORM Class                                //
// ************************************************************************** //

class ShrubberyCreationForm : public AForm{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string name);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm(void);
	
	void beSigned(Bureaucrat &br);
	void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &data);

#endif /* __SHRUBBERYCREATIONFORM_H__ */
