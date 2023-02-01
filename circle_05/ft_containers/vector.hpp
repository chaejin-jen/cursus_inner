#pragma once
#ifndef __VECTOR_H__
#define __VECTOR_H__

/*
	vector synopsis
namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector
{
public:
	typedef typename Allocator::reference                  reference;
	typedef typename Allocator::const_reference            const_reference;
	typedef implementation-defined                         iterator;
	typedef implementation-defined                         const_iterator;
	typedef T                                              value_type;
	typedef Allocator                                      allocator_type;
	typedef size_t                                         size_type;
	typedef ft::iterator_traits<iterator>::difference_type difference_type;
	typedef typename Allocator::pointer                    pointer;
	typedef typename Allocator::const_pointer              const_pointer;
	typedef ft::reverse_iterator<iterator>                 reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>           const_reverse_iterator;

	explicit vector(const Allocator & = Allocator());
	explicit vector(size_type n, const T& value = T(),
		const Allocator & = Allocator());
	template <typename InputIterator>
	vector(InputIterator first, InputIterator last,
		const Allocator & = Allocator());
	vector(const vector<T, Allocator>& x);
	~vector();
	vector<T, Allocator>& operator=(const vector<T, Allocator>& x);
	template <typename InputIterator>
	void assign(InputIterator first, InputIterator last);
	void assign(size_type n, const T& u);
	allocator_type get_allocator() const;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	size_type size() const;
	size_type max_size() const;
	void resize(size_type sz, T c = T());
	size_type capacity() const;
	bool empty() const;
	void reserve(size_type n);

	reference operator[](size_type n);
	const_reference operator[](size_type n) const;
	const_reference at(size_type n) const;
	reference at(size_type n);
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	void push_back(const T& x);
	void pop_back();
	iterator insert(iterator position, const T& x);
	void insert(iterator position, size_type n, const T& x);
	template <typename InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last);
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void swap(vector<T, Allocator>&);
	void clear();
};

template <typename T, typename Allocator>
bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
bool operator< (const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
bool operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
bool operator> (const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
bool operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
bool operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y);

template <typename T, typename Allocator>
void swap(vector<T, Allocator>& x, vector<T, Allocator>& y);


template <typename T, typename Allocator>
vector<T, Allocator>::vector(const Allocator &);

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_type n, const T& value, const Allocator &);

template <typename T, typename Allocator>
template <typename InputIterator>
vector<T, Allocator>::vector(InputIterator first, InputIterator last, const Allocator &);

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const vector<T, Allocator>& x);

template <typename T, typename Allocator>
vector<T, Allocator>::~vector();

template <typename T, typename Allocator>
vector<T, Allocator>& vector<T, Allocator>::operator=(const vector<T, Allocator>& x);

template <typename T, typename Allocator>
template <typename InputIterator>
void vector<T, Allocator>::assign(InputIterator first, InputIterator last);

template <typename T, typename Allocator>
void vector<T, Allocator>::assign(size_type n, const T& u);

template <typename T, typename Allocator>
typename vector<T, Allocator>::allocator_type
vector<T, Allocator>::get_allocator() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::begin();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::begin() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::end();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::end() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rbegin();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rbegin() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::rend();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::rend() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::size() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::max_size() const;

template <typename T, typename Allocator>
void vector<T, Allocator>::resize(size_type sz, T c);

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::capacity() const;

template <typename T, typename Allocator>
bool vector<T, Allocator>::empty() const;

template <typename T, typename Allocator>
void vector<T, Allocator>::reserve(size_type n);

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::operator[](size_type n);

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::operator[](size_type n) const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::at(size_type n) const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::at(size_type n);

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::front();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::front() const;

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::back();

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::back() const;

template <typename T, typename Allocator>
void vector<T, Allocator>::push_back(const T& x);

template <typename T, typename Allocator>
void vector<T, Allocator>::pop_back();

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::insert(iterator position, const T& x);

template <typename T, typename Allocator>
void vector<T, Allocator>::insert(iterator position, size_type n, const T& x);

template <typename T, typename Allocator>
template <typename InputIterator>
void vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last);

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::erase(iterator position);

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::erase(iterator first, iterator last);

template <typename T, typename Allocator>
void vector<T, Allocator>::swap(vector<T, Allocator>&);

template <typename T, typename Allocator>
void vector<T, Allocator>::clear();

}
*/

