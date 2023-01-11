# ft_containers
## Subject
### Mandatory part
- `vector`
	- You don’t have to do the vector<bool> specialization.
- `map`
- `stack`
	- It will use your vector class as default underlying container. But it must still be compatible with other containers, the STL ones included.

- `std::iterator_traits`
- `std::reverse_iterator`
- `std::enable_if`
	- Yes, it is C++11 but you will be able to implement it in a C++98 manner.
	- This is asked so you can discover SFINAE.
- `std::is_integral`
- `std::equal` and/or `std::lexicographical_compare`
- `std::pair`
- `std::make_pair`

### Bonus part
You will get extra points if you implement one last container:
- `set`
	- But this time, a Red-Black tree is mandatory.