#include<iostream>

template<typename Widget>
void dump(const Widget& w)
{
    std::cout << w.n << ", " << w.next << "\n";
}

class Widget
{
public:
    Widget() = default;
    Widget(Widget&& other){}
    int n;
    Widget* next;
};

class Widget1
{
public:
    Widget1() = default;
    Widget1(const Widget1&){}
};

int main()
{
    {
        Widget w1{};
        //Widget w2(w1); // error: copy constructor is implicitly declared as deleted
        dump(w1);
    }
    {
        Widget1 w; // no default constructor if no Widget1() = default;
    }
    return 0;
}