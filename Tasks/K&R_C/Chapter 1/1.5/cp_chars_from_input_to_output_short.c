#include <stdio.h>

/**
 * Copy istream to ostream
 */

int main(void)
{
    int c;
    
    while ((c = getchar()) != EOF)
        putchar(c);

    return 0;
}
