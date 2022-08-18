#include<memory>


class DefaultedCopy
{
    public:
    DefaultedCopy() = default;
    DefaultedCopy(const DefaultedCopy&) = default;
    std::unique_ptr<int> d_holder;
};

int main()
{
    DefaultedCopy x;
    return 0;
}