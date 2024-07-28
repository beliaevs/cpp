#include<iostream>
#include<string>
#include<memory>

class Resource
{
    public:
    explicit Resource(std::string i_name): name(std::move(i_name)){}
    std::string name;
};

class Holder
{
    public:
    Holder() = default;
    explicit Holder(std::string i_name): d_res(new Resource(std::move(i_name))){}
    Holder(const Holder& i_other): d_res(new Resource(*i_other.d_res) ) {}

    Holder(Holder&& i_other) = default;
    Holder& operator=(Holder&& i_rhs) = default;
    Holder& operator=(const Holder& i_rhs)
    {
        Holder tmp(i_rhs);
        return operator=(std::move(tmp));
    }

    void dump() const
    {
        std::cout << d_res->name << "\n";
    }

    private:
    std::unique_ptr<Resource> d_res;
};

int main()
{
    Holder h("hello");
    h.dump();
    Holder h1(h);
    h1.dump();
    Holder h2;
    h2 = h1;
    h2.dump();
    return 0;
}