#include <iostream>
#include <vector>

using std::string;
using std::vector;

int main(void) {
	vector <string> array;
	int i = 0;
	for (i = 0; i < 100; ++i)
		array.push_back(std::to_string(i + 1));
	for (i = 2; i < 100; i += 3)
		array[i] = "Fizz";
	for (i = 4; i < 100; i += 5)
		array[i] = "Buzz";
	for (i = 14; i < 100; i += 15)
		array[i] = "FizzBuzz";
	for (auto iter : array)
		std::cout << iter << " ";
	std::cout << std::endl;

	return 0;
}