#include <memory>
#include <algorithm>
#include <stdexcept>
#include "ft_iterator.hpp"
#include "random_access_iterator.tpp"
#include "ft_type_traits.tpp"

namespace ft {
template <typename T, typename Allocator = ::std::allocator<T> >
class vector
{
public:
	// types:
	typedef typename Allocator::reference reference; // typedef value_type& reference;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef ft::random_access_iterator<pointer> iterator;
	typedef ft::random_access_iterator<const_pointer> const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename ft::iterator_traits<pointer>::difference_type difference_type; // Difference between two pointers
	typedef ft::reverse_iterator<pointer> reverse_iterator;
	typedef ft::reverse_iterator<const_pointer> const_reverse_iterator;

	// construct/copy/destroy:
	explicit vector(const Allocator& alloc = Allocator())
		: start_(0), finish_(0), end_of_storage_(0), alloc_(alloc){
	}
	explicit vector(size_type n, const T& value = T(),
		const Allocator& alloc = Allocator())
			: start_(0), finish_(0), end_of_storage_(0), alloc_(alloc){
			assign(n, value);
		}
	template <typename InputIterator>
	vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
		const Allocator& alloc = Allocator())
			: start_(0), finish_(0), end_of_storage_(0), alloc_(alloc){
			if (last - first > 0)
				assign(first, last);
		}
	vector(const vector<T, Allocator>& x)
		: start_(0), finish_(0), end_of_storage_(0), alloc_(x.alloc_){
			if (x.size())
				assign(x.begin(), x.end());
		}
	~vector() {
		destroy();
	}
	vector<T, Allocator>& operator=(const vector<T, Allocator>& x){
		if (&x != this) {
			assign(x.begin(), x.end());
		}
		return *this;
	}
	template <typename InputIterator>
	void assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last){
		erase(begin(), end());
		insert(begin(), first, last);
	}
	void assign(size_type n, const T& u){
		erase(begin(), end());
		insert(begin(), n, u);
	}
	allocator_type get_allocator() const{
		return allocator_type(alloc_);
	}

	// iterators:
	iterator begin(){
		return iterator(start_);
	}
	const_iterator begin() const{
		return const_iterator(start_);
	}
	iterator end(){
		return iterator(finish_);
	}
	const_iterator end() const{
		return const_iterator(finish_);
	}
	reverse_iterator rbegin(){
		return reverse_iterator(finish_);
	}
	const_reverse_iterator rbegin() const{
		return const_reverse_iterator(finish_);
	}
	reverse_iterator rend(){
		return reverse_iterator(start_);
	}
	const_reverse_iterator rend() const{
		return const_reverse_iterator(start_);
	}

	// capacity:
	size_type size() const{
		return static_cast<size_type>(finish_ - start_);
	}
	size_type max_size() const{
		return size_type(-1) / sizeof(T);
	}
	void resize(size_type sz, T c = T()){
		if (sz > size())
			insert(end(), sz - size(), c);
		else if (sz < size())
			erase(begin() + sz, end());
		else
			;
	}
	size_type capacity() const{
		return size_type(end_of_storage_ - start_);
	}
	bool empty() const{
		return begin() == end();
	}
	void reserve(size_type n){
		if (n > max_size())
			throw ::std::length_error("over max_size");
		if (n > capacity()){
			pointer tmp = alloc_.allocate(n);
			size_type i = 0;
			while (start_ + i < finish_){
				alloc_.construct(tmp + i, *(start_ + i));
				i++;
			}
			destroy();
			start_ = tmp;
			finish_ = tmp + i;
			end_of_storage_ = tmp + n;
		}
	}

	// element access:
	reference operator[](size_type n){
		return start_[n];
	}
	const_reference operator[](size_type n) const{
		return start_[n];
	}
	const_reference at(size_type n) const{
		if (n >= size())
			throw ::std::out_of_range("vector out of range");
		return start_[n];
	}
	reference at(size_type n){
		if (n >= size())
			throw ::std::out_of_range("vector out of range");
		return start_[n];
	}
	reference front(){
		return *start_;
	}
	const_reference front() const{
		return *start_;
	}
	reference back(){
		return *(finish_ - 1);
	}
	const_reference back() const{
		return *(finish_ - 1);
	}

	// modifiers:
	void push_back(const T& x){
		if (finish_ == end_of_storage_)
			reserve(start_ == end_of_storage_ ? 1 : capacity() * 2);
		alloc_.construct(finish_++, x);
	}
	void pop_back(){
		alloc_.destroy(finish_++);
	}
	iterator insert(iterator position, const T& x){
		difference_type pos = position - begin();

		insert(position, 1, x);
		return begin() + pos;
	}
	void insert(iterator position, size_type n, const T& x){
		difference_type pos = position - begin();

		if (n == 0)
			return ;
		if (finish_ + n > end_of_storage_)
			reserve(size() + n);
		move_r(start_ + pos, n);
		pointer p = start_ + pos;
		finish_ += n;
		while (n-- > 0){
			alloc_.construct(p++, x);
		}
	}
	template <typename InputIterator>
	void insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last){
		difference_type pos = position - begin();
		difference_type n = last - first;

		if (n < 0)
			return ;
		if (finish_ + n > end_of_storage_)
			reserve(size() + n);
		move_r(start_ + pos, n);
		pointer p = start_ + pos;
		while (first < last){
			alloc_.construct(p++, *first++);
		}
		finish_ += n;
	}
	iterator erase(iterator position){
		difference_type pos = position - begin();

		move_l(position.base(), 1);
		if (position.base() < finish_)
			--finish_;
		return iterator(start_) + pos;
	}
	iterator erase(iterator first, iterator last){
		difference_type pos = first - begin();
		difference_type n = last - first;

		move_l(first.base(), n);
		finish_ -= n;
		return iterator(start_) + pos;
	}
	void swap(vector<T, Allocator>& x){
		allocator_type alloc(alloc_);
		pointer start(start_);
		pointer finish(finish_);
		pointer end_of_storage(end_of_storage_);
		alloc_ = x.alloc_;
		start_ = x.start_;
		finish_ = x.finish_;
		end_of_storage_ = x.end_of_storage_;
		x.alloc_ = alloc;
		x.start_ = start;
		x.finish_ = finish;
		x.end_of_storage_ = end_of_storage;
	}
	void clear(){
		destroy();
	}

