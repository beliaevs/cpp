#include <iostream>
#include <limits>

template <typename T, typename O = T>
void show_add()
{
    const T a = std::numeric_limits<T>::max();
    std::cout << "a = " << O(a) << "\n";
    T sum = 0;
    bool res = __builtin_add_overflow(a, 1, &sum);
    std::cout << "a + 1 overflow? " << res << "\n";
    std::cout << "sum = " << O(sum) << "\n";
}

int main()
{
    show_add<char, int>();
    show_add<unsigned char, unsigned int>();
    show_add<short>();
    show_add<unsigned short>();
    show_add<int>();
    show_add<unsigned int>();
    show_add<long>();
    show_add<unsigned long>();
    show_add<long long>();
    show_add<unsigned long long>();

    return 0;
}