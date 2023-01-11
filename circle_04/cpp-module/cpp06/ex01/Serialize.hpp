#pragma once
#ifndef __SERIALIZE_H__
#define __SERIALIZE_H__

#include <string>

struct s_Seat {
	int c;
	int r;
	int s;
} typedef Seat;

struct s_Data {
	std::string	nick_name;
	std::string	first_name;
	std::string	last_name;
	Seat		seat;
} typedef Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
