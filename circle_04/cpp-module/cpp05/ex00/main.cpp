#include "Bureaucrat.hpp"

int main()
{
	{
		//Bureaucrat br("jen");
		Bureaucrat br("hey", 130);

		try{
			std::cout << br << std::endl;
			for(int i = 0; i < 150; i++)
			{
				br.decGrade();
				std::cout << br << std::endl;
			}
		}
		catch (const std::exception & e){
			std::cout << e.what() << std::endl;
		}
	}

	{
		//Bureaucrat br("jen");
		Bureaucrat br("ho", 30);

		try{
			std::cout << br << std::endl;
			for(int i = 0; i < 150; i++)
			{
				br.incGrade();
				std::cout << br << std::endl;
			}
		}
		catch (const std::exception & e){
			std::cout << e.what() << std::endl;
		}
	}
	
}
