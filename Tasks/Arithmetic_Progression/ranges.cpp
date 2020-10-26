/**
 * Дан список интов, повторяющихся элементов в списке нет.
 * Нужно преобразовать это множество в строку,
 * сворачивая соседние по числовому ряду числа в диапазоны.
 *
 * Примеры:
 * [1,4,5,2,3,9,8,11,0] => "0-5,8-9,11"
 * [1,4,3,2] => "1-4"
 * [1,4] => "1,4"
 * [1,2,3,4] => "1-4"
 */

#include <iostream>
#include <vector>
#include <algorithm>

std::string range(const std::vector<int> &rhs) {
	std::string str;
	if (rhs.empty())
		return str;
	std::vector<int> v = rhs;
	std::sort(std::begin(v), std::end(v));

	int count = 0;
	str += std::to_string(v.at(0));
	for (int it = 1; it < v.size(); ++it) {
		auto prev = v.at(it - 1);
		auto curr = v.at(it);
		if (curr - prev != 1 || it+1 > v.size()) {
			if (count)
				str += "-";
			else
				str += ",";
			if (it != v.size())
				str += std::to_string(prev);
			str += ",";
			str += std::to_string(curr);
			count = 0;
		} else {
			count++;
		}
	}

	return str;
}

std::ostream &operator<<(std::ostream &os, std::vector<int> const &v) {
	os << "[";
	auto first = std::begin(v);
	for (auto i = first; i != std::end(v); ++i) {
		if (i != first)
			os << ", ";
		os << *i;
	}
	os << "]" << std::flush;
	return os;
}

int main() {
	std::vector<std::pair<std::vector<int>, std::string>> tests = {
			{{1, 4, 5, 2, 3, 9, 8, 11, 0}, "0-5,8-9,11"},
			{{1, 4, 3, 2},                 "1-4"},
			{{5, 9, 8, 6},                 "5-6,8-9"},
			{{1, 4},                       "1,4"},
			{{1, 2},                       "1,2"},
			{{1, 2, 3, 4},                 "1-4"},
			{{1},                          "1"},
			{{},                           ""}
	};
	std::string (*function)(const std::vector<int> &);
	function = &range;

	for (unsigned int i = 0; i != tests.size(); ++i) {
		std::cout << "TEST0" << (i + 1) << ":"
		          << "\n\tinput : " << tests[i].first
		          << "\n\texpect: " << tests[i].second
		          << "\n\toutput: " << function(tests[i].first)
		          << std::endl;
	}
	return 0;
}