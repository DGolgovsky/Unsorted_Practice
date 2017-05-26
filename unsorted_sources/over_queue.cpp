#include <iostream>

int main()
{
    int a = 0;
    int b = 5;
    std::cout << "a = 0, b = 5\n\
b = b / a\n";
    (a != 0) && (b = b / a);
    (a == 0) || (b = b / a);
    std::cout << "a = " <<a << ", "
              << "b = " << b << std::endl;

    return 0;
}
