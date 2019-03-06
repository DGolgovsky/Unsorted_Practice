#include <iostream>

unsigned sqrt_cpu_newton(long L) {
    unsigned rslt = (unsigned) L;
    long div = L;
    if (L <= 0)
        return 0;
    while (1) {
        div = (L / div + div) / 2;
        if (rslt > div)
            rslt = (unsigned) div;
        else
            return rslt;
    }
}

/*
 * The following code is the fast inverse square root implementation from Quake III Arena,
 * stripped of C preprocessor directives, but including the exact original comment text.
 */
float Q_rsqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long *) &y;                       // evil floating point bit level hacking
    i = 0x5f3759df - (i >> 1);               // what the fuck?
    y = *(float *) &i;
    y = y * (threehalfs - (x2 * y * y));   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}

int main(void) {
    double guess;
    int counter;
    double x = 1.0;
    double d = 1.0;

    std::cout << "Enter number: ";
    std::cin >> d;

    int cmax = (int) d;
    for (counter = 0; counter < cmax; ++counter) {
        guess = x;
        x = (x + d / x) / 2.0;
        if (guess == x)
            break;
    }

    std::cout << "Square root:\t\t" << x << std::endl;
    std::cout << "Square root (Newton):\t" << sqrt_cpu_newton(d) << std::endl;
    std::cout << "Square root (Inverse):\t" << Q_rsqrt(d) << std::endl;

    return 0;
}
