#include "concepts_test.h"
#include<iostream>

template<typename T>
concept Incrementable = requires(T x)
{ 
	{ ++x } noexcept;
	{ x++ } noexcept;
	{ ++x } -> std::convertible_to<T>;
	{ x++ } -> std::same_as<T>;
};

int foo(Incrementable auto t)
{
	int res = 0;
	while (++t)
		++res;

	return res;
}

class Bar {};

int plain_foo(auto t)
{
	int res = 0;
	while (++t)
		++res;

	return res;
}

void concepts_test()
{
	std::cout << foo(-10) << "\n";
	//std::cout << foo(Bar{}) << "\n";
	//std::cout << plain_foo(Bar{}) << "\n";
}