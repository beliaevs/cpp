#include<vector>
#include"movable.h"

int main()
{
	std::initializer_list<int> args = {1, 2, 3};
	{
		std::vector<Movable> v;
		v.reserve(3);
		for (auto n : args)
			v.emplace_back(n); // elements are constructed in-place
		std::cout << "extra emplace_back\n";
		v.emplace_back(4); // new buffer is allocated
		// new element is constructed in-place
		// other elements are moved to new buffer
		// moved-from buffer is destroyed
		std::cout << "extra push_back\n";
		v.push_back(Movable(5)); // new temporary element is created
		// new buffer is allocated
		// temporary is moved into new buffer
		// other elements are moved into new buffer
		// moved-from buffer is destroyed
		// vector is destroyed
	}
	{
		std::vector<NonMovable> v;
		v.reserve(3);
		for (auto n : args)
			v.emplace_back(n); // elements are constructed in-place
		std::cout << "extra emplace_back\n";
		v.emplace_back(4); // new buffer is allocated
		// new element is constructed in-place
		// other elements are *copied* to new buffer
		// old buffer is destroyed
		std::cout << "extra push_back\n";
		v.push_back(NonMovable(5)); // temporary element is created
		// new buffer is allocated
		// temporary is moved into new buffer
		// other elements are copied into new buffer
		// old buffer is destroyed
		// vector is destroyed
	}
	return 0;
}