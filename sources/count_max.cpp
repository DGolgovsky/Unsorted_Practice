/*
 * Последовательность состоит из натуральных чисел и завершается числом 0.
 * Определите какое количество элементов этой последовательности
 * равны ее наибольшему элементу.
 */

#include <iostream>

int main(void)
{
	int N = 0;
	int max = 0;
	int i = 1;
	while (std::cin >> N) {
		if (N == 0)
			break;
		if (N == max)
			i++;
		if (N > max) {
			max = N;
			i = 1;
		}
	}

	std::cout << i << "\n";

	return 0;
}
