#include <stdio.h>
#include <math.h>

int main(void) {
	int pow_2 = pow(2, 20);
	int res = 0;
	int count = 0;
	for (int i = 0; i < 65536; i++)
		for (int j = 0; j < 65536; j++) {
			res = (i * 16 + j) % pow_2;
			if (res == 31744)
				count++;
		}

	if (!printf("0x7c00: %d\n", count))
		return 1;

	return 0;
}
