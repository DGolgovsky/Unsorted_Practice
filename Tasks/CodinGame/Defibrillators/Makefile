all: bin

bin: main.o Defibrillator.o Point.o
	g++ -Wall -Wextra -std=c++17 main.o Defibrillator.o Point.o -o defib.bin
	
main.o: main.cpp
	g++ -Wall -Wextra -std=c++17 -c main.cpp

Defibrillator.o: Defibrillator.cpp Defibrillator.h
	g++ -Wall -Wextra -std=c++17 -c Defibrillator.cpp

Point.o: Point.cpp Point.h
	g++ -Wall -Wextra -std=c++17 -c Point.cpp

clean:
	-rm *o defib.bin


