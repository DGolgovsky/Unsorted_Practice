#include <iostream>

int main()
{
    char c[] = "Hello_niggas!";
    std::cout << "char sizeof:\t" << sizeof(c) << "\n";
    std::cout << "last element:\t" << c[sizeof(c) - 1] << "\n";
    int i = sizeof(c);
    while (--i != -1)
        std::cout << "element:\t" << c[sizeof(c) - i] << "\n";
    return 0;
}

