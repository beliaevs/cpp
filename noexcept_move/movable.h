#pragma once

#include<iostream>

class Movable
{
public:
	explicit Movable(int n) : n_(n) { std::cout << "Movable created(" << n_ << ")\n"; }
	Movable(const Movable& other) : n_(other.n_) { std::cout << "Movable copied(" << n_ << ")\n"; }
	Movable& operator=(const Movable& rhs) 
	{
		n_ = rhs.n_;
		std::cout << "Movable copy-assigned(" << n_ << ")\n";
		return *this; 
	}
	Movable(Movable&& other) noexcept : n_(other.n_) { std::cout << "Movable moved(" << n_ << ")\n"; other.n_ = -1; }
	Movable& operator=(Movable&& rhs)
	{
		n_ = rhs.n_;
		rhs.n_ = -1;
		std::cout << "Movable move-assigned(" << n_ << ")\n";
		return *this;
	}
	~Movable() noexcept
	{
		std::cout << "Movable destroyed(" << n_ << ")\n";
	}
private:
	int n_;
};

class NonMovable
{
public:
	explicit NonMovable(int n) : n_(n) { std::cout << "NonMovable created(" << n_ << ")\n"; }
	NonMovable(const NonMovable& other) : n_(other.n_) { std::cout << "NonMovable copied(" << n_ << ")\n"; }
	NonMovable& operator=(const NonMovable& rhs)
	{
		n_ = rhs.n_;
		std::cout << "NonMovable copy-assigned(" << n_ << ")\n";
		return *this;
	}
	NonMovable(NonMovable&& other) : n_(other.n_) { std::cout << "NonMovable moved(" << n_ << ")\n"; other.n_ = -1; }
	NonMovable& operator=(NonMovable&& rhs)
	{
		n_ = rhs.n_;
		rhs.n_ = -1;
		std::cout << "NonMovable move-assigned(" << n_ << ")\n";
	}
	~NonMovable() noexcept
	{
		std::cout << "NonMovable destroyed(" << n_ << ")\n";
	}
private:
	int n_;
};


