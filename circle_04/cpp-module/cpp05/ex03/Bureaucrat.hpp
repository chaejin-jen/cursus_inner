#pragma once
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

class AForm;

namespace bureaucrat{
	enum e_grade{
		MIN = 1,
		MAX = 150
	};
}

// ************************************************************************** //
//                               BUREAUCRAT Class                                //
// ************************************************************************** //

class Bureaucrat {
public:
	Bureaucrat(void);
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat(void);
	
	std::string getName(void) const;
	int getGrade(void) const;
	void setGrade(int grade);
	void incGrade(void);
	void decGrade(void);

	void signForm(AForm &form);
	void executeForm(AForm const & form);

	class GradeTooHighException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	
private:
	const std::string _name;
	int			_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &data);

#endif /* __BUREAUCRAT_H__ */
