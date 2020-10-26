// Example program
#include <iostream>
#include <string>

int main()
{
    uint16_t val = 0;
    uint8_t v1 = 255;
    uint8_t v2 = 128;

    val = v1<<8;
    val += v2;

    std::cout << "v1 = " << (val>>8) << "\n"; // 64
    std::cout << "v2 = " << (val&0xFF) << "\n"; // 32
    
    return 0;
}
