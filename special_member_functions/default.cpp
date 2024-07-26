#include<iostream>

template<typename Widget>
void dump(const Widget& w)
{
    std::cout << w.n << ", " << w.next << "\n";
}

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

class GoodWidget
{
    public:
    GoodWidget() = default;

    int n;
    GoodWidget* next;
};

int main()
{
    Widget w1; // n, next - uninitialized
    dump(w1);

    Widget w2{}; // n == 0, next == nullptr
    dump(w2);
    
    BadWidget w3{}; // n, next - uninitialized
    dump(w3);

    GoodWidget w4; // n, next - uninitialized
    dump(w4);

    GoodWidget w5{}; // n == 0, next == nullptr
    dump(w5);
    
    return 0;
}