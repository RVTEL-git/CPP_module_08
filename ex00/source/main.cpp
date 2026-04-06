#include <iostream>
#include <algorithm>
#include <vector>

#include <cstddef>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	const long max_rand = 1000000L;
	double lower_bound = 0;
	double upper_bound = 100;

	std::vector<int> vect_int;
	for (int i = 0; i < 3; i++)
	{
		int random_int = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
		vect_int.push_back(random_int);
	}
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite = vect_int.end();
	for (it = vect_int.begin(); it != ite; ++it)
		std::cout << *it << std::endl;
	std::cout << "=====" << std::endl;
	std::vector<double> vect_double;
	vect_double.push_back(3.003);
	int test = 3;
	for (int i = 0; i < 3; i++)
	{
		double random_double = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
		vect_double.push_back(random_double);
	}
	std::vector<double>::iterator dit;
	std::vector<double>::iterator dite = vect_double.end();
	for (dit = vect_double.begin(); dit != dite; ++dit) {
		if (test == *dit)
			std::cout << "yes" << std::endl;
		std::cout << *dit << std::endl;
	}
	std::cout << "=====" << std::endl;
	std::vector<float> vect_float;
	vect_float.push_back(3.003);
	for (int i = 0; i < 3; i++)
	{
		float random_float = lower_bound + (upper_bound - lower_bound) * (rand() % max_rand) / max_rand;
		vect_float.push_back(random_float);
	}
	std::vector<float>::iterator fit;
	std::vector<float>::iterator fite = vect_float.end();
	for (fit = vect_float.begin(); fit != fite; ++fit) {
		if (test == *fit)
			std::cout << "yes" << std::endl;
		std::cout << *fit << std::endl;
	}
	std::cout << "=====" << std::endl;
	return (0);
}