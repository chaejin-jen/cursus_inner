#include "Span.hpp"
#include <cstdlib>

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "====================================" << std::endl;

	//0 ~999999999999999999
	{
		std::cout << "1000 Span:" << std::endl;
		Span sp = Span(1000);
		for (int i = 0; i < 1000; i++)
			sp.addNumber(rand());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "10001 Span:" << std::endl;
		Span sp = Span(10001);
		for (int i = 0; i < 10001; i++)
			sp.addNumber(rand());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "====================================" << std::endl;

	{
		std::cout << "100000 Span:" << std::endl;
		Span sp = Span(100000);
		for (int i = 0; i < 100000; i++)
			sp.addNumber(rand());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "====================================" << std::endl;

	{
		std::cout << "1000000 Span:" << std::endl;
		Span sp = Span(1000000);
		for (int i = 0; i < 1000000; i++)
			sp.addNumber(rand());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "====================================" << std::endl;

	{
		std::cout << "FullSpanException :" << std::endl;
		Span sp = Span(10);
		for (int i = 0; i < 15; i++)
			sp.addNumber(rand());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "NoSpanException :" << std::endl;
		Span sp = Span(10);
		for (int i = 0; i < 1; i++)
			sp.addNumber(rand());
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what();
		}
		try
		{
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what();
		}
	}

	return 0;
}