protected:
	pointer start_;
	pointer finish_;
	pointer end_of_storage_;
	allocator_type alloc_;

private:
	void destroy(){
		if (start_)
		{
			pointer p = finish_;
			while (p != start_) {
				alloc_.destroy(--p);
			}
			alloc_.deallocate(start_, end_of_storage_ - start_);
		}
		start_ = finish_ = end_of_storage_ = 0;
	}
	void move_r(pointer p, difference_type n){
		pointer src = finish_;
		pointer dst = finish_ + n;
		while (--src >= p){
			alloc_.construct(--dst, *src);
			alloc_.destroy(src);
		}
	}
	void move_l(pointer p, difference_type n){
		while (p + n < finish_){
			alloc_.destroy(p);
			alloc_.construct(p, *(p + n));
			p++;
		}
		while (p < finish_)
			alloc_.destroy(p++);
	}
};

// operator:
template <typename T, typename Allocator>
bool operator==(const vector<T, Allocator>& x, const vector<T, Allocator>& y){
	if (x.size() != y.size())
		return (false);
	for (size_t i = 0; i < x.size(); i++){
		if (x[i] != y[i])
			return false;
	}
	return true;
}

template <typename T, typename Allocator>
bool operator< (const vector<T, Allocator>& x, const vector<T, Allocator>& y){
	size_t i = 0;
	while (i < x.size() && i < y.size())
	{
		if (x[i] < y[i])
			return true;
		else if (x[i] > y[i])
			return false;
		i++;
	}
	if (i < y.size())
		return true;
	return false;
}

template <typename T, typename Allocator>
bool operator!=(const vector<T, Allocator>& x, const vector<T, Allocator>& y){
	return !(x == y);
}

template <typename T, typename Allocator>
bool operator> (const vector<T, Allocator>& x, const vector<T, Allocator>& y){
	return y < x;
}

template <typename T, typename Allocator>
bool operator>=(const vector<T, Allocator>& x, const vector<T, Allocator>& y){
	return !(x < y);
}

template <typename T, typename Allocator>
bool operator<=(const vector<T, Allocator>& x, const vector<T, Allocator>& y){
	return !(y < x);
}

// specialized algorithms:
template <typename T, typename Allocator>
void swap(vector<T, Allocator>& x, vector<T, Allocator>& y){
	x.swap(y);
}

}

#endif /* __VECTOR_H__ */
