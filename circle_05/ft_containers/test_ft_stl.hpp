#pragma once
#ifndef __FT_STL_H__
#define __FT_STL_H__

#include "test_stl.hpp"

#include "set.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"

#define NS "FT "

typedef ft::set<int>       _set_int;
typedef ft::map<int, int>  _map_int;
typedef ft::stack<int>     _stack_int;
typedef ft::vector<int>    _vector_int;

typedef ft::pair<int, int> _pair;

#endif /* __FT_STL_H__ */
