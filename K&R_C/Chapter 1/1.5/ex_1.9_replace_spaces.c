#include <stdio.h>

int main(void)
{
    unsigned int c, d;

    c = getchar();
    putchar(c);

    while ((d = getchar()) != EOF) {
        if (c != d)
            putchar(d);
        else
            if (c != ' ')
                putchar(d);
    }

    c = d;

    return 0;
}
