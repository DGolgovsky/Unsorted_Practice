#include <iostream>

template <class Char>
struct lchar_traits : public std::char_traits<Char>
{
	static void assign(Char &c1, Char const &c2) {
		c1 = std::tolower(c2);
	}

	static Char *move(Char *s1, Char const *s2, std::size_t n) {
		for (std::size_t i = 0; i < n; ++i)
			assign(s1[i], s2[i]);
		return s1;
	}

	static Char *copy(Char *s1, Char const *s2, std::size_t n) {
		return move(s1, s2, n);
	}
};

template <class Char>
using lbasic_string = std::basic_string<Char, lchar_traits<Char> >;

using lstring = lbasic_string<char>;
using lwstring = lbasic_string<wchar_t>;

template <class Char, class Traits, class Char2>
std::basic_ostream <Char, Traits> &operator<<(
		std::basic_ostream <Char,
		Traits> &os, const lbasic_string<Char2> &str) {
	return os.write(str.data(), str.size());
}

int main() {
	lstring s1 = "Hello";
	lstring s2 = "heLLo";
	if (s1 == s2)
		std::cout << s1 << " and " << s2 << " are equal\n";

#ifdef _UNICODE
	lwstring ws1 = L"Hello";
	lwstring ws2 = L"heLLo";
	if (ws1 == ws2)
		std::wcout << ws1 << " and " << ws2 << " are equal\n";
#endif

	return 0;
}
