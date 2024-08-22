#include "interleaved.h"
#include <coroutine>
#include <vector>
#include <iostream>

struct Generator
{
	struct sentinel {};

	struct promise_type
	{
		int val{};

		Generator get_return_object() { return Generator(this); }
		std::suspend_never initial_suspend() noexcept { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		std::suspend_always yield_value(int v)
		{
			val = v;
			return {};
		}
		void return_void() noexcept {}
		void unhandled_exception() {}
	};

	using Handle = std::coroutine_handle<promise_type>;
	Handle mCoroHdl{};

	explicit Generator(promise_type* p): mCoroHdl{ Handle::from_promise(*p) }{}
	Generator(Generator&& rhs) : mCoroHdl{ std::exchange(rhs.mCoroHdl, nullptr) } {}
	~Generator()
	{
		if (mCoroHdl) { mCoroHdl.destroy(); }
	}
	int value() const { return mCoroHdl.promise().val; }
	bool finished() const { return mCoroHdl.done(); }
	void resume()
	{
		if (not finished())
			mCoroHdl.resume();
	}

	struct iterator
	{
		Handle mCoroHdl;
		bool operator==(sentinel) const
		{
			return mCoroHdl.done();
		}
		iterator& operator++()
		{
			mCoroHdl.resume();
			return *this;
		}
		int operator*() const
		{
			return mCoroHdl.promise().val;
		}
	};

	iterator begin() { return {mCoroHdl}; }
	sentinel end() { return {}; }


};

Generator interleaved(std::vector<int> a, std::vector<int> b)
{
	auto lamb = [](std::vector<int>& v) -> Generator
		{
			for (const auto& e : v) { co_yield e; }
		};

	auto x = lamb(a);
	auto y = lamb(b);

	while (not x.finished() or not y.finished())
	{
		if (not x.finished())
		{
			co_yield x.value();
			x.resume();
		}

		if (not y.finished())
		{
			co_yield y.value();
			y.resume();
		}
	}
}

void run_interleaved()
{
	std::cout << "run_interleaved()\n";
	auto gen = interleaved({1, 2, 3, 4, 5}, {6, 7, 8});

	for (auto e: gen)
	{
		std::cout << e << "\n";
	}
}