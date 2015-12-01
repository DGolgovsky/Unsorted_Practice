int fermat (void) {
	const int MAX = 1000;
	int a = 1,b = 1,c = 1;
	while (1) {
		if (((a * a * a) == ((b * b * b) + ( c * c * c))))
			return 1;
		a++;
		if (a > MAX) {
			a = 1;
			b++;
		}
		if (b > MAX) {
			b = 1;
			c++;
		}
		if (c > MAX)
			return 0;
	}
}

#include <stdio.h>

int main (void) {
	if (fermat()) {
		printf ("Fermat's Last Theorem has been disproved.\n");
  } else {
    printf ("Fermat's Last Theorem has not been disproved.\n");
  }
  return 0;
}