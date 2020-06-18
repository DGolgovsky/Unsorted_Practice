#include <stdio.h>

int main() {
	int a[2][2] = {{0, 1},
				   {2, 3}};
	int (*pa)[2] = &a[1];

	printf("*pa[0] -> %d\n*pa[1] -> %d\n", *pa[0], *pa[1]);

	return 0;
}
