#include<iostream>

template<typename T> 
void use()
{
    T t; // default constructor and destructor
    T t2(t); // copy
    t2 = t2; // assignment
    T t3(std::move(t)); // move constructor
    t3 = std::move(t2); // move assignment
}

template<typename T>
void use_int()
{
    T t(10); // constructor from int and destructor
    T t2(t); // copy
    t2 = t2; // assignment
    T t3(std::move(t)); // move constructor
    t3 = std::move(t2); // move assignment
}

//everything is defaulted
class Defaulted
{
};

// any constructor
class AnyConstructor
{
    public:
    AnyConstructor(int){}
};

// only default
class DefaultConstructor
{
    public:
    DefaultConstructor(){}
};

// destructor
class Destructor
{
    public:
    ~Destructor(){}
};

class CopyConstructor
{
    public:
    CopyConstructor() = default; // no matching function for call to ‘CopyConstructor::CopyConstructor()
    CopyConstructor(const CopyConstructor&){}
};

class CopyAssignment
{
    public:
    CopyAssignment& operator=(const CopyAssignment&)
    { 
        return *this;
    }
};

class MoveConstructor
{
    public:
    MoveConstructor() = default; // error: no matching function for call to ‘MoveConstructor::MoveConstructor()’
    MoveConstructor(MoveConstructor&&){}
};

class MoveAssignment
{
    public:
    MoveAssignment& operator=(MoveAssignment&&)
    {
        return *this;
    }
};

int main()
{
    use<Defaulted>();
    // use<AnyConstructor>(); // no matching function for call to ‘AnyConstructor::AnyConstructor()
    use_int<AnyConstructor>();
    use<DefaultConstructor>();
    use<Destructor>(); // copy and assignment are available!
    use<CopyConstructor>(); 
    // warning: implicitly-declared ‘constexpr CopyConstructor& CopyConstructor::operator=(const CopyConstructor&)’ is deprecated 
    // because ‘CopyConstructor’ has user-provided ‘CopyConstructor::CopyConstructor(const CopyConstructor&)’
    use<CopyAssignment>();
    // warning: implicitly-declared ‘constexpr CopyAssignment::CopyAssignment(const CopyAssignment&)’ is deprecated 
    // because ‘CopyAssignment’ has user-provided ‘CopyAssignment& CopyAssignment::operator=(const CopyAssignment&)’
    // use<MoveConstructor>();
    // error: use of deleted function ‘constexpr MoveConstructor::MoveConstructor(const MoveConstructor&)’
    // error: use of deleted function ‘constexpr MoveConstructor& MoveConstructor::operator=(const MoveConstructor&)’
    // use<MoveAssignment>();
    // error: use of deleted function ‘constexpr MoveAssignment::MoveAssignment(const MoveAssignment&)’
    // error: use of deleted function ‘constexpr MoveAssignment& MoveAssignment::operator=(const MoveAssignment&)’
    return 0;
}