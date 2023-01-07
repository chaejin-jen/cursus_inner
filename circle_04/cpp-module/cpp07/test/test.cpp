#include <iostream>

// https://www.geeksforgeeks.org/template-specialization-c/

template <class T>
class Test
{
	// Data members of test
public:
	Test() // Test<T>() 무슨 차이??
	{
		// Initialization of data members
		std::cout << "General template object \n";
	}
	// Other methods of Test
};

template <>
class Test<int>
{
public:
	Test()
	{
		// Initialization of data members
		std::cout << "Specialized template object\n";
	}
};

int main()
{
	Test<int> a;
	Test<char> b;
	Test<float> c;
	return 0;
}