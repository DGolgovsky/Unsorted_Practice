#include <stdio.h>

void DisplayBits(int a, int n) {
    int i;
    for (i = n - 1; i >= 0; i--)
        printf("%d ", ((a >> i) & 1));
    printf("\n");
}


int main() {
    int n = 6, i, size;
    size = 1 << n;
    for (i = 0; i < size; i++)
        DisplayBits(i, n);
    return 0;
}
