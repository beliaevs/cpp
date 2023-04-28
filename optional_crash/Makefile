all: main.exe

main.exe: main.cpp
	g++ -std=c++17 -fsanitize=address -Wall -pedantic -Wextra -o main.exe main.cpp

clean:
	rm main.exe main_clang.exe

clang: main_clang.exe

main_clang.exe: main.cpp
	clang++ -std=c++17 -fsanitize=address -Wall -Wpedantic -Wextra -o main_clang.exe main.cpp

