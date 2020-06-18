#include <iostream>

int main() {
	int sum = 0;
	int value = 50;
	while (value <= 100) {
		sum += value;
		value++;
	}

	std::cout << "(while) Sum of 50 to 100 inclusive "
			  << sum << std::endl;
	return 0;
}
