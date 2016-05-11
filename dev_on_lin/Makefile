all: exe lib

exe: hello.h main.c lib
	gcc main.c -fPIC -ldl -o hello

lib: hello.h hello.c
	gcc -shared hello.c -fPIC -o libHello.so

clean:
	-rm *.o libHello.so 2>/dev/null

