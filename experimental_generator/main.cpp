#include<iostream>
#include<experimental/generator>
#include<ranges>

std::experimental::generator<char> letters(char first)
{
	for (;; co_yield first++);
}


int main()
{
	for (const char c: letters('a') | std::views::take(26))
	{
		std::cout << c << " ";
	}
	std::cout << "\n";
	return 0;
}