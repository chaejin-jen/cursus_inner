#pragma once
#include "../system/lib.hpp"
#include MAP

#include <string>

template <class T, class V, class C>
void fillMap(std::map<T, V, C> &mp) {
	mp.insert(std::make_pair(16, 3));
	mp.insert(std::make_pair(8, 3));
	mp.insert(std::make_pair(23, 3));
	mp.insert(std::make_pair(7, 3));
	mp.insert(std::make_pair(19, 3));
	mp.insert(std::make_pair(29, 3));
	mp.insert(std::make_pair(41, 3));
	mp.insert(std::make_pair(4, 3));
	mp.insert(std::make_pair(11, 3));
}

template <class T, class V, class C>
void fillMap(_map<T, V, C> &mp) {
	mp.insert(_make_pair(16, 3));
	mp.insert(_make_pair(8, 3));
	mp.insert(_make_pair(23, 3));
	mp.insert(_make_pair(7, 3));
	mp.insert(_make_pair(19, 3));
	mp.insert(_make_pair(29, 3));
	mp.insert(_make_pair(41, 3));
	mp.insert(_make_pair(4, 3));
	mp.insert(_make_pair(11, 3));
}

class MapBoolTest {
public:
	std::map<int, int> m1, m2, m3, m4;
	std::map<std::string, std::string> m5, m6, m7, m8, m9;
	_map<int, int> mp1, mp2, mp3, mp4;
	_map<std::string, std::string> mp5, mp6, mp7, mp8, mp9;

	::std::string str1 = "123";
	::std::string str2 = "124";
	::std::string str3 = "12";

	MapBoolTest() {
		m1.insert(std::make_pair(2, 3)); mp1.insert(ft::make_pair(2, 3));
		m2.insert(std::make_pair(3, 3)); mp2.insert(ft::make_pair(3, 3));
		m3.insert(std::make_pair(3, 4)); mp3.insert(ft::make_pair(3, 4));
		m4.insert(std::make_pair(4, 4)); mp4.insert(ft::make_pair(4, 4));
		m4.insert(std::make_pair(4, 5)); mp4.insert(ft::make_pair(4, 5));
		m5.insert(std::make_pair(str1, str1)); mp5.insert(ft::make_pair(str1, str1));
		m6.insert(std::make_pair(str1, str2)); mp6.insert(ft::make_pair(str1, str2));
		m7.insert(std::make_pair(str2, str1)); mp7.insert(ft::make_pair(str2, str1));
		m8.insert(std::make_pair(str3, str1)); mp8.insert(ft::make_pair(str3, str1));
		m9.insert(std::make_pair(str1, str3)); mp9.insert(ft::make_pair(str1, str3));
	}
};

template <class T, class V>
int run_map_unit_test(std::string test_name, std::vector<int> (func1)(std::map<T, V>), std::vector<int> (func2)(_map<T, V>)) {
    int    result;
    int    leaks;
	time_t t1;
	time_t t2;
	std::vector<int > res1;
	std::vector<int > res2;
	std::map<int, int> map;
	_map<int, int> my_map;

	printElement(test_name);
	res1 = func1(map);
	res2 = func2(my_map);
	if (res1 == res2) {
	    printElement("OK");
	    result = 0;
	}
	else {
	    printElement("FAILED");
	    result = 1;
	}
	t1 = g_end1 - g_start1, t2 = g_end2 - g_start2;
	(t1 >= t2) ? printElement(GREEN + std::to_string(t2) + "ms" + RESET) : printElement(REDD + std::to_string(t2) + "ms" + RESET);
	(t1 > t2) ? printElement(REDD + std::to_string(t1) + "ms" + RESET) : printElement(GREEN + std::to_string(t1) + "ms" + RESET);
	leaks = leaks_test(getpid());
	cout << endl;

	return !(!result && !leaks);
}

template <class T, class V, class C, class A>
int run_map_allocator_unit_test(std::string test_name, void (func)(_map<T, V, C, A>)) {

    _map<T, V, C, A> my_map;

    printElement(test_name);
    func(my_map);
    if (_allocator_used) {
        printElement("OK");
        cout << endl;
        return (0);
    }
    else {
        printElement("FAILED");
        cout << endl;
        return (1);
    }
}
