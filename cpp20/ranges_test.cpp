#include "ranges_test.h"

#include<iostream>
#include<vector>
#include<ranges>
#include<string>

void dump(auto v)
{
	for (auto&& e : v)
		std::cout << e << " ";
	std::cout << "\n";
}

void ranges_test()
{
	using namespace std;
	vector v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	auto result{ v | views::filter([](auto e) { return e % 2 == 1; })
				   | views::transform([](auto e) { return 2.0 * e; }) 
	               | views::drop(2) 
	               | views::reverse
				   | views::transform([](auto e) { return to_string(e); }) };

	dump(result);
}