#pragma once
#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ************************************************************************** //
//                               PRESIDENTIALPARDONFORM Class                                //
// ************************************************************************** //

class PresidentialPardonForm : public AForm{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string name);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm(void);

	void beSigned(Bureaucrat &br);
	void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &data);

#endif /* __PRESIDENTIALPARDONFORM_H__ */
