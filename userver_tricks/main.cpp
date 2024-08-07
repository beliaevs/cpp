#include<iostream>

class A
{
public:
	static A create(int id) {
		return A(id); // c++14 'A::A(A &&)': attempting to reference a deleted function
		// c++17 - OK
	}
	~A() = default;

	void hi() const {
		std::cout << "hi from " << id_ << "!\n";
	}

	int getId() const {
		return id_;
	}

private:
	A(int n): id_(n) {}
	A() = delete;
	A(const A&) = delete;
	A(A&&) = delete;
	A& operator=(const A&) = delete;
	A& operator=(A&&) = delete;
	int id_;
};

// function chains
A&& h(A&& a)
{
	std::cout << "h is skipping " << a.getId() << "\n";
	return std::move(a);
}

void g(A&& a)
{
	std::cout << a.getId() << " from g\n";
}

void f(A&& a)
{
	std::cout << a.getId() << " from f\n";
	g(std::move(a));
}


int main()
{
	A a = A::create(123);
	a.hi();

	{
		f(A::create(456));
		f(h(A::create(789)));
	}

	{
		// A a = h(A::create(135)); // error C2280: 'A::A(A &&)': attempting to reference a deleted function
	}
	return 0;
}