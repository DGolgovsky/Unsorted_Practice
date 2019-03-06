#include <iostream>
#include <tuple>
#include <typeinfo>

template<class T>
constexpr
std::string_view
type_name() {
    using namespace std;
#ifdef __clang__
    string_view p = __PRETTY_FUNCTION__;
    return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
    return string_view(p.data() + 36, p.size() - 36 - 1);
#  else
    return string_view(p.data() + 49, p.find(';', 49) - 49);
#  endif
#elif defined(_MSC_VER)
    string_view p = __FUNCSIG__;
    return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}


int main() {
    auto[a, i, b] = std::tuple('a', 123, true);

    std::cout << "a: " << a << '\t' << typeid(a).name() << '\n';
    std::cout << "a: " << a << '\t' << type_name<decltype(a)>() << '\n';
    std::cout << "i: " << i << '\t' << typeid(i).name() << '\n';
    std::cout << "i: " << i << '\t' << type_name<decltype(i)>() << '\n';
    std::cout << "b: " << b << '\t' << typeid(b).name() << '\n';
    std::cout << "b: " << b << '\t' << type_name<decltype(b)>() << '\n';

    return 0;
}
