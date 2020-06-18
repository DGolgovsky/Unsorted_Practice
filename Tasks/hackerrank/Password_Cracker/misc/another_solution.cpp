#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>

static std::unordered_set <std::string> memos;

static std::vector <std::string> *
		crack(std::vector < std::string >
const &words
,
std::string const &loginAttempt
)
{
if (memos.
find(loginAttempt)
== memos.

end()

) {
for (
auto const &word
: words) {
if (loginAttempt.compare(0, word.

length(), word

) == 0) {
auto s = loginAttempt.substr(word.length());
if (s.

empty()

)
return new std::vector <std::string> {
word};
auto *l = crack(words, s);
if (l != nullptr) {
l->
push_back(word);
return
l;
}
}
}
memos.
insert(loginAttempt);
}
return nullptr;
}

int main() {
	int t;
	std::cin >> t;
	while (--t >= 0) {
		memos.clear();
		int n;
		std::cin >> n;
		std::vector <std::string> words(n);
		while (--n >= 0) {
			std::cin >> words[n];
		}
		std::string loginAttempt;
		std::cin >> loginAttempt;
		auto *matches = crack(words, loginAttempt);
		if (matches == nullptr) {
			std::cout << "WRONG PASSWORD" << std::endl;
		} else {
			for (auto i = matches->crbegin(); i != matches->crend(); ++i) {
				std::cout << *i << ' ';
			}
			std::cout << std::endl;
		}
	}

	return 0;
}
