#include <iostream>

template <class Char>
struct ichar_traits : public std::char_traits<Char>
{
	static bool eq(Char c1, Char c2) {
		return std::toupper(c1) == std::toupper(c2);
	}

	static bool lt(Char c1, Char c2) {
		return std::toupper(c1) < std::toupper(c2);
	}

	static bool gt(Char c1, Char c2) {
		return !lt(c1, c2);
	}

	static int compare(const Char *s1, const char *s2, std::size_t n) {
		for (; n-- != 0; ++s1, ++s2)
			if (std::toupper(*s1) < std::toupper(*s2)) return -1;
			else if (std::toupper(*s1) > std::toupper(*s2)) return 1;
		return 0;
	}

	static const char *find(const Char *s, int n, Char a) {
		for (a = std::toupper(a); n-- != 0; ++s)
			if (std::toupper(*s) == a) return s;
		return nullptr;
	}
};

/* C++17 */
template <class Char>
using ibasic_string_view = std::basic_string_view<Char, ichar_traits<Char>>;
using istring_view = ibasic_string_view<char>;
using iwstring_view = ibasic_string_view<wchar_t>

template <class Char, class Traits, class Char2>
std::basic_ostream <Char, Traits> &operator<<(
		std::basic_ostream <Char, Traits> &os,
		const ibasic_string_view<Char2> &str) {
	return os.write(str.data(), str.size());
}
/* C++17 */

template <class Char>
using ibasic_string = std::basic_string<Char, ichar_traits<Char> >;
using istring = ibasic_string<char>;
using iwstring = ibasic_string<wchar_t>;

template <class Char, class Traits, class Char2>
std::basic_ostream <Char, Traits> &operator<<(
		std::basic_ostream <Char, Traits> &os,
		const ibasic_string<Char2> &str) {
	return os.write(str.data(), str.size());
}

int main() {
	istring s1 = "Hello";
	istring s2 = "heLLo";

	if (s1 == s2)
		std::cout << s1 << " and " << s2 << " are equal\n";

#ifdef _UNICODE
	iwstring ws1 = L"Hello";
	iwstring ws2 = L"heLLo";

	if (ws1 == ws2)
		std::wcout << ws1 << " and " << ws2 << " are equal\n";

	/* C++17 */
	iwstring_view wsv1 = L"Hello";
	iwstring_view wsv2 = L"heLLo";

	if (wsv1 == wsv2)
		std::wcout << wsv1 << " and " << wsv2 << " are equal\n";
#endif

	return 0;
}
