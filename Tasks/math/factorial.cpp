#include <iostream>
#include <stdexcept>
//#include <exception>

constexpr unsigned long long factorial(unsigned n) {
	if (n > 20)
		throw std::out_of_range("N is out of range");
	return n ? n * factorial(n - 1) : 1;
}

int main() {
	unsigned long long i = 0;
	unsigned N = 0;
	while (std::cout << "N[0..20]: " && std::cin >> N) {
		try {
			i = factorial(N);
		} catch (std::out_of_range &ex) {
			std::cout << ex.what() << '\n';
			continue;
		}
		std::cout << "!" << N << " = " << i << std::endl;
	}
	return 0;
}

