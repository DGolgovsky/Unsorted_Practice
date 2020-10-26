/**
 * Дан массив, состоящий из букв 'X', 'Y' и 'O'.
 * Необходимо найти кратчайшее расстояние между буквами 'X' и 'Y',
 * либо вывести 0, если 'X' либо 'Y' отсутствуют.
 *
 * "XY" -> 1
 * "YX" -> 1
 * "OOOXOOYOXO" -> 2
 * "OOOXXOY" -> 2
 *
 * "OO" -> 0
 * "OOOYYY" -> 0
 */

#include <climits>
#include <iostream>
#include <string>
#include <vector>

std::size_t distance(const std::string &str, char c1 = 'X', char c2 = 'Y') {
	if (str.empty())
		return 0;

	std::size_t min_distance = str.length();
	int i1 = -1;
	int i2 = -1;

	for (unsigned long i = 0; i < str.length(); ++i) {
		if (str[i] == c1) {
			i1 = i;
		}
		if (str[i] == c2) {
			i2 = i;
		}
		if (i1 != -1 && i2 != -1) {
			min_distance = std::min(static_cast<std::size_t>(abs(i2 - i1)), min_distance);
		}
	}
	if (min_distance == str.size())
		min_distance = 0;
	return min_distance;
}

int main() {
	std::vector<std::pair<std::string, unsigned int>> tests = {
			{"XY",                                               1},
			{"YX",                                               1},
			{"OOOXOOYOXO",                                       2},
			{"OOOYOOXOYO",                                       2},
			{"OOOXXOY",                                          2},
			{"OO",                                               0},
			{"",                                                 0},
			{"X00000X00000Y000X0000Y000X0000X0000XXXXX0000YYYY", 4},
			{"OOOXXX",                                           0},
			{"OOOYYY",                                           0},
			{"XXX000",                                           0},
			{"YYYOOO",                                           0}
	};
	std::size_t (*function)(std::string const &, char, char);
	function = &distance;

	for (unsigned int i = 0; i != tests.size(); ++i) {
		std::cout << "TEST0" << (i + 1) << ":"
		          << "\n\tinput : " << tests[i].first
		          << "\n\texpect: " << tests[i].second
		          << "\n\toutput: " << function(tests[i].first, 'X', 'Y')
		          << std::endl;
	}
	return 0;
}