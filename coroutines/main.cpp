#include<iostream>
#include<string_view>
#include "chat.h"
#include "interleaved.h"
#include "schedule.h"

void put_banner(std::string_view view)
{
	std::string sep(view.size(), '-');
	std::cout << sep << '\n' << view << '\n' << sep << std::endl;
}

int main()
{
	put_banner("Coroutine tests");
	put_banner("run_chat");
	run_chat();
	put_banner("run_interleaved");
	run_interleaved();
	put_banner("run_scheduler");
	run_scheduler();
	put_banner("done");
	return 0;
}
