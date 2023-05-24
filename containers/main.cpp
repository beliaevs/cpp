#include<iostream>
#include<set>
#include<vector>
#include<deque>

int main()
{
    {
        std::set<int> s{1, 2, 3};
        auto b = s.begin();
        std::cout << *b << "\n";
        --b;
        std::cout << (s.end() == b) << "\n";
    }
    {
        std::set<int> s;
        auto b = s.begin();
        std::cout << (s.end() == b) << "\n";
        //--b;
        //std::cout << (s.end() == b) << "\n";
    }
    {
        std::vector<int> v{1, 2, 3};
        auto b = v.begin();
        std::cout << *b << "\n";
        --b;
        std::cout << (v.end() == b) << "\n";
    }
    {
        std::deque<int> d{2, 4, 6};
        auto b = d.begin();
        std::cout << *b << "\n";
        --b;
        std::cout << (d.end() == b) << "\n";
    }
}