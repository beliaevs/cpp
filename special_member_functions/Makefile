all: copy.exe default.exe resource.exe move.exe howard_hinnant.exe

copy.exe: copy.cpp
	g++ -o copy.exe -Wall -Wpedantic -Wextra -std=c++17 copy.cpp

default.exe: default.cpp
	g++ -o default.exe -Wall -Wpedantic -Wextra -std=c++17 default.cpp

resource.exe: resource.cpp
	g++ -o resource.exe -Wall -Wpedantic -Wextra -std=c++17 resource.cpp

move.exe: move.cpp
	g++ -o move.exe -Wall -Wpedantic -Wextra -std=c++17 move.cpp

howard_hinnant.exe: howard_hinnant.cpp
	g++ -o howard_hinnant.exe -Wall -Wpedantic -Wextra -std=c++17 howard_hinnant.cpp

clean:
	rm default.exe copy.exe move.exe resource.exe howard_hinnant.exe
