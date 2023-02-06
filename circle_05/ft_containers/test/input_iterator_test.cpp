#include <iostream>
#include "../vector.hpp"
#include <fstream>
#include <typeinfo>

int main(void) {
	std::cout<< "ft::vector<char> v((std::istreambuf_iterator<char>(source)), "
	<< "std::istreambuf_iterator<char>()) " << std::endl;

	std::cout << "\n\n===============Makefile print test "
					"(constructor)================\n\n";
	std::ifstream source("Makefile", std::ios::binary);
	std::istream_iterator<char> it(source);
	std::istream_iterator<char> it2(source);
	//std::istreambuf_iterator<char> it(source);
	//std::istreambuf_iterator<char> it2(source);
	std::cout
		<< typeid(std::istreambuf_iterator<char>::iterator_category).name()
		<< '\n';

	for (;it != std::istream_iterator<char>(); ++it) {
	//for (;it != std::istreambuf_iterator<char>(); ++it) {
		std::cout << *it;
	}

	std::cout << "\n segvsegv\n";

	
	for (;it2 != std::istream_iterator<char>(); ++it2) {
	//for (;it2 != std::istreambuf_iterator<char>(); ++it2) {
		std::cout << "empty?";
		std::cout << *it2 << '\n';
	}

	//ft::vector<char> vec_str(it, std::istreambuf_iterator<char>());
	//ft::vector<char>::iterator vec_it;
}
