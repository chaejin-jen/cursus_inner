#include "test.h"
#include "vector.hpp"

void test_vec_enable_if()
{
	{
		::std::cout << "======= test is_integral, enable_if =======" << ::std::endl;
		typedef ft::vector<int>::iterator v_iter;
		::std::cout << "is_integtal v_iter " << (ft::is_integral<v_iter>::value) << ::std::endl;
		::std::cout << "is_integtal int    " << (ft::is_integral<int>::value) << ::std::endl;

		typedef ft::enable_if<!ft::is_integral<v_iter>::value, v_iter>::type v_iter_type;
		typedef ft::enable_if<ft::is_integral<int>::value, int>::type int_type;
		::std::cout << "\n     sizeof v_iter " << sizeof(v_iter_type) << ::std::endl;
		::std::cout << "     sizeof int    " << sizeof(int_type) << ::std::endl;
	}
}
