#include <iostream>

int bitSwapRequired(int &a, int &b)
{
	int count = 0;
	for (int c = a ^ b; c != 0; c = c >> 1)
		count += c & 1;
	return count;
}

int main(void)
{
	int a = 0, b = 0;
	std::cin >> a >> b;
	std::cout << "Bits req: " << bitSwapRequired(a, b) << "\n";
	return 0;
}

