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

template <class ForwardIterator, class Distance>
	void advance(ForwardIterator& i, Distance n);
template <class ForwardIterator>
	typename iterator_traits<ForwardIterator>::difference_type
		distance(ForwardIterator first, ForwardIterator last);

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
#include <iterator>
#include "ft_type_traits.tpp"

namespace ft {

template <class T>
struct __has_iterator_category
{
private:
	struct __two {char _; char __;};
	template <class U> static __two __test(...); // CHECK
	template <class U> static char __test(typename U::iterator_category* = 0);
public:
	static const bool value = sizeof(__test<T>(0)) == 1;
};

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
	typedef ::std::random_access_iterator_tag iterator_category;
};

template<class T> struct iterator_traits<const T*> {
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef ::std::random_access_iterator_tag iterator_category;
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

// is_input_iterator / is_forward_iterator
template <typename T>
struct is_input_iterator_helper {
	typedef char yes[1];
	typedef char no[2];

	template <typename U>
	static yes& test(typename iterator_traits<U>::value_type*);
	template <typename U>
	static no& test(...);

	static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

template <typename T>
struct is_input_iterator {
	static const bool value =
		is_input_iterator_helper<T>::value &&
		is_same<typename iterator_traits<T>::iterator_category,
					::std::input_iterator_tag>::value;
};

template <typename T>
struct is_forward_iterator_helper {
	typedef char yes[1];
	typedef char no[2];

	template <typename U>
	static yes& test(typename iterator_traits<U>::value_type*);
	template <typename U>
	static no& test(...);

	static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

template <typename T>
struct is_forward_iterator {
	typedef typename iterator_traits<T>::iterator_category category;
	static const bool value =
		is_forward_iterator_helper<T>::value &&
		(is_same<category, ::std::forward_iterator_tag>::value ||
		 is_same<category, ::std::bidirectional_iterator_tag>::value ||
		 is_same<category, ::std::random_access_iterator_tag>::value);
};

template<class ForwardIterator>
typename iterator_traits<ForwardIterator>::difference_type
	distance(ForwardIterator first, ForwardIterator last){
		typename iterator_traits<ForwardIterator>::difference_type n = 0;
		while (first != last) {
			++first; ++n;
		}
		return n;
	}

}

#endif /* __FT_ITERATOR_H__ */
