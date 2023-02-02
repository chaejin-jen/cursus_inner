#pragma once
#ifndef __RANDOM_ACCESS_ITTERATOR_TPP__
#define __RANDOM_ACCESS_ITTERATOR_TPP__

#include "ft_iterator.hpp"

namespace ft{

template <class Iterator> class random_access_iterator : public
	iterator<typename iterator_traits<Iterator>::iterator_category,
		typename iterator_traits<Iterator>::value_type,
		typename iterator_traits<Iterator>::difference_type,
		typename iterator_traits<Iterator>::pointer,
		typename iterator_traits<Iterator>::reference> {
protected:
	Iterator current;
public:
	typedef Iterator iterator_type;
	typedef typename iterator_traits<Iterator>::difference_type difference_type;
	typedef typename iterator_traits<Iterator>::reference reference;
	typedef typename iterator_traits<Iterator>::pointer pointer;

	random_access_iterator(){}
	explicit random_access_iterator(Iterator x): current(x){}
	template <class U>
	random_access_iterator(const random_access_iterator<U>& u): current(u.base()){}

	Iterator base() const{ return current; } // explicit
	reference operator*() const{
		return *current;
	}
	pointer operator->() const{ return &(operator*()); }

	random_access_iterator& operator++(){
		++current;
		return *this;
	}
	random_access_iterator operator++(int){
		random_access_iterator tmp = *this;
		++current;
		return tmp;
	}
	random_access_iterator& operator--(){
		--current;
		return *this;
	}
	random_access_iterator operator--(int){
		random_access_iterator tmp = *this;
		--current;
		return tmp;
	}

	random_access_iterator operator+ (difference_type n) const{
		return random_access_iterator(current + n);
	}
	random_access_iterator& operator+=(difference_type n){
		current += n;
		return *this;
	}
	random_access_iterator operator- (difference_type n) const{
		return random_access_iterator(current - n);
	}
	random_access_iterator& operator-=(difference_type n){
		current -= n;
		return *this;
	}
	reference operator[](difference_type n) const{
		return current[n];
	}
};

template <class T, class U>
	bool operator==(
		const random_access_iterator<T>& x,
		const random_access_iterator<U>& y){
			return x.base() == y.base();
		}
template <class T, class U>
	bool operator<(
		const random_access_iterator<T>& x,
		const random_access_iterator<U>& y){
			return x.base() < y.base();
		}
template <class T, class U>
	bool operator!=(
		const random_access_iterator<T>& x,
		const random_access_iterator<U>& y){
			return x.base() != y.base();
		}
template <class T, class U>
	bool operator>(
		const random_access_iterator<T>& x,
		const random_access_iterator<U>& y){
			return x.base() > y.base();
		}
template <class T, class U>
	bool operator>=(
		const random_access_iterator<T>& x,
		const random_access_iterator<U>& y){
			return x.base() >= y.base();
		}
template <class T, class U>
	bool operator<=(
		const random_access_iterator<T>& x,
		const random_access_iterator<U>& y){
			return x.base() <= y.base();
		}

template <class T, class U>
	typename random_access_iterator<T>::difference_type operator-(
		const random_access_iterator<T>& x,
		const random_access_iterator<U>& y){
		return x.base() - y.base();
		}
template<class T>
	random_access_iterator<T> operator+(
	typename random_access_iterator<T>::difference_type n,
	const random_access_iterator<T>& x){
		return random_access_iterator<T>(x.base() + n);
	}
}

#endif /* __RANDOM_ACCESS_ITTERATOR_TPP__ */
