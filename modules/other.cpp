module;

#include<iostream>

export module other;

export namespace other
{
    void call()
    {
        std::cout << "other::call\n";
    }
}