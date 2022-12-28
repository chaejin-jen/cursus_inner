#include <iostream>
#include <sstream>
#include <string>

int main(){
	int	a=7;
	int	*ptr=&a;

	// 방법 1 : 실패
	// std::string address_a = static_cast<int *>(ptr);
	// std::cout<<address_a<<std::endl;

	// 방법 2
	// std::cout << ptr << std::endl;

	// 방법 3
	std::ostringstream	oss;
	oss << ptr;
	std::string address_a = oss.str();
	std::cout<<address_a<<std::endl;
}