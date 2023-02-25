#pragma once
#ifndef __FT_TYPE_TRAITS_TPP__
#define __FT_TYPE_TRAITS_TPP__

namespace ft
{
	template <bool, typename T = void> struct enable_if {};
	template <typename T> struct enable_if<true, T>     {typedef T type;};

	// 20.9.3 Helper classes
	template <typename T, T v>
		struct integral_constant {
			static const T value = v;
			typedef T value_type;
			typedef integral_constant<T,v> type;
			operator value_type() const { return value; }
		};
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	// is_const
	template <typename T> struct is_const          : public false_type {};
	template <typename T> struct is_const<T const> : public true_type {};

	// remove_const
	template <typename T> struct remove_const          {typedef T type;};
	template <typename T> struct remove_const<const T> {typedef T type;};

	// remove_volatile
	template <typename T> struct remove_volatile             {typedef T type;};
	template <typename T> struct remove_volatile<volatile T> {typedef T type;};

	// remove_cv
	template <typename T> struct remove_cv
	{typedef typename remove_volatile<typename remove_const<T>::type>::type type;};

	// remove_pointer
	template <typename T> struct remove_pointer                    {typedef T type;};
	template <typename T> struct remove_pointer<T*>                {typedef T type;};
	template <typename T> struct remove_pointer<T* const>          {typedef T type;};
	template <typename T> struct remove_pointer<T* volatile>       {typedef T type;};
	template <typename T> struct remove_pointer<T* const volatile> {typedef T type;};

	// is_integral
	template <typename T> struct __ft_is_integral                       : false_type{};
	template <>           struct __ft_is_integral<bool>                 : true_type{};
	template <>           struct __ft_is_integral<char>                 : true_type{};
	template <>           struct __ft_is_integral<signed char>          : true_type{};
	template <>           struct __ft_is_integral<unsigned char>        : true_type{};
	template <>           struct __ft_is_integral<char16_t>             : true_type{};
	template <>           struct __ft_is_integral<char32_t>             : true_type{};
	template <>           struct __ft_is_integral<wchar_t>              : true_type{};
	template <>           struct __ft_is_integral<short>                : true_type{};
	template <>           struct __ft_is_integral<unsigned short>       : true_type{};
	template <>           struct __ft_is_integral<int>                  : true_type{};
	template <>           struct __ft_is_integral<unsigned int>         : true_type{};
	template <>           struct __ft_is_integral<long>                 : true_type{};
	// template <>           struct __ft_is_integral<long long>            : true_type{};  // 'long long' is a C++11 extension
	template <>           struct __ft_is_integral<unsigned long>        : true_type{};
	// template <>           struct __ft_is_integral<unsigned long long>   : true_type{};  //'long long' is a C++11 extension
	template <typename T> struct is_integral : public __ft_is_integral<typename remove_cv<T>::type> {};

	// is_same
	template <typename T, class U> struct is_same         : public false_type {};
	template <typename T>            struct is_same<T, T> : public true_type {};

	// is_empty
	template <typename T>
	struct is_empty {
		struct empty_helper{
			char padding;
		};
		static bool const value = sizeof(empty_helper) == sizeof(T) && !::ft::is_integral<T>::value;
	};
}

#endif /* __FT_TYPE_TRAITS_TPP__ */
