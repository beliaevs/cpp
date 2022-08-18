main.exe: main.cpp Makefile
	g++ -std=c++17 -o main.exe -Wall -pedantic -Wextra main.cpp

clean:
	rm main.exe main_clang.exe

clang: main_clang.exe

gcc: main.exe

main_clang.exe: main.cpp Makefile
	clang++ -std=c++17 -o main_clang.exe main.cpp