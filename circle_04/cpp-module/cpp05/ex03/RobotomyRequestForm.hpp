#pragma once
#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

// ************************************************************************** //
//                               ROBOTOMYREQUESTFORM Class                                //
// ************************************************************************** //

class RobotomyRequestForm : public AForm{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string name);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm(void);

	void beSigned(Bureaucrat &br);
	void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &data);

#endif /* __ROBOTOMYREQUESTFORM_H__ */
