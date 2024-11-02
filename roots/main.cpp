#include "dichotomy.h"
#include "newton.h"

#include<iostream>
#include<iomanip>

int main()
{
	auto f = [](double x) { return x * x - 2; };
	auto df = [](double x) {return 2 * x; };
	int dichotomyCount = 0;
	int newtonCount = 0;
	double root = findRoot(f, 0., 2., 1e-15, 0, &dichotomyCount);
	double rootNewton = findRoot(f, df, 1., 1e-16, 20, &newtonCount);

	std::cout << std::setprecision(20) << root << ", iterations:" << dichotomyCount << "\n";
	std::cout << std::setprecision(20) << rootNewton << ", iterations: " << newtonCount << "\n";

	return 0;
}