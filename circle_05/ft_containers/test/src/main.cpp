#include "test.h"
#include <cstdlib>

int main(int argc, char **argv)
{
	// test_vector
	vec::test_constructor();
	vec::test_capacity();
	system("leaks test");
	return (0);
}
