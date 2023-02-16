#include "test.h"
#include "map.hpp"
//#include <cstdlib>

//#include <map>
//namespace ft = std;

ft::map<int, int> create_intmap(int size, int seed);
void test_iterators(void);


int main(){
	test_iterators();
	return 0;
}


ft::map<int, int> create_intmap(int size, int seed)
{
	ft::map<int, int> map;

	srand(seed);

	for (int i = 0; i < size; i++)
	{
		int random = rand() % 1000;;
		const ft::pair<const int, int>	pair(random, random);
		map.insert(pair);
	}
	return map;
}

void test_iterators(void)
{
	::std::cout << "\n\n======= map iterator =======" << ::std::endl;


	ft::map<int, int> map = create_intmap(8, 200);

	::std::cout << "\033[0;92mbidirectional\033[0m" << ::std::endl;
	ft::map<int, int>::iterator it;

	for (it = map.begin(); it != map.end(); ++it)
	{
		std::cout << it->first << ", " << it->second << std::endl;
	}

		::std::cout << "\033[0;92mconst bidirectional\033[0m" << ::std::endl;
	ft::map<int, int>::const_iterator const_it;

	for (it = map.begin(); it != map.end(); ++it)
	{
		std::cout << it->first << ", " << it->second << std::endl;
	}

	::std::cout << "\033[0;92mreverse\033[0m" << ::std::endl;
	ft::map<int, int>::reverse_iterator	reverse_it;

	for (reverse_it = map.rbegin(); reverse_it != map.rend(); ++reverse_it)
	{
		std::cout << reverse_it->first << ", " << reverse_it->second << std::endl;
	}

		::std::cout << "\033[0;92mconst reverse\033[0m" << ::std::endl;
	ft::map<int, int>::const_reverse_iterator	const_reverse_it;

	for (reverse_it = map.rbegin(); reverse_it != map.rend(); ++reverse_it)
	{
		std::cout << reverse_it->first << ", " << reverse_it->second << std::endl;
	}

	::std::cout << "\033[0;92mcomparisons\033[0m" << ::std::endl;
	it = map.begin();
	const_it = map.begin();
	reverse_it = map.rend();
	const_reverse_it = map.rend();

	::std::cout << "\033[0;92mit == const_it\033[0m" << ::std::endl;
	std::cout << (it == const_it) << std::endl;
		::std::cout << "\033[0;92mit == it\033[0m" << ::std::endl;
	std::cout << (it == it) << std::endl;
	::std::cout << "\033[0;92mreverse_it == const_reverse_it\033[0m" << ::std::endl;
	std::cout << (reverse_it == const_reverse_it) << std::endl;
	::std::cout << "\033[0;92mconst_it == const_it\033[0m" << ::std::endl;
	std::cout << (const_it == const_it) << std::endl;
}
