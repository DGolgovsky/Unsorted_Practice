#include <tuple>
#include <string>
#include <map>
#include <cassert>
#include <iostream>

struct BookInfo
{
	std::string title; // In UTF-8
	int yearPublished = 0;
};

template <class T>
T readBookInfo(T &t) {
	return t;
}

int main() {
	using namespace std::literals;

	BookInfo book = {"Advanced C++", 2017};
	// Раскладываем поля структуры на переменные title и year, тип которых выведен автоматически
	auto[title, year] = readBookInfo(book);

	auto[a, b, c] = std::tuple<int, std::string, double>(42, "hello"s, 3.14);

	std::cout << title << ": " << year << '\n';
	std::cout << a << ", " << b << ", " << c << '\n';

	/*
	 * Пример декомпозиции с try_emplace и
	 * декомпозиции key-value при обходе map:
	 */
	std::map <std::string, std::string> map;
	auto[iterator1, succeed1] = map.try_emplace("key", "abc");
	auto[iterator2, succeed2] = map.try_emplace("key", "cde");
	auto[iterator3, succeed3] = map.try_emplace("another_key", "cde");

	assert(succeed1);
	assert(!succeed2);
	assert(succeed3);

	// Вы можете раскладывать key и value прямо в range-based for
	for (auto&&[key, value] : map) {
		std::cout << key << ": " << value << "\n";
	}

	return 0;
}
