# from http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC=g++
CFLAGS=-I.
OBJS=main.o worker1.o worker2.o worker3.o worker4.o
EXE=constfloat

DEPS=

all: $(EXE)

clean:
	rm $(EXE)
	rm *.o

%.o: %.cpp $(DEPS) makefile
	$(CC) -g -c -Wall -o $@ $< $(CFLAGS)

$(EXE): $(OBJS) makefile
	$(CC) -o $@ $(OBJS)
	@echo 'Built executable "constfloat"'
