#include <iostream>

int main()
{
    int A = 0, B = 0;

    /*
     * Instruction/description
     */
    std::cout << "Swap two variables using only math.\n";
    std::cout << "Enter two numbers:\n";
    std::cout << "A = ";
    std::cin >> A;
    std::cout << "B = ";
    std::cin >> B;

    /*
     * Some math magic
     */
    A = A + B;
    B = A - B;
    A = A - B;

    std::cout << "Swapping..." << std::endl;
    std::cout << "A = " << A << ", "
              << "B = " << B << std::endl;

    return 0;
}
