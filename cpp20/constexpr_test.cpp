#include "constexpr.h"

#include<vector>
#include<iostream>
#include<string>
#include<format>

consteval double mm2Meters(double len)
{
	return len / 1000.;
}

const double Len = mm2Meters(1000.);

void constexpr_test()
{
	double len = 10;
	double len1  = mm2Meters(10.);
	std::cout << std::format("{0}mm is {1}m\n", len, len1);
	//constexpr std::vector<int> v;
	//constexpr auto s = v.size();
	// constexpr std::string s = "sasha";
	//std::cout << s << "\n";
}
