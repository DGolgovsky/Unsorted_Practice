#include <iostream>
#include <thread>

int i = 0;

void hello()
{
    std::cout << "[" << i << "] Hello, parrallel world!\n";
    ++i;
}

int main()
{
    while (i != 10) {
        std::thread t (hello);
        t.join();
    }

    return 0;
}
