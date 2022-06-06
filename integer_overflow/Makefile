all: overflow.exe

overflow.exe: overflow.cpp Makefile
	g++ -o $@ -std=c++17 -Wall -Wpedantic -Wextra $<

clean:
	rm overflow.exe
	