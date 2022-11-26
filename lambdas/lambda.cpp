#include<iostream>
#include<string>

int main()
{
    {
        std::cout << "Lambda to function pointer conversion\n";
        auto f = [](int n){ std::cout << "f(" << n << ")\n"; };
        f(101);
        // strange conversion from lambda to function pointer
        auto *g = +[](int n){ std::cout << "g(" << n << ")\n"; };
        g(42);
    }
    
    {
        std::cout << "immediate lambda invocation\n";
        //immediate lambda invocation
        const std::string name = [](){ std::string in; std::cin >> in; return in; }();
        std::cout << name << "\n";
    }
    {
        std::cout << "modification of captured variables\n";
        // modification of captured variables
        int n = 21;
        auto f = [&n](){ ++n; };
        f();
        auto g = [n]() mutable { ++n; std::cout << n << "\n"; };
        for(int i = 0; i < 5; ++i)
            g();
        std::cout << n << "\n";
    }
    {
        std::cout << "captures\n";
        // what do we need to capture?
        // static - no
        static int n = 42;
        auto f = [](){ std::cout << n << "\n"; };
        f();
        // constexpr - no
        constexpr int m = 56;
        auto g = [](){ std::cout << m << "\n"; };
        g();
        // simply const - yes
        int p = 500;
        const int k = p;
        //auto h = [](){ std::cout << k << "\n";}; // error: "k" is not captured
        auto h = [k](){ std::cout << k << "\n";}; // error: "k" is not captured
        h();
        const double u = 2.345;
        //auto i = [](){ std:: cout << u << "\n"; }; // floating-point constants should be captured 
        auto i = [u](){ std:: cout << u << "\n"; };
        i();
    }
}