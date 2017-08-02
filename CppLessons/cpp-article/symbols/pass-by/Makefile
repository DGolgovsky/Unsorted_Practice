pass-by: by-value.o by-reference.o by-pointer.o main.o
	g++ -o pass-by by-value.o by-reference.o by-pointer.o main.o

main.o: main.cpp by-value.hpp by-reference.hpp by-pointer.hpp
	g++ -c  main.cpp

by-pointer.o: by-pointer.cpp
	g++ -c by-pointer.cpp

by-reference.o: by-reference.cpp
	g++ -c by-reference.cpp

by-value.o: by-value.cpp
	g++ -c by-value.cpp

clean:
	rm -f *.o pass-by

