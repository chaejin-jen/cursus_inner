#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		try {
			// Form form = Form();
			// Form form = Form("50", 50, 50);
			Form form = Form("77", 77, 77);
			Bureaucrat br = Bureaucrat("Jen", 60);
			//for (int i = 0 ; i < 13 ; i++)
			//	br.incGrade();
			br.signForm(form);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	
}
