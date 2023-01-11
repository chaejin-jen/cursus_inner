#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}

	{
		try {
			Intern a;
			AForm* b = a.makeForm("robotomy request", "dfdf");
			std::cout << b->getName() << std::endl;
			delete b;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		try{
			Bureaucrat official("official", 1);
			Intern intern;

			AForm *form_ptr1 = intern.makeForm("shrubbery creation", "garden");
			AForm *form_ptr2 = intern.makeForm("robotomy request", "Human");
			AForm *form_ptr3 = intern.makeForm("presidential pardon", "Criminal");
			// AForm *form_ptr4 = intern.makeForm("Does Not Exist Form", "Target");

			std::cout << std::endl;

			official.signForm(*form_ptr1);
			official.signForm(*form_ptr2);
			official.signForm(*form_ptr3);

			std::cout << std::endl;

			official.executeForm(*form_ptr1);
			official.executeForm(*form_ptr2);
			official.executeForm(*form_ptr3);

			delete form_ptr1;
			delete form_ptr2;
			delete form_ptr3;
			// delete form_ptr4;

			std::cout << std::endl;

			system("leaks intern");
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	return 0;
}
