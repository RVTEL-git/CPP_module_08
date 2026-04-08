#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>


template <typename T>
void easyfind(T &cont, const int n) {
	
	typename T::iterator it = std::find(cont.begin(), cont.end(), n);
	if (it != cont.end()) {
		std::cout << "Element " << n << " found at position: " << std::distance(cont.begin(), it) << std::endl;
	}
	else {
		throw std::out_of_range("Element not found");
	}
}

#endif