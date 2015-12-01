#include <iostream>

int main() {
	char greeting[] = "Hello";
	std::cout << greeting << '\n';
	for (int i = 0; i < 5; i++)
		std::cout << greeting[i] << ";";
	std::cout << "\n";
	return 47;
}

