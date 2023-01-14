#include "test.h"
#include "vector.hpp"

//#include <vector>
//namespace ft = std;

void vec::test_constructor()
{
	::ft::vector<int> vector_a(5, 100);
	::ft::vector<int> vector_b(3);
	::ft::vector<int> vector_c(vector_a);
	*(vector_a.begin()) = 77;
	putElements(vector_a.begin(), vector_a.end());
	putElements(vector_b.begin(), vector_b.end());
	putElements(vector_c.begin(), vector_c.end());
	::std::cout << "*(vector_a.rbegin()) = 33;" << ::std::endl;
	*(vector_a.rbegin()) = 33;
	putElements(vector_a.rbegin(), vector_a.rend());
}

void vec::test_capacity()
{
	::ft::vector<int> vector_a(5, 100);
	putElements(vector_a.begin(), vector_a.end());
	::std::cout << "size: " << vector_a.size() << ::std::endl;
	::std::cout << "max_size: " << vector_a.max_size() << ::std::endl;
	::std::cout << "capacity: " << vector_a.capacity() << ::std::endl;
	::std::cout << "do reserve(10)!" << ::std::endl;
	vector_a.reserve(10);
	putElements(vector_a.begin(), vector_a.end());
	::std::cout << "size: " << vector_a.size() << ::std::endl;
	::std::cout << "capacity: " << vector_a.capacity() << ::std::endl;
	::std::cout << "max_size: " << vector_a.max_size() << ::std::endl;
	//putElements(vector_a.rbegin(), vector_a.rend());
}
