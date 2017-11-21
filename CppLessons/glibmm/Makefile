CC=g++

STD=-std=c++17
ERR=-Wall -Wextra -Wpedantic
ARGS=-fstack-protector-strong -pipe -no-pie -march=native
CFLAGS=-I. 

LIBS=`pkg-config --cflags --libs giomm-2.4`

OBJS=main.o
EXE=notification

DEPS=

all: $(EXE)

clean:
	-rm $(EXE)
	-rm *.o

%.o: %.cpp $(DEPS) Makefile
	$(CC) $(STD) -g -O2 -c $(ERR) $(LIBS) $(ARGS) -o $@ $< $(CFLAGS)

$(EXE): $(OBJS) Makefile
	$(CC) -o $@ $(OBJS) $(LIBS) $(ARGS)
	@echo 'Built executable:' $(EXE)

