/*
 * Дано натуральное число N. Выведите слово YES, если число N является
 * точной степенью двойки, или слово NO в противном случае.
 */

#include <iostream>
#include <cmath>
#include <string>

int main(void) {
	double N = 0;
	std::cin >> N;
	std::string ret = "NO";
	N = log10(N) / log10(2);
	if ((double) (int) N == N)
		ret = "YES";

	std::cout << ret << "\n";
	return 0;
}
