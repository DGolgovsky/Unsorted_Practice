#include <iostream>

int main() {
    int n = 1;
    unsigned int k;
    std::cin >> k;
    while (k > 1) {
        k /= 2;
        n++;
        std::cout << n << "\n";
    }
    return 0;
}

