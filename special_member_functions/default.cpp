#include<iostream>

class Widget
{
    public:
    int n;
    Widget* next;
};

class BadWidget
{
    public:
    BadWidget() {}

    int n;
    BadWidget* next;
};

int main()
{
    Widget w1; // n, next - uninitialized
    std::cout << w1.n << ", " << w1.next << "\n";

    Widget w2{}; // n == 0, next == nullptr
    std::cout << w2.n << ", " << w2.next << "\n";
    
    BadWidget w3{}; // n, next - uninitialized
    std::cout << w3.n << ", " << w3.next << "\n";

    return 0;
}