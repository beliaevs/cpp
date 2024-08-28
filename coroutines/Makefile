CPP=g++
CPPFLAGS=-std=c++20 -fcoroutines -Wall -Wpedantic -Wextra
SOURCES=main.cpp schedule.cpp interleaved.cpp chat.cpp
HEADERS=chat.h interleaved.h schedule.h
OBJS=main.o schedule.o interleaved.o chat.o

coroutines.exe: $(OBJS)
	$(CPP) -o coroutines.exe $(OBJS)

main.o: main.cpp $(HEADERS)
	$(CPP) -c $(CPPFLAGS) main.cpp

interleaved.o: interleaved.cpp interleaved.h 
	$(CPP) -c $(CPPFLAGS) interleaved.cpp

chat.o: chat.cpp chat.h 
	$(CPP) -c $(CPPFLAGS) chat.cpp

schedule.o: schedule.cpp schedule.h 
	$(CPP) -c $(CPPFLAGS) schedule.cpp

clean:
	rm -f $(OBJS) coroutines.exe
