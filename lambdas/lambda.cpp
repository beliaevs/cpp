#include<iostream>

int main()
{
    auto f = [](int n){ std::cout << "f(" << n << ")\n"; };

    f(101);

    auto *g = +[](int n){ std::cout << "g(" << n << ")\n"; };
    (*g)(42);
}