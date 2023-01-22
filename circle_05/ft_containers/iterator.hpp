#pragma once
#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <cstddef>
#include <iosfwd>

namespace ft {

// primitives:
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

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag: public input_iterator_tag {};
struct bidirectional_iterator_tag: public forward_iterator_tag {};
struct random_access_iterator_tag: public bidirectional_iterator_tag {};

// iterator operations:
template <class InputIterator, class Distance>
	void advance(InputIterator& i, Distance n);
template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last);

// predefined iterators:
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

template <class Iterator>
	bool operator==(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y){
			return x.current == y.current
		}
template <class Iterator>
	bool operator<(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y){
			return x.current > y.current
		}
template <class Iterator>
	bool operator!=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y){
			return x.current != y.current
		}
template <class Iterator>
	bool operator>(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y){
			return x.current < y.current
		}
template <class Iterator>
	bool operator>=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y){
			return x.current <= y.current
		}
template <class Iterator>
	bool operator<=(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y){
			return x.current >= y.current
		}

template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator>& x,
			const reverse_iterator<Iterator>& y){
				return y.current - x.current
			}
template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x){
			return reverse_iterator<Iterator> (x.current - n)
		}

template <class Container> class back_insert_iterator;
template <class Container>
	back_insert_iterator<Container> back_inserter(Container& x);

template <class Container> class front_insert_iterator;
template <class Container>
	front_insert_iterator<Container> front_inserter(Container& x);

template <class Container> class insert_iterator;
template <class Container, class Iterator>
	insert_iterator<Container> inserter(Container& x, Iterator i);

// stream iterators:
template <class T, class charT = char, class traits = std::char_traits<charT>,
	class Distance = std::ptrdiff_t>
class istream_iterator;
template <class T, class charT, class traits, class Distance>
	bool operator==(const istream_iterator<T,charT,traits,Distance>& x,
		const istream_iterator<T,charT,traits,Distance>& y);
template <class T, class charT, class traits, class Distance>
	bool operator!=(const istream_iterator<T,charT,traits,Distance>& x,
		const istream_iterator<T,charT,traits,Distance>& y);

template <class T, class charT = char, class traits = std::char_traits<charT> >
	class ostream_iterator;

template<class charT, class traits = std::char_traits<charT> >
	class istreambuf_iterator;
template <class charT, class traits>
	bool operator==(const istreambuf_iterator<charT,traits>& a,
		const istreambuf_iterator<charT,traits>& b);
template <class charT, class traits>
	bool operator!=(const istreambuf_iterator<charT,traits>& a,
		const istreambuf_iterator<charT,traits>& b);

template <class charT, class traits = std::char_traits<charT> >
	class ostreambuf_iterator;

/* reverse function
template <class BidirectionalIterator>
void reverse(BidirectionalIterator first, BidirectionalIterator last) {
	typename iterator_traits<BidirectionalIterator>::difference_type n =
		distance(first, last);
	--n;
	while(n > 0) {
		typename iterator_traits<BidirectionalIterator>::value_type
		tmp = *first;
		*first++ = *--last;
		*last = tmp;
		n -= 2;
	}
}
*/

}
