/**
 * Find all permutations with given N numbers and sums S
 * I1 + I2 + .. IN = S
 * N <= S
 * 0 < N,S < 50
 *
 * N = 4, S = 6
 * 1113
 * 1122
 * 1131
 * 1212
 * 1221
 * 1311
 * 2112
 * 2121
 * 2211
 * 3111
 */

#include <vector>
#include <iostream>
#include <numeric>
#include <cassert>

// Output all vector's permutations
void print_vector(std::vector<unsigned> v) {
	for (auto &it : v) {
		std::cout << it;
	}
	/*
	do {
		std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << '\n';
	} while (std::next_permutation(v.begin(), v.end()));
	 */
	std::cout << std::endl;
}

template <typename T>
void gen(T &v, int i, const unsigned S, unsigned init = 0) {
	do {
		if (std::accumulate(std::begin(v), std::end(v), init) == S) {
			print_vector(v);
		} else {
			if (i + 1 != v.size())
				gen(v, i + 1, S);
		}
	} while ((++v[i]) <= (S - v.size() + 1));
	v[i] = 1;
}

int main() {
	unsigned N, S;
	std::cout << "N = ";
	std::cin >> N;
	std::cout << "S = ";
	std::cin >> S;
	assert(N <= S);

	unsigned init = 0;
	std::vector<unsigned> v(N, 1);
	std::size_t i = 0;
	gen(v, i, S);

	return 0;
}
