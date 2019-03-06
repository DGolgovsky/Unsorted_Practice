#include <stdio.h>

int main(void) {
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int n = 0;
    int a[20] = {1};

    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        for (k = i - 1; k; --k) {
            a[k] = a[k] + a[k - 1];
        }
        a[i - 1] = 1;

        for (l = 0; l < n - i; ++l)
            printf(" ");
        for (l = 0; l < i; ++l)
            printf("%d ", a[l]);
        printf("\n");
    }

    return 0;
}
