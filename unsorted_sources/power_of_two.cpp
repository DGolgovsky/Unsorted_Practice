#include <iostream>
#include <cmath>

int main() {
    int N = 0, bin = 1, i = 1;
    std::cin >> N;
    while (bin <= N) {
        std::cout << bin << " ";
        bin = pow(2, i++);
    }

    std::cout << std::endl;
    return 0;
}

