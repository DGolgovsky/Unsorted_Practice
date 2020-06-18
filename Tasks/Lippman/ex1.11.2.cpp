#include <iostream>

int main() {
	std::cout << "(for)";
	for (int val = 10; val >= 0; val--)
		std::cout << " " << val;
	std::cout << std::endl;
	return 0;
}
