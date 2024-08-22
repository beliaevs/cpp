#include<vector>
#include"movable.h"

int main()
{
	std::initializer_list<int> args = {1, 2, 3};
	{
		std::vector<Movable> v;
		v.reserve(3);
		for (auto n : args)
			v.emplace_back(n);
		v.emplace_back(4);
	}
	{
		std::vector<NonMovable> v;
		v.reserve(3);
		for (auto n : args)
			v.emplace_back(n);
		v.emplace_back(4);
	}
	return 0;
}