#include <iostream>

int main() {
	int I = 1;
	while (I < 2147483647) {
		std::cout << I << ":" << sizeof(I) << "\n";
		I = I + I;
	}
	return 0;
}

