#include<vector>
#include<set>
#include<iostream>

template<typename Cont>
concept HasPushBack = requires (Cont c, typename Cont::value_type e)
{
    c.push_back(e);
};

void add(HasPushBack auto& io_cont, const auto& el)
{
    io_cont.push_back(el);
}

void add(auto& io_cont, const auto& el)
{
    io_cont.insert(el);
}

int main()
{
    std::vector<int> vec;
    std::set<int> bag;

    add(vec, 3);
    add(bag, 5);

    std::cout << "vec: ";
    for(auto el: vec)
        std::cout << el << " ";
    std::cout << "\n";

    std::cout << "bag: ";
    for(auto el: bag)
        std::cout << el << " ";
    std::cout << "\n";

    return 0;
}