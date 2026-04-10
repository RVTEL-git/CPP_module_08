#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class span
{
	private:
		const unsigned int		_capacity;
		std::vector<int>		_item;
	public:
		span(const unsigned int n);
		span(const span &rhs);
		span &operator=(const span &rhs);
		~span();
};

#endif