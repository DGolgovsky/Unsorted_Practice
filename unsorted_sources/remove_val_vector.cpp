/** https://leetcode.com/problems/remove-element
 * Given an array nums and a value val,
 * remove all instances of that value in-place
 * and return the new length.
 *
 * Do not allocate extra space for another array,
 * you must do this by modifying the input array
 * in-place with O(1) extra memory.
 *
 * The order of elements can be changed.
 * It doesn't matter what you leave beyond the new length.
 *
 * input:
 *      [3,2,2,3]
 *      3
 * answer:
 *      [2,2]
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

class Solution
{
public:
	int removeElement(std::vector<int> &vec, int val) {
		vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
		return vec.size();
	}
};

void trimLeftTrailingSpaces(std::string &input) {
	input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(std::string &input) {
	input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

std::vector<int> stringToIntegerVector(std::string input) {
	std::vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	std::stringstream ss;
	ss.str(input);
	std::string item;
	char delim = ',';
	while (std::getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(std::string input) {
	return stoi(input);
}

std::string integerVectorToString(std::vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	std::string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += std::to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::vector<int> nums = stringToIntegerVector(line);
		std::getline(std::cin, line);
		int val = stringToInteger(line);

		int ret = Solution().removeElement(nums, val);

		std::string out = integerVectorToString(nums, ret);
		std::cout << out << std::endl;
	}

	return 0;
}
