#ifndef _HAS_AT_
#define _HAS_AT_

#include <experimental/type_traits>

template<class T>
using at_t = decltype(std::declval<T&>().at(0));

template<typename T>
constexpr bool has_at = std::experimental::is_detected_v<at_t, T>;

/* SFINAE test examples */
/*
struct Example
{
    int at() const
    {
        return 42;
    }
};
struct Generic {};

int main(int, char**)
{
    if constexpr (has_at<Example>)
        std::cout << has_at<Example> << std::endl;

    if constexpr (has_at<Generic>)
        std::cout << has_at<Generic> << std::endl;

    return 0;
}
*/

#endif
