#include<iostream>

int main()
{
    int a[] = {1, 4, 2, 5, 3, 6};
    {
        int* p = &a[1];
        std::cout << "a[1] = " << *p << "\n";
        ++p;
        std::cout << "a[2] = " << *p << "\n";
        *p = 100;
    }
    {
        int* const p = &a[3];
        std::cout << "a[3] = " << *p << "\n";
        // ++p; //  error: increment of read-only variable ‘p’
        // std::cout << "a[4] = " << *p << "\n"; 
        *p = 200;
    }
    {
        void* p = &a[0];
        // std::cout << *p << "\n"; //error: ‘void*’ is not a pointer-to-object type
        // clang error: arithmetic on a pointer to void
        // ++p; // g++ warning: ISO C++ forbids incrementing a pointer of type ‘void*’ [-Wpointer-arith]
        auto intp = static_cast<int*>(p);
        std::cout << *intp << "\n"; // 1
        //void* p5 = &a[5];
        //int count = 0;
        //while(p != p5)
        //{
        //    ++p; // shift by 1 byte in gcc, error in clang
        //    ++count;
        //}
        //std::cout << "diff: " << count << "\n";
        //clang error: arithmetic on pointers to void
        //std::cout << p5 - p << "\n"; // error: invalid use of ‘void’
    }
    {
        int* p1 = &a[1];
        int* p5 = &a[5];
        std::cout << p5 - p1 << "\n";
    }
    {
        unsigned int a = 10;
        unsigned int b = 20;
        auto c = a - b;
        std::cout << "10 - 20 = " << c << "\n"; // 10 - 20 = 4294967286
    }
    return 0;
}