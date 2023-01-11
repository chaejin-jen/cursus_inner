#include <vector>
#include <deque>
#include <list>
#include <exception>
#include "easyfind.hpp"

int main()
{
	{
		std::vector<int> vec;

		for (int i = 0; i < 10; i++)
			vec.push_back(i);
		try
		{
			std::cout << *easyfind(vec, 3) << std::endl;
			std::cout << *easyfind(vec, 100) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::deque<int> dq;

		for (int i = 0; i < 10; i++)
				dq.push_back(i);
		try{
			std::cout << *easyfind(dq, 3) << std::endl;
			std::cout << *easyfind(dq, 100) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::list<int> ls;

		for (int i = 0; i < 10; i++)
				ls.push_back(i);
		try
		{
				std::cout << *easyfind(ls, 3) << std::endl;
				std::cout << *easyfind(ls, 100) << std::endl;
		}
		catch (const std::exception &e)
		{
				std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}