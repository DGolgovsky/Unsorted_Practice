CC=g++

STD=-std=c++17
ERR=-Wall -Wextra -Wpedantic
CFLAGS=-I.

#SFML Example
LIBS=-lSDL2 -lGL -lGLU
OBJS=main.o
EXE=cube.bin

DEPS=

all: $(EXE)

clean:
	-rm $(EXE)
	-rm *.o

%.o: %.cpp $(DEPS) Makefile
	$(CC) $(STD) -g -O2 -c $(ERR) -o $@ $< $(CFLAGS)

$(EXE): $(OBJS) Makefile
	$(CC) -o $@ $(OBJS) $(LIBS)
	@echo 'Built executable:' $(EXE)

