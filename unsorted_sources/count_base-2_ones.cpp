/*
 * Given a base-10 integer, n, convert it to binary (base-2).
 * Then find and print the base-10 integer denoting
 * the maximum number of consecutive 1's in n's binary representation.
 */

#include <iostream>
#include <algorithm>

int main() {
	int n = 0;
	std::cin >> n;

	int counter = 0, max = 0;
	while (n > 0) {
		int rem = n % 2;
		if (rem == 1)
			counter++;
		else
			counter = 0;
		max = std::max(counter, max);
		n /= 2;
	}
	std::cout << max << '\n';

	return 0;
}
