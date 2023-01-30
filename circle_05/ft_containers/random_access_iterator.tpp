#pragma once
#ifndef __FT_ITERATORS_H__
#define __FT_ITERATORS_H__

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
		return *(current + n);
	}
};

template <class Iterator>
	bool operator==(
		const random_access_iterator<Iterator>& x,
		const random_access_iterator<Iterator>& y){
			return x.base() == y.base();
		}
template <class Iterator>
	bool operator<(
		const random_access_iterator<Iterator>& x,
		const random_access_iterator<Iterator>& y){
			return x.base() < y.base();
		}
template <class Iterator>
	bool operator!=(
		const random_access_iterator<Iterator>& x,
		const random_access_iterator<Iterator>& y){
			return x.base() != y.base();
		}
template <class Iterator>
	bool operator>(
		const random_access_iterator<Iterator>& x,
		const random_access_iterator<Iterator>& y){
			return x.base() > y.base();
		}
template <class Iterator>
	bool operator>=(
		const random_access_iterator<Iterator>& x,
		const random_access_iterator<Iterator>& y){
			return x.base() >= y.base();
		}
template <class Iterator>
	bool operator<=(
		const random_access_iterator<Iterator>& x,
		const random_access_iterator<Iterator>& y){
			return x.base() <= y.base();
		}

template <class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator-(
			const random_access_iterator<Iterator>& x,
			const random_access_iterator<Iterator>& y){
				return x.base() - y.base();
			}
template <class Iterator>
	random_access_iterator<Iterator> operator+(
		typename random_access_iterator<Iterator>::difference_type n,
		const random_access_iterator<Iterator>& x){
			return random_access_iterator<Iterator> (n + x.base());
		}

}

#endif /* __FT_ITERATORS_H__ */
