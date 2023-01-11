#pragma once
#ifndef __SPAN_H__
#define __SPAN_H__

#include <deque>
#include <iostream>
#include <exception>

// ************************************************************************** //
//                               SPAN Class                                //
// ************************************************************************** //

class Span
{
public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span(void);

	void addNumber(const int n);

	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);

	class FullSpanException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

private:
	unsigned int _N; //  a maximum of N integers
	std::deque<int> _data;

	Span(void);
};

#endif /* __SPAN_H__ */
