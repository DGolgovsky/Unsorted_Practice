#include <cassert>
#include <cstdint>
#include <utility>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
    assert(a > 0);

    if (b > 0) {
        return gcd(b, a % b);
    }
    return a;
}

int main(void)
{
    std::int64_t a, b;
    std::cin >> a >> b;
    const int RUNS_COUNT = 1000000;
    for (int i = 0; i < RUNS_COUNT; ++i) {
        gcd(a, b);
    }
    std::cout << gcd(a, b) << std::endl;
    return 0;
}

