#include <Span.hpp>
#include <cassert>
#include <iostream>

void test_constructor() {
	std::cout << "Testing constructor..." << std::endl;
	span s(5);
	assert(s.size() == 0);
	std::cout << "✓ Constructor test passed" << std::endl;
}

void test_addNumber() {
	std::cout << "Testing addNumber..." << std::endl;
	span s(5);
	s.addNumber(10);
	s.addNumber(20);
	s.addNumber(30);
	assert(s.size() == 3);
	std::cout << "✓ addNumber test passed" << std::endl;
}

void test_addNumber_overflow() {
	std::cout << "Testing addNumber overflow..." << std::endl;
	span s(2);
	s.addNumber(10);
	s.addNumber(20);
	try {
		s.addNumber(30);
		assert(false);
	} catch (const std::logic_error &e) {
		std::cout << "✓ addNumber overflow test passed" << std::endl;
	}
}

void test_shortestSpan() {
	std::cout << "Testing shortestSpan..." << std::endl;
	span s(5);
	s.addNumber(6);
	s.addNumber(3);
	s.addNumber(17);
	s.addNumber(9);
	s.addNumber(11);
	unsigned int shortest = s.shortestSpan();
	assert(shortest == 2);
	std::cout << "✓ shortestSpan test passed" << std::endl;
}

void test_longestSpan() {
	std::cout << "Testing longestSpan..." << std::endl;
	span s(5);
	s.addNumber(6);
	s.addNumber(3);
	s.addNumber(17);
	s.addNumber(9);
	s.addNumber(11);
	unsigned int longest = s.longestSpan();
	std::cout << longest << std::endl;
	assert(longest == 14);
	std::cout << "✓ longestSpan test passed" << std::endl;
}

void test_shortestSpan_insufficient_elements() {
	std::cout << "Testing shortestSpan with insufficient elements..." << std::endl;
	span s(5);
	s.addNumber(10);
	try {
		s.shortestSpan();
		assert(false);
	} catch (const std::logic_error &e) {
		std::cout << "✓ shortestSpan insufficient elements test passed" << std::endl;
	}
}

void test_longestSpan_insufficient_elements() {
	std::cout << "Testing longestSpan with insufficient elements..." << std::endl;
	span s(5);
	s.addNumber(10);
	try {
		s.longestSpan();
		assert(false);
	} catch (const std::logic_error &e) {
		std::cout << "✓ longestSpan insufficient elements test passed" << std::endl;
	}
}

void test_copy_constructor() {
	std::cout << "Testing copy constructor..." << std::endl;
	span s1(5);
	s1.addNumber(10);
	s1.addNumber(20);
	span s2(s1);
	std::cout << s2.size() << std::endl;
	assert(s2.size() == 2);
	std::cout << "✓ Copy constructor test passed" << std::endl;
}

void test_operator_assignment() {
	std::cout << "Testing operator assignment..." << std::endl;
	span s1(5);
	s1.addNumber(10);
	s1.addNumber(20);
	span s2(3);
	s2 = s1;
	assert(s2.size() == 2);
	std::cout << "✓ Operator assignment test passed" << std::endl;
}

void test_operator_output() {
	std::cout << "Testing operator<<..." << std::endl;
	span s(3);
	s.addNumber(5);
	s.addNumber(10);
	s.addNumber(15);
	std::cout << "Output: ";
	std::cout << s;
	std::cout << "✓ Operator<< test passed" << std::endl;
}

void test_addNumbers_large() {
	std::cout << "Testing addNumbers with 1200 elements..." << std::endl;
	span s(1500);

	std::vector<int> numbers;
	for (int i = 0; i < 1200; i++)
		numbers.push_back(i);

	s.addNumbers(numbers.begin(), numbers.end());

	assert(s.size() == 1200);
	assert(s.shortestSpan() == 1);
	assert(s.longestSpan() == 1199);
	std::cout << "  Shortest span: " << s.shortestSpan() << std::endl;
	std::cout << "  Longest span: " << s.longestSpan() << std::endl;
	std::cout << "✓ addNumbers test with 1200 elements passed" << std::endl;
}

int main(void)
{
	try {
		test_constructor();
		test_addNumber();
		test_addNumber_overflow();
		test_shortestSpan();
		test_longestSpan();
		test_shortestSpan_insufficient_elements();
		test_longestSpan_insufficient_elements();
		test_copy_constructor();
		test_operator_assignment();
		test_operator_output();
		test_addNumbers_large();
		std::cout << "\n✅ All tests passed!" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "❌ Test failed: " << e.what() << std::endl;
	}
	
	return (0);
}