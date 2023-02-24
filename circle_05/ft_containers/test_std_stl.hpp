#pragma once
#ifndef __STD_STL_H__
#define __STD_STL_H__

#include "test_stl.hpp"

#include <set>
#include <map>
#include <stack>
#include <vector>

#define NS "STD "

typedef std::set<int>       _set_int;
typedef std::map<int, int>  _map_int;
typedef std::stack<int>     _stack_int;
typedef std::vector<int>    _vector_int;

typedef std::pair<int, int> _pair;

#endif /* __STD_STL_H__ */
