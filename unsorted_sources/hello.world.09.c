#include <stdio.h>

int main()
{
	char* h = "Hello, World!\n\0";
	for(;*h;putchar(*h++));
	return 0;
}

