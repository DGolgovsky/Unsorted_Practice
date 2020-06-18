#include <functional>
#include <iostream>

template <typename T>
extern void func(T);

template <typename T>
struct S
{
	static void do_thing() {
		try {
			func(T{});
		} catch (const std::range_error &) {
			std::clog << "range error";
		} catch (const std::runtime_error &) {
			std::clog << "runtime error";
		} catch (const std::bad_function_call &) {
			std::clog << "bad function call";
		}
	}
};

int main() {
	S<std::integral_constant < int, 1>>
	s;
	s.do_thing();
	S<std::integral_constant < int, 2>>
	s2;
	s2.do_thing();
	S<std::integral_constant < int, 3>>
	s3;
	S<std::integral_constant < int, 4>>
	s4;
	S<std::integral_constant < int, 5>>
	s5;
	S<std::integral_constant < int, 6>>
	s6;
	s3.do_thing();
	s4.do_thing();
	s5.do_thing();
	s6.do_thing();
	return 0;
}
