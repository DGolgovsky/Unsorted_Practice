#include <stdio.h>

int main(void) {
    int array[10] = {0};
    for (int i = 0; i < 1000; ++i)
        for (int j = 1; j < 10; ++j)
            if (i % j == 0)
                array[j]++;

    for (int i = 0; i < 10; ++i)
        printf(" %3d", array[i]);

    return 0;
}

