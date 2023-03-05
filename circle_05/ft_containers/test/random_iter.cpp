#include <iostream>
#include <cstdlib>
#include <vector>
//#include "vector.hpp"
//#include "ft_iterators.hpp"
//#include "random_access_iterator.hpp"

namespace ft = std;

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

int main(void){
	srand(time(NULL));
	{

		//ft::random_access_iterator<int> it_1;
		//ft::random_access_iterator<int> it_2;
		//std::cout << (it_1 == it_1) << std::endl;
		//std::cout << (it_1 == it_2) << std::endl;

		//std::cout << *it_1 << std::endl;
		//std::cout << *(it_1++) << std::endl;
		//std::cout << *it_1 << std::endl;
		//std::cout << *it_1++ << std::endl;
	}

	{
		size_t n = 20;
		std::vector<int> data(n);
		for (size_t i = 0; i < n ; i++)
			data[i] = i;
		putElements(data.begin(), data.end());

		std::vector<int>::iterator first(&data.front());
		std::vector<int>::iterator last(&data.front() + data.size());

		//ft::random_access_iterator<int> first(&data.front());
		//ft::random_access_iterator<int> last(&data.front() + data.size());
		putElements(first, last);

		std::cout << *first++ << std::endl;
		std::cout << *last-- << std::endl;

	}

	::std::cout << "\033[0;90m" << std::endl;
	//system("leaks a.out");
	return 0;
}


