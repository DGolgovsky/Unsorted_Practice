#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[256];
    for (int i = 0; i < 256; ++i)
        a[i] = i*2;

    for (int i = 0; i < 256; ++i)
        printf("%d ", *(a+i));

    printf("\n");

    return 0;
}
