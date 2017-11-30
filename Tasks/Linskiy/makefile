main: main.o hello.o
	g++ main.o hello.o -o main
main.o: main.cpp hello.h
	g++ -c main.cpp
hello.o: hello.cpp
	g++ -c hello.cpp
clean:
	rm -rf *.o
