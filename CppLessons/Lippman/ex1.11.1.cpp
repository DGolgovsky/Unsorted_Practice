#include <iostream>

int main() {
	int val = 10;
	std::cout << "(while)";
	while (val >= 0) {
		std::cout << " " << val;
		val --;
	}
	std::cout << std::endl;	
	return 0;
}
