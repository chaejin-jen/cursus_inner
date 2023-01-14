#include "vector.hpp"
#include "test.h"

//template <typename iterator>
//void putElements(const iterator first, const iterator last);

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
