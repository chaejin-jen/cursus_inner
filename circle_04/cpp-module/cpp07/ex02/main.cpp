// #include <iostream>
// #include <Array.hpp>
#include "Array.hpp"

// #define MAX_VAL 750
#define MAX_VAL 10
int main(int, char **)
{
	{
		Array<int> test;
		Array<int> numbers(MAX_VAL);
		int *mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		test = numbers;
		std::cout << "test:\n"
				  << test << '\n';
		// std::cout << "numbers:\n" << numbers << '\n';
		//  std::cout << "mirror:\n";
		//  for (int i = 0; i < MAX_VAL; i++)
		//{
		//	std::cout << mirror[i] << ' ';
		//  }
		//  std::cout << std::endl;
		//   SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);

			// std::cout << "tmp:\n"
			//		  << tmp << '\n';
		}
		// std::cout << std::endl;

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		// std::cout << "numbers:\n"
		//		  << numbers << '\n';
		// std::cout << "mirror:\n";
		// for (int i = 0; i < MAX_VAL; i++)
		//{
		//	std::cout << mirror[i] << ' ';
		// }
		// std::cout << std::endl;
		delete[] mirror;
	}
	//system("leaks array");
	return 0;
}