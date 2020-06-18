#include <iostream>
#include <vector>
#include <string_view>
#include <utility>

#include "boost/algorithm/string.hpp"

int main() {
	const char *input = "geeks\tfor\tgeeks";
	std::vector <std::pair<const char *, const char *>> result;
	boost::split(result, input, boost::is_any_of("\t"));

	for (size_t i = 0; i < result.size(); i++) {
		std::cout << '[' << result[i].first - input << "-" << result[i].second - input << ')' << std::endl;
	}
	return 0;
}

