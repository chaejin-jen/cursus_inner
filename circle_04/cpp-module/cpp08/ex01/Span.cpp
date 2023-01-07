#include "Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span(void)
{
}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span(void)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_data = other._data;
	}
	return *this;
}

void Span::addNumber(const int n)
{
	try
	{
		if (_N == _data.size())
			throw FullSpanException();
		_data.push_back(n);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}
}

unsigned int Span::shortestSpan(void)
{
	if (_data.size() < 2)
		throw Span::NoSpanException();
	std::deque<int> tmp(_data);
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	return *std::min_element(tmp.begin(), tmp.end());
}

unsigned int Span::longestSpan(void)
{
	if (_data.size() < 2)
		throw Span::NoSpanException();
	return (*std::max_element(_data.begin(), _data.end()) - *std::min_element(_data.begin(), _data.end()));
}

const char *Span::FullSpanException::what(void) const throw()
{
	return "Full span\n";
}

const char *Span::NoSpanException::what(void) const throw()
{
	return "No span can be found\n";
}
