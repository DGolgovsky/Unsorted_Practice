#include <iostream>

int square(int x) {
	return x * x;
}

int main() {
	// put your code here
	int num = 0, i = 1;
	std::cin >> num;
	while (square(i) <= num) {
		std::cout << "num= " << num << ",i= " << i << ",sq(i)= ";
		std::cout << square(i++) << "\n";
	}
	return 0;
}
