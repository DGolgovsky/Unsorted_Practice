#include <iostream>

int factorial(int x) {
	if (x > 1) return x * factorial(x - 1);
	else return 1;
}

int main(void) {
	double k = 0.0;
	std::cout << ">> ";
	std::cin >> k;
	std::cout << k << "! = "
			  << factorial((int) k) << std::endl;
	return 0;
}
