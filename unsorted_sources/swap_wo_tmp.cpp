#include <iostream>

void swap(int &a, int &b) {
    // Ex: a = 9, b = 4
    a = a - b;  // a = 9 - 4 = 5
    b = a + b;  // b = 5 + 4 = 9
    a = b - a;  // a = 9 - 5
}

void swap_opt(int &a, int &b) {
    // Ex: a = 101 (bin), b = 110
    a = a ^ b;  // a = 101^110 = 011
    b = a ^ b;  // b = 011^110 = 101
    a = a ^ b;  // a = 011^101 = 110
}

int main(void) {
    int a = 0, b = 0;
    std::cin >> a >> b;
    swap(a, b);
    std::cout << "Swap (1):" << "\n"
              << "\ta = " << a << "\n"
              << "\tb = " << b << "\n";
    swap_opt(a, b);
    std::cout << "Swap (2):" << "\n"
              << "\ta = " << a << "\n"
              << "\tb = " << b << "\n";
    return 0;
}

