#include <iostream>

int main()
 {
    for (int i = 0; i < 4; ++i)
    {
       switch (i)
       {
          case 0  : std::cout << "0";
          case 1  : std::cout << "1"; continue;
          case 2  : std::cout << "2"; break;
          default : std::cout << "D"; break;
       }
       std::cout << ".";
    }
    std::cout << "\n";
    return 0;
 }
