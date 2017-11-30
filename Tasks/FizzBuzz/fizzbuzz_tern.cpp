#include <iostream>

int main(void)
{
    for (int x = 1; x < 101; ++x)
        std::cout <<
            (!(x%15)?"FizzBuzz":!(x%3)?"Fizz":!(x%5)?"Buzz":std::to_string(x)) << " ";
    std::cout << std::endl;

    return 0;
}
