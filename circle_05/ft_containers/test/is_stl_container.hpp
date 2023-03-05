#include "vector.hpp"

//specialize a type for all of the STL containers.
template <typename T>
struct is_stl_container:std::false_type{};

template <typename T, std::size_t N>
struct is_stl_container<std::array<T,N> > :std::true_type{};
template <typename Args>
struct is_stl_container<ft::vector<Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::deque <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::list <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::forward_list <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::set <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::multiset <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::map <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::multimap <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::unordered_set <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::unordered_multiset<Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::unordered_map <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::unordered_multimap<Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::stack <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::queue <Args> >:std::true_type{};
//template <typename Args>
//struct is_stl_container<std::priority_queue<Args> >:std::true_type{};
