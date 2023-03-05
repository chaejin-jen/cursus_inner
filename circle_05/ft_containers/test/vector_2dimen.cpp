#include <iostream>
#include <vector>

int main(void)
{
	std::vector < std::vector <int> > v;
	std::vector <int> v2;

	v.push_back(v2);

	v[0].push_back(7);

	std::cout << "begin()->begin()"<< *(v.begin()->begin()) << std::endl;
	std::cout << v[0][0] << std::endl;

	std::cout << v.at(0).at(0) << std::endl;
	return 0;
}
