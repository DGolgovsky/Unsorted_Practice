//leaders_in_an_array
// 16 17 4 3 5 2 0
#include <iostream>

int main() {
    int *p = new int();
    int *q = p;
    while (std::cin >> *p && *p) {
//		std::cout << p << "\n";
        p++;
    }
    int length = p - q;
//	std::cout << /*length << */"\n";
    int i = 0;
    bool check;
    while (i < length) {
//		std::cout << q+i << "\n";
        check = 1;
        for (int j = i + 1; j < length; ++j) {
//			std::cout << *(q+j) << ";" << *(q+i) << "\n";
//			std::cout << q+j << "\n";
            if (*(q + j) > *(q + i)) {
                check = 0;
                break;
            }
        }
        if (check)
            std::cout << *(q + i) << "\n";
        i++;
    }
//	std::cout << std::endl;
    delete p;
    return 0;
}
