#include <iostream>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
 
int main()
{
    /*
     * C++
     * std::random_device rd;
     * std::mt19937 gen(rd());
     * std::uniform_int_distribution<> dis(0, vect.size() — 1);
     * auto result = vect[dis(gen)];
     */
    std::string in = "abcdefghijklmnopqrstuvwxyz", out;
    std::sample(in.begin(), in.end(), std::back_inserter(out),
                5, std::mt19937{std::random_device{}()});
    std::cout << "five random letters out of " << in << " : " << out << '\n';
    return 0;
}
