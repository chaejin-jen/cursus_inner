#pragma once
#ifndef __FT_TREE_UTILITY_TPP__
#define __FT_TREE_UTILITY_TPP__

#include "ft_utility.hpp"

/*
for rebind
	construct/destruct

memory
	addressof
	unique_ptr
*/ 

namespace ft{

// construct/destruct
template <typename T1, typename T2>
inline void construct(T1* p, const T2& value) {
	new (p) T1(value);
}

template <typename T1>
inline void construct(T1* p) {
	new (p) T1();
}

template <typename Tp>
inline void destroy(Tp* pointer) {
	pointer->~Tp();
}

// addressof

template <class Tp>
inline
Tp*
addressof(Tp& x){
	return (Tp*)&reinterpret_cast<const volatile char&>(x);
}

template<typename Tp, typename Dp>
class unique_ptr {
public:
	// Constructors
	explicit unique_ptr(Tp* ptr = 0) : __ptr_(ptr), __dp_(0) {}
	// explicit unique_ptr(Tp* ptr, Dp&=* dptr) : __ptr_(ptr), __dptr_(dptr) {}
	explicit unique_ptr(Tp* ptr, Dp dp) : __ptr_(ptr), __dp_(dp) {}
	
	// Destructor
	~unique_ptr() {
		if (__ptr_)
			__dp_(__ptr_);
	}
	
	// Release ownership
	Tp* release() {
		Tp* ptr = __ptr_;
		__ptr_ = 0;
		return ptr;
	}
	
	// Reset pointer
	void reset(Tp* ptr = 0) {
		if (__ptr_ != ptr) {
			if (__ptr_)
				__dp_(__ptr_);
			__ptr_ = ptr;
		}
	}
	
	// Overload operators
	Tp& operator*() const { return *__ptr_; }
	Tp* operator->() const { return __ptr_; }
	
	// Getters
	Tp* get() const { return __ptr_; }
	Dp& get_deleter() { return __dp_; }
	const Dp& get_deleter() const { return __dp_; }
	
	// Boolean conversion operator
	operator bool() const { return __ptr_ != 0; }
	
private:
	Tp* __ptr_;
	Dp __dp_;

public:
	// Disable copy constructor and copy assignment operator
	unique_ptr(const unique_ptr&);
	unique_ptr& operator=(const unique_ptr&);
};

}

#endif /* __FT_TREE_UTILITY_TPP__ */
