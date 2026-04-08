#include <cstddef>
#include <stdlib.h>
#include <deque>
#include <list>
#include <vector>
#include "easyfind.hpp"

#define MAX_RAND 1000000L

template <typename T>
T ft_make_container( void ) {
	T ret;
	for (int i = 0; i < 5; i++)
	{
		int random = rand() / MAX_RAND;;
		ret.push_back(random);

	}
	return (ret);
}

int main()
{
	srand(time(NULL));
	int			to_find = 42;

	std::vector<int> vect_int = ft_make_container<std::vector<int> >();
	std::vector<double> vect_double = ft_make_container<std::vector<double> >();
	std::deque<int> deque_int = ft_make_container<std::deque<int> >();
	std::deque<double> deque_double = ft_make_container<std::deque<double> >();
	std::list<int> list_int = ft_make_container<std::list<int> >();
	std::list<double> list_double = ft_make_container<std::list<double> >();

	std::cout << "=== Int not in ===\n";
	try {
		easyfind(vect_int, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try {
		easyfind(deque_int, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try {
		easyfind(list_int, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	vect_double.push_back(42.042);
	deque_double.push_back(42.042);
	list_double.push_back(42.042);

	std::cout << "=== Compare to double ===\n";
	try {
		easyfind(vect_double, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() <<'\n';
	}

	try {
		easyfind(deque_double, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() <<'\n';
	}

	try {
		easyfind(list_double, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "=== Added in vect ===\n";
	vect_int.push_back(42);
	try {
		easyfind(vect_int, to_find);
		easyfind(deque_int, to_find);
		easyfind(list_int, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=== Added in rest ===\n";
	deque_int.push_back(42);
	list_int.push_back(42);
	try {
		easyfind(vect_int, to_find);
		easyfind(deque_int, to_find);
		easyfind(list_int, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}