#include<string>
#include<vector>
#include<iostream>

int GetX();
int GetY();

struct TestableObjectConstructor {
    int x;
    int y;

    int Transform() const {
        return x*x + y*y;
    }
};

template<typename T>
void Instantiate(const std::string& testsuite_name, const std::string& test_name, const T& object)
{
    std::cout << object;
}

#define INSTANTIATE_TEST_SUITE(testsuite_name, test_name, checked_object) \
    Instantiate("testsuite_##testsuite_name", "test_##test_name", checked_object);

int main()
{
    //std::string testsuite_name, test_name; // added
    //INSTANTIATE_TEST_SUITE(testsuite_name, test_name, []() {
    //    TestableObjectConstructor obj{.x = GetX(), .y = GetY()}; // comma in macro arguments
    //    return obj.Transform();
    //}() );

    return 0;
}