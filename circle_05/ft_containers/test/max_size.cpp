#include <vector>
#include <iostream>
#include <cstdlib>

//max std::size_t is: 18446744073709551615

int main(int ac, char *av[])
{
	size_t a;

	long cnt(100);
	if (ac == 2)
		cnt = strtol(av[1], NULL, 10);
	std::cout << "====================================" << std::endl;
	{
		std::cout << cnt << " Vector:" << std::endl;
		//std::vector<int> vec;
		//for (int i = 0; i < cnt; i++)
		//	vec.push_back(rand());
		std::vector<int> vec(cnt, 1);
		std::cout << "size: " << vec.size() << std::endl;
		std::cout << "max size: " << vec.max_size() << std::endl;
	}

	std::cout << "====================================" << std::endl;
	{
		std::cout << cnt << " Vector2:" << std::endl;
		//std::vector<int> vec2;
		//for (int i = 0; i < cnt; i++)
		//	vec2.push_back(rand());
		std::vector<int> vec2(cnt, 1);
		std::cout << "max size: " << vec2.max_size() << std::endl;
	}
	return 0;
}
