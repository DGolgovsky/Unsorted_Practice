// Sum without operator '+'
#include <iostream>

int add(int a, int b)
{
	if (b == 0) return a;
	int sum = a ^ b;
	int carry = (a & b) << 1;
	return add(sum, carry);
}

int main(void)
{
	int a = 0, b = 0;
	std::cin >> a >> b;
	std::cout << "Sum = " << add(a, b) << "\n";
	return 0;
}

