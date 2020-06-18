#include <experimental/type_traits>

template <class T>
using copy_assign_t = decltype(std::declval<T &>() = std::declval<const T &>());

struct Meow
{
};

struct Purr
{
	void operator=(const Purr &) = delete;
};

int main() {
	static_assert(std::experimental::is_detected<copy_assign_t, Meow>::value, "Meow should be copy assignable!");
	static_assert(!std::experimental::is_detected_v < copy_assign_t, Purr > , "Purr should not be copy assignable!");
	static_assert(std::experimental::is_detected_exact_v < Meow & , copy_assign_t, Meow > ,
				  "Copy assignment of Meow should return Meow&!");
}
