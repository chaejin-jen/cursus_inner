#pragma once
#ifndef __FT_ITERATOR_H__
#define __FT_ITERATOR_H__


/*
    iterator synopsis
namespace ft {

template<class Iterator> struct iterator_traits;

template<class T> struct iterator_traits<T*>;

template<class T> struct iterator_traits<const T*>;

template<class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T&> struct iterator;

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag: public input_iterator_tag {};
struct bidirectional_iterator_tag: public forward_iterator_tag {};
struct random_access_iterator_tag: public bidirectional_iterator_tag {};

template <class InputIterator, class Distance>
	void advance(InputIterator& i, Distance n);
template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last);

template <class Iterator> class reverse_iterator : public
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

	reverse_iterator();
	explicit reverse_iterator(Iterator x);
	template <class U>
	reverse_iterator(const reverse_iterator<U>& u);

	Iterator base() const; // explicit
	reference operator*() const;
	pointer operator->() const;

	reverse_iterator& operator++();
	reverse_iterator operator++(int);
	reverse_iterator& operator--();
	reverse_iterator operator--(int);

	reverse_iterator operator+ (difference_type n) const;
	reverse_iterator& operator+=(difference_type n);
	reverse_iterator operator- (difference_type n) const;
	reverse_iterator& operator-=(difference_type n);
	reference operator[](difference_type n) const;
};

template <class Iterator>
	bool operator==(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	bool operator<(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	bool operator!=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	bool operator>(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	bool operator>=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);
template <class Iterator>
	bool operator<=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y);

template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator>& x,
			const reverse_iterator<Iterator>& y);
template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x);

}
*/

#include <cstddef>

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag: public input_iterator_tag {};
struct bidirectional_iterator_tag: public forward_iterator_tag {};
struct random_access_iterator_tag: public bidirectional_iterator_tag {};

template<class Iterator> struct iterator_traits {
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
	typedef typename Iterator::iterator_category iterator_category;
};

template<class T> struct iterator_traits<T*> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef random_access_iterator_tag iterator_category;
};

template<class T> struct iterator_traits<const T*> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef random_access_iterator_tag iterator_category;
};

template<class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T&> struct iterator {
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

template <class Iterator> class reverse_iterator : public
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

	reverse_iterator(){}
	explicit reverse_iterator(Iterator x): current(x){}
	template <class U>
	reverse_iterator(const reverse_iterator<U>& u): current(u.base()){}

	Iterator base() const{ return current; } // explicit
	reference operator*() const{
		Iterator tmp = current;
		return *--tmp;
	}
	pointer operator->() const{ return &(operator*()); }

	reverse_iterator& operator++(){
		--current;
		return *this;
	}
	reverse_iterator operator++(int){
		reverse_iterator tmp = *this;
		--current;
		return tmp;
	}
	reverse_iterator& operator--(){
		++current;
		return *this;
	}
	reverse_iterator operator--(int){
		reverse_iterator tmp = *this;
		++current;
		return tmp;
	}

	reverse_iterator operator+ (difference_type n) const{
		return reverse_iterator(current - n);
	}
	reverse_iterator& operator+=(difference_type n){
		current -= n;
		return *this;
	}
	reverse_iterator operator- (difference_type n) const{
		return reverse_iterator(current + n);
	}
	reverse_iterator& operator-=(difference_type n){
		current += n;
		return *this;
	}
	reference operator[](difference_type n) const{
		return current[-n - 1];
	}
};

template <class T, class U>
	bool operator==(
		const reverse_iterator<T>& x,
		const reverse_iterator<U>& y){
			return x.base() == y.base();
		}
template <class T, class U>
	bool operator<(
		const reverse_iterator<T>& x,
		const reverse_iterator<U>& y){
			return x.base() > y.base();
		}
template <class T, class U>
	bool operator!=(
		const reverse_iterator<T>& x,
		const reverse_iterator<U>& y){
			return x.base() != y.base();
		}
template <class T, class U>
	bool operator>(
		const reverse_iterator<T>& x,
		const reverse_iterator<U>& y){
			return x.base() < y.base();
		}
template <class T, class U>
	bool operator>=(
		const reverse_iterator<T>& x,
		const reverse_iterator<U>& y){
			return x.base() <= y.base();
		}
template <class T, class U>
	bool operator<=(
		const reverse_iterator<T>& x,
		const reverse_iterator<U>& y){
			return x.base() >= y.base();
		}

template <class T, class U>
	typename reverse_iterator<T>::difference_type operator-(
			const reverse_iterator<T>& x,
			const reverse_iterator<U>& y){
				return y.base() - x.base();
			}
template <class T>
	reverse_iterator<T> operator+(
		typename reverse_iterator<T>::difference_type n,
		const reverse_iterator<T>& x){
			return reverse_iterator<T>(x.base() - n);
		}

template<class InputIterator>
typename iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last){
		typename iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last) {
			++first; ++n;
		}
		return n;
	}

}

#endif /* __FT_ITERATOR_H__ */
