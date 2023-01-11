 #pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>
#include <exception>

template <typename T>
class Array
{
public:
	Array(void); // empty array
	Array(unsigned int n);
	Array(const Array &other);
	~Array(void);
	Array &operator=(const Array &other);
	T &operator[](const unsigned int idx) const;

	unsigned int size(void) const;

	class OutOfRangeException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

private:
	T *_arr;
	const unsigned int _len;
};

template <typename T>
Array<T>::Array(void) : _arr(NULL), _len(0)
{
	std::cout
		<< "Default constructor called : Creates an empty array"
		<< std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(NULL), _len(n)
{
	std::cout
		<< "Constructor called : array[" << n << "]"
		<< std::endl;
	_arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array &other) : _arr(NULL), _len(other._len)
{
	*this = other;
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout
		<< "Default destructor called"
		<< std::endl;
	if (_len)
		delete[] _arr;
	_arr = NULL;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		if (_len != other._len)
		{
			delete[] _arr;
			const_cast<unsigned int &>(_len) = other._len;
		}
		const_cast<unsigned int &>(_len) = other._len;
		_arr = new T[_len];
		for (unsigned int i = 0; i < other._len; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](const unsigned int idx) const
{
	if (idx >= _len)
		throw Array<T>::OutOfRangeException();
	return _arr[idx];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return _len;
}

template <typename T>
const char *
Array<T>::OutOfRangeException::what() const throw()
{
	return ("Index out of range");
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &arr)
{
	for(unsigned int i = 0; i < arr.size(); ++i)
		out << arr[i] << " ";
	return (out);
}

#endif