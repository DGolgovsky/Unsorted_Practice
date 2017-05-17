#include <stdio.h>

void print(const char *str)
{
    printf("log: %s\n", str);
}

void print(int i)
{
    printf("log: %d\n", i);
}

void print(float f)
{
    printf("log: %f\n", f);
}

int main()
{
    print(0.5f);
    print("hi");

    return 0;
}
