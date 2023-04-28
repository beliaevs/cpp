#include<optional>
#include<iostream>

int main()
{
    std::optional<int> onum = 1;
    std::cout << "onum == 1? " << (onum == 1) << ", *onum == 1? " << (*onum == 1) << "\n";
    onum.reset();
    std::cout << "after reset():\n";
    std::cout << "onum == 1? " << (onum == 1) << ", *onum == 1? " << (*onum == 1) << "\n";
    return 0;
}