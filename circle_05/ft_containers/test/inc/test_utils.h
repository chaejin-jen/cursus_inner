//#pragma once
#ifndef __TEST_UTILS_H__
#define __TEST_UTILS_H__

#include <iostream>

template <typename iterator>
void putElements(const iterator first, const iterator last)
{
	size_t i(0);
	while (first + i != last)
	{
		::std::cout<< *(first + i) << ' '; // test output
		++i;
	}
	::std::cout << ::std::endl;
}

#endif /* __TEST_UTILS_H__ */

