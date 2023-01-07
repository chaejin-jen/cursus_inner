#pragma once
#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <iostream>
#include <algorithm>
#include <stdexcept>

// ************************************************************************** //
//                               EASYFIND Class                                //
// ************************************************************************** //

template <typename T>
typename T::iterator easyfind(T &container, int toBeFound)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), toBeFound);
	if (iter == container.end())
		throw std::runtime_error("Element not found");
	return (iter);
}

#endif /* __EASYFIND_H__ */
