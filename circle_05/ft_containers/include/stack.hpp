#pragma once
#ifndef __STACK_H__
#define __STACK_H__

/*
	stack synopsis
namespace ft {

template <typename T, typename Container = ft::vector<T> >
class stack
{
public:
	typedef typename Container::value_type                 value_type;
	typedef typename Container::size_type                  size_type;
	typedef          Container                             container_type;

protected:
	Container c;
public:
	explicit stack(const Container& = Container());
	bool      empty() const;
	size_type size()  const;
	value_type&       top();
	const value_type& top() const;
	void push(const value_type& x);
	void pop();
};

template <typename T, typename Container>
bool operator==(const stack<T, Container>& x, const stack<T, Container>& y);

template <typename T, typename Container>
bool operator< (const stack<T, Container>& x, const stack<T, Container>& y);

template <typename T, typename Container>
bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y);

template <typename T, typename Container>
bool operator> (const stack<T, Container>& x, const stack<T, Container>& y);

template <typename T, typename Container>
bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y);

template <typename T, typename Container>
bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y);

}
*/

#include "vector.hpp"

namespace ft {

template <typename T, typename Container = ft::vector<T> >
class stack
{
public:
	typedef typename Container::value_type value_type;
	typedef typename Container::size_type size_type;
	typedef Container container_type;

	template <typename T2, typename Container2>
	friend
	bool operator==(const stack<T2, Container2>& x, const stack<T2, Container2>& y);

	template <typename T2, typename Container2>
	friend
	bool operator< (const stack<T2, Container2>& x, const stack<T2, Container2>& y);

protected:
	container_type c;

public:
	explicit stack(const Container& cntn = Container()) : c(cntn) {}
	bool empty() const{
		return c.empty();
	}
	size_type size() const{
		return c.size();
	}
	value_type& top(){
		return c.back();
	}
	const value_type& top() const{
		return c.back();
	}
	void push(const value_type& x){
		c.push_back(x);
	}
	void pop(){
		c.pop_back();
	}
};

template <typename T, typename Container>
bool operator==(const stack<T, Container>& x, const stack<T, Container>& y){
	return x.c == y.c;
}

template <typename T, typename Container>
bool operator< (const stack<T, Container>& x, const stack<T, Container>& y){
	return x.c < y.c;
}

template <typename T, typename Container>
bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y){
	return !(x == y);
}

template <typename T, typename Container>
bool operator> (const stack<T, Container>& x, const stack<T, Container>& y){
	return y < x;
}

template <typename T, typename Container>
bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y){
	return !(x < y);
}

template <typename T, typename Container>
bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y){
	return !(y < x);
}

}

#endif /* __STACK_H__ */
