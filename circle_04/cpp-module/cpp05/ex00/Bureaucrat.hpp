#pragma once
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <iostream>
#include <string>
#include <exception>

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

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const &other);
		virtual ~GradeTooHighException(void) throw();

		GradeTooHighException &operator=(const GradeTooHighException &other);

		virtual const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const &other);
		virtual ~GradeTooLowException(void) throw();

		GradeTooLowException &operator=(const GradeTooLowException &other);

		virtual const char* what(void) const throw();
	};
	
private:
	std::string _name;
	int			_grade;
};

std::ostream & operator << (std::ostream &os, const Bureaucrat &data);

#endif /* __BUREAUCRAT_H__ */
