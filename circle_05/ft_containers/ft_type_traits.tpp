#pragma once
#ifndef __FT_TYPE_TRAITS_TPP__
#define __FT_TYPE_TRAITS_TPP__

namespace ft
{
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

	template <typename T>
	struct is_integral : false_type{};
	template <>
	struct is_integral<bool> : true_type{};
	template <>
	struct is_integral<char> : true_type{};
	template <>
	struct is_integral<signed char> : true_type{};
	template <>
	struct is_integral<unsigned char> : true_type{};
	template <>
	struct is_integral<char16_t> : true_type{};
	template <>
	struct is_integral<char32_t> : true_type{};
	template <>
	struct is_integral<wchar_t> : true_type{};
	template <>
	struct is_integral<short> : true_type{};
	template <>
	struct is_integral<unsigned short> : true_type{};
	template <>
	struct is_integral<int> : true_type{};
	template <>
	struct is_integral<unsigned int> : true_type{};
	template <>
	struct is_integral<long> : true_type{};
	//template <>
	//struct is_integral<long long> : true_type{};           // 'long long' is a C++11 extension
	template <>
	struct is_integral<unsigned long> : true_type{};
	//template <>
	//struct is_integral<unsigned long long> : true_type{};  //'long long' is a C++11 extension

	// If B is true, the member typedef type shall equal T;
	// otherwise, there shall be no member type.
	// usage : template <bool b, class T=void> typename enable_if<b,T>::type;
	template <bool, class T = void>
		struct enable_if {};

	template <class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	// is_const
	template <class Tp> struct is_const            : public false_type {};
	template <class Tp> struct is_const<Tp const> : public true_type {};

	// remove_const
	template <class Tp> struct remove_const            {typedef Tp type;};
	template <class Tp> struct remove_const<const Tp> {typedef Tp type;};

	// is_empty
	// Note : not guaranteed by the C++ standard
	//        Assumeing compiler uses the "null pointer optimization"
	//         to ensure that casting a null pointer to a pointer
	//         to a non-empty class or struct results in a non-null pointer
	template <typename T>
	struct is_empty {
		struct empty_helper{
			char padding;
		};
		static bool const value = sizeof(empty_helper) == sizeof(T) && !static_cast<T*>(0);
		// static bool const value = sizeof(empty_helper) == sizeof(T) && !ft::is_integral<T>::value);
	};

}

#endif /* __FT_TYPE_TRAITS_TPP__ */
