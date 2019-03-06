#include <iostream>

int bitSwapRequired(int a, int b) {
    int count = 0;
    for (int c = a ^b; c != 0; c = c & (c - 1)) {
        std::cout << c << " ";
        count++;
    }
    std::cout << "\n";
    return count;
}

int main() {
    std::cout << "Enter two int numbers: ";
    int a, b;
    std::cin >> a >> b;
    int swap = bitSwapRequired(a, b);
    std::cout << "For swap need to change " << swap << " bit(s).\n";
    return 0;
}
