#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>

template <typename T>
void fill_array(T &arr) {
	int input = 0;
	auto size = sizeof(arr) / sizeof(arr[0]);
	std::size_t i = 0;
	while (i < size) {
		std::cin >> input;
		if (std::cin.fail()) { // user didn't input a number
			std::cin.clear(); // reset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
							'\n'); //skip bad input
			// next, request user reinput
		} else {
			arr[i++] = input;
		}
	}
}

int main() {
	const unsigned int N1 = 7;
	const unsigned int N2 = 7;
	const unsigned int N3 = N1 + N2;

	std::cout << "Program will concatenate two static arrays." << '\n';

	std::array<int, N1> arr1;
	std::array<int, N2> arr2;
	std::array<int, N3> arr3;

	std::cout << "Fill array1(" << N1 << "): ";
	fill_array(arr1);
	std::cout << "Fill array2(" << N1 << "): ";
	fill_array(arr2);

	std::merge(arr1.begin(), arr1.end(),
			   arr2.begin(), arr2.end(),
			   arr3.begin());
	std::sort(arr3.begin(), arr3.end());

	std::copy(arr3.begin(), arr3.end(),
			  std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';

	return 0;
}
