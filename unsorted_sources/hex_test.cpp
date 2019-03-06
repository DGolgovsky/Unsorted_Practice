#include <iostream>

int main() {
    unsigned i = 0xDEADBEEF;
    std::cout << "address of i is " << std::hex << &i;
    std::cin.get(); //Чтобы процесс не завершился
    return 0;
}

