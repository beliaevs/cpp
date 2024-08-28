#include "coroutine.h"
#include<coroutine>
#include<iostream>

struct ReturnType
{
	struct promise_type
	{
		ReturnType get_return_object() { return {}; }
		std::suspend_always initial_suspend() 
		{
			std::cout << "hello from coro!\n";
			return {}; 
		}
		std::suspend_always final_suspend() noexcept { return {}; }
		void return_void() {}
		void unhandled_exception() {}
	};
};

ReturnType f()
{
	co_return;
}

void coroutine_test()
{
	auto r = f();
}