#include <iostream>

template <typename T>
struct Format
{
	std::string formatted() {
		return static_cast<T *>(this)->russian + " (" + static_cast<T *>(this)->english + ")";
	}
};

struct Author : Format<Author>
{
	Author(const std::string &r, const std::string &e)
			: russian(r), english(e) {}

	std::string russian;
	std::string english;
};

struct Movie : Format<Movie>
{
	Movie(const std::string &r, const std::string &e)
			: russian(r), english(e) {}

	std::string russian;
	std::string english;
};

int main() {
	Author author("Иван", "Ivan");
	Movie movie("Титаник", "Titanic");

	std::cout << author.formatted() << std::endl;
	std::cout << movie.formatted() << std::endl;

	return 0;
}
