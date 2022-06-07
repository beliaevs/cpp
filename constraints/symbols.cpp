#include<cmath>

double k(double x);

int f(int a)
{
    return a+1;
}

int g(double b)
{
    return static_cast<int>(b);
}

double h(double x)
{
    return k(x)/2.;
}

double i(double x)
{
    return std::sqrt(x) +1.;
}