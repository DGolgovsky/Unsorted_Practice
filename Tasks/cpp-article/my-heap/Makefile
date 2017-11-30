all: main.o increment1.o increment2.o
	g++ -o diff-flags main.o increment1.o increment2.o

main.o: main.cpp increment1.hpp increment2.hpp Counters.hpp
	g++ -c -O2 main.cpp

increment1.o: increment1.cpp Counters.hpp
	g++ -c $(CFLAGS) -O2 increment1.cpp

increment2.o: increment2.cpp Counters.hpp
	g++ -c -O2 increment2.cpp

clean:
	rm -f *.o diff-flags


