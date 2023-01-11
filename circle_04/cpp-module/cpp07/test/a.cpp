#include <iostream>

int main(void)
{
	int *a = new int();
	std::cout << *a << std::endl;
	delete a;
	std::cout << *a << std::endl;

	{
		int *b = NULL;
		delete b;
		//std::cout << *b << std::endl;
	}

	return 0;
}
