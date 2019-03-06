#include <iostream>
#include <thread>
#include <string_view>

void say_hello(std::string_view username) {
    std::osyncstream{std::cerr} << "Hello " << username;
}

void beware_of(std::string_view something) {
    std::osyncstream(std::cerr) << something << " is dangerous";
}

int main() {
    std::thread t1([] {
        say_hello("Rachel");
    });

    std::thread t2([] {
        beware_of("darkness");
    });

    std::cerr << '\n';

    t2.join();
    t1.join();
}
