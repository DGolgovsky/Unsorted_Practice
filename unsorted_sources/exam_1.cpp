#include <iostream>
#include <vector>
#include <algorithm>

int second_largest(std::vector<int> array) {
	std::sort(array.begin(), array.end(), std::greater<int>());
	int max = array[0];
	for (auto &it : array) {
		if (it < max) {
			return it;
		}
	}
	return -1;
}

int main() {
	std::vector<int> arr1 = {1, 2, 3, 4};
	std::vector<int> arr2 = {4, 1, 2, 3};
	std::vector<int> arr3 = {1, 1, 2, 2};
	std::vector<int> arr4 = {1, 1};
	std::vector<int> arr5 = {1};
	std::vector<int> arr6 = {};
	std::cout << second_largest(arr1) << std::endl;
	std::cout << second_largest(arr2) << std::endl;
	std::cout << second_largest(arr3) << std::endl;
	std::cout << second_largest(arr4) << std::endl;
	std::cout << second_largest(arr5) << std::endl;
	std::cout << second_largest(arr6) << std::endl;
	return 0;
}
