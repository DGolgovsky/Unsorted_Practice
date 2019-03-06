#include <stdio.h>

void calculate_tri_num(int n) {
    int i;
    int t_num = 0;
    for (i = 1; i <= n; ++i)
        t_num += i;
    printf("Number %i is %i\n", n, t_num);
}

int main(void) {
    calculate_tri_num(10);
    calculate_tri_num(20);
    calculate_tri_num(50);

    return 0;
}
