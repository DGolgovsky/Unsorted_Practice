#include <iostream>

int main() {
	double P = 0.0;
	double X = 0.0;
	double Y = 0.0;
	std::cin >> P >> X >> Y;
	double sum = X + (Y / 100.0);
	std::cout << sum << "\n";
	sum = sum + (sum * (P / 100.0));
	std::cout << sum << "\n";
	std::cout << (int) sum << " " << (sum - (int) sum) * 100 << std::endl;
	return 0;
}
