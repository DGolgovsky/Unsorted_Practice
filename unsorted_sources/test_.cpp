#include <iostream>

int main()
{
	static int number  = 5;
	std::cout << number-- << std::endl;
	if (number)
		main();
	return 0;
}
