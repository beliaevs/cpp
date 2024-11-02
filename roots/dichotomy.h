#pragma once

#include<cmath>
#include<stdexcept>

template<typename F, typename T>
T findRoot(F f, T a, T b, T eps, int max_it = 0, int* it_count = nullptr)
{
	constexpr T zero = T(0);
	auto middle = [](T a, T b) { return (a + b) * T(0.5); };
	auto close = [](T a, T b, T eps) { return std::abs(b - a) < eps; };
	auto opposite = [](T a, T b) { return a < zero && b > zero || a > zero && b < zero; };

	T fa = f(a);
	T fb = f(b);

	if (close(0, fa, eps))
		return a;

	if (close(0, fb, eps))
		return b;

	if (!opposite(fa, fb))
		throw std::logic_error("f has values of the same sign");

	int count = 0;

	while (!close(a, b, eps) && (max_it == 0 || count < max_it))
	{
		T m = middle(a, b);
		T fm = f(m);

		if (close(0, fm, eps))
		{
			if (it_count)
				*it_count = count;

			return m;
		}
		if(opposite(fa, fm))
		{
			b = m;
		}
		else
		{
			a = m;
		}
		++count;
	}

	if (it_count)
		*it_count = count;

	return middle(a, b);
}