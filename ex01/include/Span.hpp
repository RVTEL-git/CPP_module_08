#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class span
{
	private:
		unsigned int			_capacity;
		std::vector<int>		_vector;
	public:
		span(const unsigned int n);
		span(const span &rhs);
		span &operator=(const span &rhs);
		~span(void);

		unsigned int size(void);
		std::vector<int>::iterator			begin(void);
		std::vector<int>::const_iterator	begin(void) const;
		std::vector<int>::iterator			end(void);
		std::vector<int>::const_iterator	end(void) const;

		void addNumber(int num);
		template <typename T>
		void addNumbers(T first, T end) {
			try {
				for (T it = first; it != end; it++)
					addNumber(*it);
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
		}


		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
};

std::ostream &operator<<(std::ostream &out, const span &rhs);

#endif