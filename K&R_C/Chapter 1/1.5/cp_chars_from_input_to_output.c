#include <stdio.h>

/**
 * Copy istream to ostream
 */

int main(void)
{
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    return 0;
}
