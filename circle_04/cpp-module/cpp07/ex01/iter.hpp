#pragma once
#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, size_t len, void (*f)(T const &ref))
{
	for (size_t i = 0; i < len ; i++)
		f(array[i]);
}

#endif