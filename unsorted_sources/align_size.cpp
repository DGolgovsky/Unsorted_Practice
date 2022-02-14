#include <stdio.h>

class Foo {
    int a;
    char b;
    int c;
    char d;
};

class Bar {
    int a;
    int c;
    char b;
    char d;
};

int main() 
{
    printf( "%u - %u\n", sizeof(Foo), sizeof(Bar) );
	// Program returned: 16 - 12 (x64)
	
    return 0;
}

