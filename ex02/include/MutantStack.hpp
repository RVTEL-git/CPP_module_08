#pragma once

#include <stack>
#include <list>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() {};
		MutantStack(const MutantStack &rhs) : std::stack<T>(rhs) { };
		~MutantStack() { };
		MutantStack &operator=(const MutantStack &rhs);
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
};

#include <MutantStack.tpp>