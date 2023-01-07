#include "iter.hpp"

template <typename T>
void putElement(T const &ref)
{
	std::cout << ref << std::endl;
}

int main(int, char**)
{
	{
		int arr1[] = {1, 2, 3, 4};
		iter(arr1, 4, &putElement);
	}

	std::cout << std::endl;

	{
		char arr[] = "42seoul";
		iter(arr, std::strlen(arr), &putElement);
	}

	std::cout << std::endl;

	{
		float arr[] = {12.3f, 43.2f, 0.234f, -9.83f};
		iter(arr, 4, &putElement);
	}
	
	return 0;
}