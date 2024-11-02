#pragma once

#include<cmath>

template<typename F, typename DF, typename T>
T findRoot(F f, DF df, T x0, T eps, int max_it = 0, int* it_count = nullptr)
{
	auto close = [](T a, T b, T eps) { return std::abs(b - a) < eps; };
	T y0 = f(x0);
	int count = 0;

	while (!close(0, y0, eps) && (max_it == 0 || count < max_it))
	{
		T delta = y0 / df(x0);
		T x = x0 - delta;

		if (close(x, x0, eps))
			return x0;

		x0 = x;
		y0 = f(x0);

		++count;
	}

	if (it_count)
		*it_count = count;

	return x0;
}
