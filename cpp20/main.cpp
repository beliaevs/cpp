#include<iostream>
#include "ranges_test.h"
// spaceship operator
struct Comp
{
	int a;
	double b;
	char c;
	constexpr std::partial_ordering operator<=>(const Comp& rhs) const = default;
};



int main()
{
	std::cout << "cpp20 features test\n";
	Comp c1{ 1, 0., 'a' };
	Comp c2{ 1, 0., 'b' };

	std::cout << (c1 < c2) << ", " << (c1 > c2) << ", " << (c1 == c2) << "\n";

	ranges_test();

	return 0;
}