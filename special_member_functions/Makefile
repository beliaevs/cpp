all: copy.exe default.exe

copy.exe: copy.cpp
	g++ -o copy.exe -Wall -Wpedantic -Wextra -std=c++17 copy.cpp

default.exe: default.cpp
	g++ -o default.exe -Wall -Wpedantic -Wextra -std=c++17 default.cpp

clean:
	rm default.exe copy.exe
