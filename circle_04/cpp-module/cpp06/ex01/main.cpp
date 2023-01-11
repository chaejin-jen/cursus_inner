#include <iostream>
#include "Serialize.hpp"

int main(void) {
	Data data = {
		"chaejkim",
		"chaejin",
		"kim",
		{1, 2, 3}
	};

	uintptr_t	struct_ptr;
	Data		*data_ptr;

	struct_ptr = serialize(&data);
	data_ptr = deserialize(struct_ptr);

	std::cout << "========================" << std::endl;
	std::cout << "&data : " << &data << std::endl;
	std::cout << data.nick_name << std::endl;
	std::cout << data.first_name << std::endl;
	std::cout << data.last_name << std::endl;
	std::cout << "cx-"<< data.seat.c
		<< 'r'<< data.seat.r
		<< 's'<< data.seat.s << std::endl;
	std::cout << "========================\n" << std::endl;

	std::cout << "struct_ptr : " << struct_ptr << std::endl;

	std::cout << "\n========================" << std::endl;
	std::cout << "data_ptr : " << data_ptr << std::endl;
	std::cout << data_ptr->nick_name << std::endl;
	std::cout << data_ptr->first_name << std::endl;
	std::cout << data_ptr->last_name << std::endl;
	std::cout << "cx-"<< data_ptr->seat.c
		<< 'r'<< data_ptr->seat.r
		<< 's'<< data_ptr->seat.s << std::endl;
	std::cout << "========================" << std::endl;
	
	return 0;
}
