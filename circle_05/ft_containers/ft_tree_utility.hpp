#pragma once
#ifndef __FT_TREE_UTILITY_TPP__
#define __FT_TREE_UTILITY_TPP__

#include "ft_utility.hpp"

/*
memory
	addressof
	unique_ptr
*/ 

namespace ft{

// addressof

template <class Tp>
inline
Tp*
addressof(Tp& x)
{
	return (Tp*)&reinterpret_cast<const volatile char&>(x);
}

template <class Tp, class Dp>
class unique_ptr
{
public:
	typedef Tp  element_type;
	typedef Dp  deleter_type;
	typedef Tp* pointer;
private:
	pair<pointer, deleter_type> ptr;

	unique_ptr(unique_ptr&);
	template <class Up, class Ep>
		unique_ptr(unique_ptr<Up, Ep>&);
	unique_ptr& operator=(unique_ptr&);
	template <class Up, class Ep>
		unique_ptr& operator=(unique_ptr<Up, Ep>&);

	typedef Tp&                 reference;
	typedef deleter_type&       Dp_reference;
	typedef const deleter_type& Dp_const_reference;
public:
	unique_ptr()
		: ptr(pointer()){}
	explicit unique_ptr(pointer p)
		: ptr(p){}

	template <class Up, class Ep>
	unique_ptr& operator=(unique_ptr<Up, Ep> __u){
		reset(__u.release());
		ptr.second() = __u.get_deleter();
		return *this;
	}

	unique_ptr(pointer p, deleter_type d)
		: ptr(p, d) {}
	~unique_ptr() {
		reset();
	}

	reference operator*() const{
		return *ptr.first();
	}
	pointer operator->() const {
		return ptr.first();
	}
	pointer get() const {
		return ptr.first();
	}
    Dp_reference get_deleter(){
		return ptr.second();
	}
	Dp_const_reference get_deleter() const{
		return ptr.second();
	}
	operator bool() const{
		return ptr.first() != NULL;
	}

	pointer release(){
		pointer t = ptr.first();
		ptr.first() = pointer();
		return t;
	}

	void reset(pointer p = pointer()){
		pointer tmp = ptr.first();
		ptr.first() = p;
		if (tmp)
			ptr.second()(tmp);
	}
};

template <class Tp, class Dp>
class unique_ptr<Tp[], Dp>
{
public:
	typedef Tp element_type;
	typedef Dp deleter_type;
	typedef Tp* pointer;
private:
	pair<pointer, deleter_type> ptr;

	unique_ptr(unique_ptr&);
	template <class Up, class Dp2>
		unique_ptr(unique_ptr<Up, Dp2>&);
	unique_ptr& operator=(unique_ptr&);
	template <class Up, class Dp2>
		unique_ptr& operator=(unique_ptr<Up, Dp2>&);

	typedef Tp&                 reference;
	typedef deleter_type&       Dp_reference;
	typedef const deleter_type& Dp_const_reference;
public:
	unique_ptr()
		: ptr(pointer()){}

	explicit unique_ptr(pointer p)
		: ptr(p){}

	unique_ptr(pointer p, deleter_type d)
		: ptr(p, d) {}

	~unique_ptr() {
		reset();
	}

	pointer get() const {
		return ptr.first();
	}
	Dp_reference get_deleter(){
		return ptr.second();
	}
	Dp_const_reference get_deleter() const{
		return ptr.second();
	}

	pointer release(){
		pointer t = ptr.first();
		ptr.first() = pointer();
		return t;
	}

	void reset(pointer p = pointer()){
		pointer tmp = ptr.first();
		ptr.first() = p;
		if (tmp)
			ptr.second()(tmp);
	}
};

}

#endif /* __FT_TREE_UTILITY_TPP__ */
