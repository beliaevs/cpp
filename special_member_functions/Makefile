all: copy.exe default.exe resource.exe

copy.exe: copy.cpp
	g++ -o copy.exe -Wall -Wpedantic -Wextra -std=c++17 copy.cpp

default.exe: default.cpp
	g++ -o default.exe -Wall -Wpedantic -Wextra -std=c++17 default.cpp

resource.exe: resource.cpp
	g++ -o resource.exe -Wall -Wpedantic -Wextra -std=c++17 resource.cpp

clean:
	rm default.exe copy.exe
