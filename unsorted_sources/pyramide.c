#include <stdio.h>

int main() {
    int n, i, j, k;
    do {
        printf("N = ");
        scanf("%d", &n);
    } while (n <= 0 || n > 40);
    for (i = 1; i <= n; ++i) {
        for (k = n - i; k > 0; --k) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
