#include <iostream>

int **create_a2d(size_t row, size_t col) {
	if (!row)
		return 0;

	int **m = new int *[row];

	m[0] = new int[row * col];
	for (size_t i = 1; i != row; ++i)
		m[i] = m[i - 1] + col;

	return m;
}

void delete_a2d(int **m) {
	delete[] m[0];
	delete[] m;
}

int main(void) {
	int k = 1;
	int r = 0, c = 0;
	std::cin >> r >> c;
	int **m = create_a2d(r, c);
	if (!m)
		return 1;
	for (size_t i = 0; i != r; ++i) {
		std::cout << i + 1 << ". ";
		for (size_t j = 0; j != c; ++j) {
			m[i][j] = k++;
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}

	delete_a2d(m);
	m = 0;

	return 0;
}
