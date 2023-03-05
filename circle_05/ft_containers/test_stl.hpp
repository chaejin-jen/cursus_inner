#pragma once
#ifndef __TEST_STL_H__
#define __TEST_STL_H__

#include <iostream>
#include <string>

#include <sys/time.h>
#include <cstdlib>
#include <unistd.h>


#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"
#define GRAY "\033[1;30m"
#define BOLD "\033[1m"

typedef long long ll;

#define SECONDS 1000000LL

#define VEC_SIZE 1000
#define STACK_SIZE 1000
#define MAP_SIZE 100000
#define SET_SIZE 100000

//#define name_space "std  :\t"

class Tester
{
public:
	Tester(const std::string &ns)
		: name_space(ns) {};
	void timer()
	{
		gettimeofday(&end, NULL);
		elasped_time =  ((end.tv_sec - start.tv_sec) * SECONDS + (end.tv_usec - start.tv_usec));
		if (elasped_time < 1000)
			std::cout << BLUE << BOLD << elasped_time << " us" << RESET << std::endl;
		else
			std::cout << BLUE << BOLD << elasped_time / 1000 << " ms" << RESET << std::endl;

	}
private:
	timeval start;
	timeval end;

	ll elasped_time;

	std::string name_space;

	void set_timer(){
		gettimeofday(&start, NULL);
	}

public:

	void putTestName(const std::string &container_name)
	{
		std::cout << CYAN << BOLD << "\n\n------------- " << name_space << container_name << " -------------" << RESET << std::endl;
	}
	void putMethodName(const std::string &method_name)
	{
		std::cout << method_name << std::endl;
		set_timer();
	}
	void exit()
	{
		std::cout << RED << BOLD << "fail" << RESET << std::endl;
		::exit(1);
	}
};


#endif /* __TEST_STL_H__ */
