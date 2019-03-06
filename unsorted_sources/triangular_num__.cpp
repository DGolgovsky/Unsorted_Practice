#include <iostream>
#include <stdio.h>

#define MAX 9223372036854775807.0

bool ReadA(double &a) {
    if (scanf("%lf", &a) != 1 || (a - (long long) a != 0))
        return false;

    a = (long long) a;

    if (a <= 0.0 || a > MAX)
        return false;
    else
        return true;
}

int main(void) {
    double a;
    double b = 0.0;
    if (!ReadA(a)) {
        std::cout << 0;
        std::cout << std::endl;
        return 0;
    }
    for (; a > 0.0; ++b)
        a -= b;
    std::cout << (a ? 0 : b - 1);
    std::cout << std::endl;
    return 0;
}
