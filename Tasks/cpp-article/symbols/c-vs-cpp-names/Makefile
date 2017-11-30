all: cpp-app c-app
	nm sum.o print.o
	nm -C print.o c-main.o cpp-main.o c-app cpp-app

cpp-app: cpp-main.o print.o sum.o
	g++ -o cpp-app cpp-main.o print.o sum.o


c-app: c-main.o print.o sum.o
	g++ -o c-app c-main.o print.o sum.o

cpp-main.o: cpp-main.cpp print.hpp sum.h
	g++ -c cpp-main.cpp

c-main.o: c-main.c print.hpp sum.h
	gcc -c c-main.c

print.o: print.cpp
	g++ -c print.cpp

sum.o: sum.c
	gcc -c sum.c

clean:
	rm -f *.o cpp-app c-app

