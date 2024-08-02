#include<iostream>
#include<type_traits>

class A
{
    public:
    int n;
    double x;
};

class B
{
    public:
    B() = default;
    B(const B&) = delete;
    B(B&&) = delete;
    int n;
    double x;
};

class C
{
    public:
    C() = default;
    C(const C&) = delete;
    C(C&&) = delete;
    C& operator=(const C&) = default;
};

int main()
{
    std::cout << "A is trivial: " << std::is_trivial_v<A> << "\n";
    std::cout << "B is trivial: " << std::is_trivial_v<B> << "\n";
    std::cout << "C is trivial: " << std::is_trivial_v<C> << "\n";
    std::cout << "A is trivially copyable: " << std::is_trivially_copyable_v<A> << "\n";
    std::cout << "B is trivially copyable: " << std::is_trivially_copyable_v<B> << "\n";
    std::cout << "C is trivially copyable: " << std::is_trivially_copyable_v<C> << "\n";
    std::cout << "A is copy constructible: " << std::is_copy_constructible_v<A> << "\n";
    std::cout << "B is copy constructible: " << std::is_copy_constructible_v<B> << "\n";
    std::cout << "C is copy constructible: " << std::is_copy_constructible_v<C> << "\n";
    std::cout << "A is default constructible: " << std::is_default_constructible_v<A> << "\n";
    std::cout << "B is default constructible: " << std::is_default_constructible_v<B> << "\n";
    std::cout << "C is default constructible: " << std::is_default_constructible_v<C> << "\n";
    std::cout << "A is assignable:" << std::is_assignable_v<A, A> << "\n";
    std::cout << "B is assignable:" << std::is_assignable_v<B, B> << "\n";
    std::cout << "C is assignable:" << std::is_assignable_v<C, C> << "\n";
}