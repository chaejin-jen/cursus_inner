#include "test.h"
#include <cstdlib>

int main(int argc, char **argv)
{
	// test_vector
	vec::test_constructor();
	vec::test_capacity();
	vec::test_swap();
	//vec::test_vvector();
	vec::test_operator();
	vec::test_element_access();
	vec::test_modifiers();
	//test_vec_enable_if();
	std::cout << "\033[0;90m" << std::endl;
	system("leaks test");
	return (0);
}
