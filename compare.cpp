#include <iostream>
#include <cmath>

double left(short n)
{
    //return n*pow(2,n); /* n2n = O(3^n)  */
    //return pow(n,0.5); /* n^0.5 = O(5^logn)  */
    //return pow(2,n); /* 2^n < Theta(2^(n+1))  */
    //return 10*(log10(n)/log10(2)); /* 10logn > O((logn)^2) */
    //return sqrt(n); /* sqrt(n) < O((logn)^3) */
    //return pow(2,n); /* 2^n < O(2^(n+1) */
    return n; /* n != Omega(2^n) */
}

double right(short n)
{
    //return pow(3,n);
    //return pow(5,(log10(n)/log10(2)));
    //return pow(2,n + 1);
    //return pow(log10(n)/log10(2),2);
    //return pow(log10(n)/log10(2),3);
    //return pow(2,n+1);
    return pow(2,n);
}

void compare(double &l, double &r)
{
    std::cout << l;
    if (l < r)
        std::cout << " < ";
    else if (l > r)
        std::cout << " > ";
    else
        std::cout << " = ";    
    std::cout << r << std::endl;
}

int main(void)
{
    double l_value, r_value;
    short n;
    for (n = 0; n != 10; ++n) {
        l_value = left(n);
        r_value = right(n);
        compare(l_value, r_value);
    }
    return 0;
}
