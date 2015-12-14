#include <stdio.h>
#include <stdint.h>

int main()
{
    //unsigned int a = 1024;
    uint32_t *i = 1024;
    i++;
    printf("%u\n", i);
    return 0;
}
