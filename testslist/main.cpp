#include<forward_list>
#include<string>
#include<string_view>
#include<iostream>
#include "testlist.h"

class TestElement
{
public:
	std::string name;

	TestElement(): name("anonymous") {}
	
	~TestElement()
	{
		std::cout << "~Test(" << name << ")\n";
	}

	TestElement(const TestElement& other) : name(other.name)
	{
		std::cout << "copy " << name << "\n";
	}

	TestElement(TestElement&& other) : name(std::move(other.name))
	{
		std::cout << "move " << name << "\n";
	}

	TestElement& operator=(const TestElement& rhs)
	{
		std::cout << "assign " << rhs.name << " to " << name << "\n";
		name = rhs.name;
		return *this;
	}

	TestElement& operator=(TestElement&& rhs)
	{
		std::cout << "move assign " << rhs.name << " to " << name << "\n";
		name = std::move(rhs.name);
		return *this;
	}

	explicit TestElement(std::string_view sw): name(sw)
	{}
};

TestList<int> getList()
{
	TestList<int> res;
	res.push_front(1);
	res.push_front(2);
	return res;
}

template<typename Cont>
void show(const Cont& i_cont)
{
	for (const auto& e : i_cont)
	{
		std::cout << e << " ";
	}
	std::cout << "\n";
}

int main()
{
	{
		// testing TestElement
		TestElement t1;
		TestElement t2{ t1 };
		TestElement t3("hi there");
		TestElement t4("so fun");
		t4 = t3;
		t3 = []() { return TestElement("from lambda"); }();
	}
	{
		std::forward_list<TestElement> l;
		const bool res1 = (l.begin() == l.end());
		std::cout << res1 << "\n";

		l.push_front(TestElement("head"));
		l.emplace_front("new head");
	}
	{
		std::cout << "\npush_front for special class\n";
		TestList<TestElement> listEl;
		listEl.push_front(TestElement("sasha"));
		listEl.push_front(TestElement("pasha"));
		listEl.emplace_front("dasha");

		for (const auto& e : listEl)
		{
			std::cout << e.name << "\n";
		}
	}
	{
		std::cout << "\npush front test\n";
		TestList<int> listInt;

		for (int i = 0; i != 10; ++i)
		{
			listInt.push_front(i);
		}

		show(listInt);
	}
	{
		std::cout << "\nswaps test\n";
		TestList<int> list1;
		list1.push_front(1);
		list1.push_front(2);

		TestList<int> list2;
		list2.push_front(3);
		list2.push_front(4);

		list1.swap(list2);
		show(list1);
		show(list2);
		
		list1 = list2;
		show(list1);
	}
	{
		std::cout << "\nmove constructions\n";
		TestList<int> a;
		a = getList();

		TestList<int> b(std::move(a));
		TestList<int> c(b);

		TestList<int> d;
		d = c;
	}
	{
		std::cout << "\nList from initializer_list\n";
		TestList<int> a{2, 3, 4, 5, 6, 7, 8, 9};
		show(a);

		TestList<int> b(a);
		show(b);

		for (auto& e : b)
		{
			++e;
		}
		show(b);
		b.reverse();
		show(b);
	}
	return 0;
}

