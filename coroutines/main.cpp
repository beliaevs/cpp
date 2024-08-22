#include<iostream>

#include "chat.h"
#include "interleaved.h"

int main()
{
	std::cout << "Coroutine tests\n";

	run_chat();
	run_interleaved();

	return 0;
}
