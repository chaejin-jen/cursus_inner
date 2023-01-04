#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		try {
			Bureaucrat president("president", 1);
			Bureaucrat military("military", 6);
			Bureaucrat policeOfficer("policeOfficer", 46);
			Bureaucrat fireFighter("fireFighter", 138);

			AForm *form1 = new ShrubberyCreationForm("Home");
			AForm *form2 = new RobotomyRequestForm("TTTT");
			AForm *form3 = new PresidentialPardonForm("Criminal");

			std::cout << "============ self introduction ============" << std::endl;
			std::cout
				<< president << std::endl
				<< military << std::endl
				<< policeOfficer << std::endl
				<< fireFighter << std::endl << std::endl;
			
			std::cout << "============ form status ============" << std::endl;
			std::cout
				<< *form1 << std::endl << std::endl
				<< *form2 << std::endl << std::endl
				<< *form3 << std::endl << std::endl;

			std::cout << "============ sign form ============" << std::endl;
			military.signForm(*form1);
			policeOfficer.signForm(*form2);
			fireFighter.signForm(*form3);

			std::cout << std::endl;

			std::cout << "============ execute form ============" << std::endl;
			military.executeForm(*form1);
			policeOfficer.executeForm(*form2);
			fireFighter.executeForm(*form3);

			std::cout << std::endl;

			president.executeForm(*form1);
			president.executeForm(*form2);
			president.executeForm(*form3);

			delete form1;
			delete form2;
			delete form3;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	
}
