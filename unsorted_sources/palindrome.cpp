#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string word) {
	auto size = word.size();
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	for (auto i = 0; i < size / 2; ++i) {
		std::cout << word[i] << ";" << i << " == " << word[size - i - 1] << ";" << (size - i - 1) << '\n';
		if (word[i] != word[size - i - 1])
			return false;
	}
	return true;
}

int main() {
	string word;
	cin >> word;
	cout << isPalindrome(word) << endl;
}