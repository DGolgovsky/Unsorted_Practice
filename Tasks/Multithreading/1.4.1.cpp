#include <iostream>
#include <thread>

void hello()
{
    std::cout << "[" << std::this_thread::get_id();
    std::cout << "] Hello, parrallel world!\n";
}

int main()
{
    size_t i = 0;
    while (i != 10) {
        std::thread t (hello);
        std::cout << "main thread\n";
        t.join();
        ++i;
    }

    return 0;
}
