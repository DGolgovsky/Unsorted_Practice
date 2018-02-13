CC=g++

STD=-std=c++17
ERR=-Wall -Wextra -Wpedantic -Weffc++
ARGS=-fstack-protector-strong -pipe -no-pie -march=native
CFLAGS=-I. 

#SFML Example
LIBS=-lstdc++fs
OBJS=main.o
EXE=d_tube.x64

DEPS=

all: $(EXE)

clean:
	-rm $(EXE)
	-rm *.o

%.o: %.cpp $(DEPS) Makefile
	$(CC) $(STD) -g -O2 -c $(ERR) $(ARGS) -o $@ $< $(CFLAGS)

$(EXE): $(OBJS) Makefile
	$(CC) -o $@ $(OBJS) $(LIBS)
	@echo 'Built executable:' $(EXE)

