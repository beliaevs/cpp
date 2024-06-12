#include<iostream>
#include<boost/type_index.hpp>

int main()
{
    {// reftest
        auto p = std::pair(1., 2);
        auto& e = p;
        std::cout << "typeid(e.first): " << boost::typeindex::type_id_with_cvr<decltype(e.first)>().pretty_name() << "\n";
    }
    { 
        // structured bindings and CTAD
        // auto [a, b] = std::pair(2., 3);
        // is equivalent to:
        // auto e = std::pair(2., 3);
        // alias a = e.first;
        // alias b = e.second;
        auto p = std::pair(2., 3);
        auto& [a, b] = p;
        std::cout << "typeid(a): " << boost::typeindex::type_id_with_cvr<decltype(a)>().pretty_name() 
        << ", typeid(b): " << boost::typeindex::type_id_with_cvr<decltype(b)>().pretty_name() << "\n";
        std::cout << "a=" << a << ", b=" << b << "\n";
    }
    return 0;
}