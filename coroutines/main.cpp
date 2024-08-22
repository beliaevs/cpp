#include<iostream>

#include "chat.h"
#include "interleaved.h"

int main()
{
	std::cout << "Coroutine tests\n";
	std::string sep = "------------------\n";
	run_chat();
	std::cout << sep;
	run_interleaved();

	return 0;
}
