#include <stdio.h>

int main()
{
    const char *hello = "Hello, world";
    char *ptr = hello;
    printf("%s\n", hello);
    for (; *ptr != '\0'; ++ptr)
        printf("%s\n", ptr);
    return 0;
}

