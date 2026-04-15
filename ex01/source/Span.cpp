#include <Span.hpp>
#include <algorithm>
#include <stdexcept>


span::span(const unsigned int n) : _capacity(n) {}

span::span(const span &rhs) : _capacity(rhs._capacity), _vector(rhs._vector) {}

span &span::operator=(const span &rhs){
	if (this != &rhs) {
		_capacity = rhs._capacity;
		_vector = rhs._vector;
	}
	return (*this);
}

span::~span() {}

unsigned int span::size(void)
{
	return (_vector.size());
}
std::vector<int>::iterator	span::begin(void)
{
	return (_vector.begin());
}
std::vector<int>::iterator	span::end(void)
{
	return (_vector.end());
}
std::vector<int>::const_iterator	span::begin(void) const
{
	return (_vector.begin());
}
std::vector<int>::const_iterator	span::end(void) const
{
	return (_vector.end());
}

void span::addNumber(int n) {
	if (_vector.size() >= _capacity)
		throw std::logic_error("Capacity exceeded");
	else
		_vector.insert(std::lower_bound(_vector.begin(), _vector.end(), n), n);
}

unsigned int span::shortestSpan()
{
	if (_vector.size() < 2)
		throw std::logic_error("Not enough elements");
	std::vector<int>::const_iterator it = _vector.begin();
	std::vector<int>::const_iterator neighbor = it + 1;
	unsigned int distance = 0;
	for (; neighbor != _vector.end(); ++it, ++neighbor) {
		unsigned int tmp = static_cast<unsigned int>(*neighbor - *it);
			if (it == _vector.begin() || tmp < distance)
				distance = tmp;
	}
	return (distance);
}

unsigned int span::longestSpan()
{
	if (_vector.size() < 2)
		throw std::logic_error("Not enough elements");
	return (static_cast<unsigned int>(*(end() - 1) - *begin()));
}

std::ostream &operator<<(std::ostream &out, const span &rhs) {
	std::vector<int>::const_iterator it;
	for (it = rhs.begin(); it != rhs.end() - 1; it++)
		out << *it << " - ";
	out << *(rhs.end() - 1) << std::endl;
	return (out);
}