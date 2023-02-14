#pragma once
#ifndef __FT_UTILITY_TPP__
#define __FT_UTILITY_TPP__

/*
	utility synopsis
namespace ft
{

template <class T1, class T2>
struct pair {

	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;
	pair();
	pair(const T1& x, const T2& y);
	template<class U, class V> pair(const pair<U, V> &p);
};

template <class T1, class T2>
	bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y);

template <class T1, class T2>
	bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y);

template <class T1, class T2>
	pair<T1, T2> make_pair(const T1& x, const T2& y);
}
*/

namespace ft
{

template <class T1, class T2>
struct pair {
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;
	pair() : first(T1()), second(T2()) {}
	pair(const T1& x, const T2& y) : first(x), second(y) {}
	template<class U, class V>
	pair(const pair<U, V> &p) : first(p.first), second(p.second) {}
};

template <class T1, class T2>
	bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y){
		return x.first == y.first && x.second == y.second;
	}

template <class T1, class T2>
	bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y){
		return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
	}

template <class T1, class T2>
	pair<T1, T2> make_pair(const T1& x, const T2& y){
		return pair<T1, T2>(x, y);
	}

}

#endif /* __FT_UTILITY_TPP__ */
