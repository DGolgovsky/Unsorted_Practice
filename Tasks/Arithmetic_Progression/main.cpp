/*
 * Write a program to check if the sum of digits
 * of a given number N is a palindrome number or not.
 *
 * Input:
 * The first line of the input contains T denoting the number of testcases.
 * T testcases follow. Then each of the T lines contains
 * single positive integer N denoting the value of number.
 *
 * Output:
 * For each testcase, in a new line, output "YES" if pallindrome
 * else "NO". (without the quotes)
 *
 * Constraints:
 * 1 <= T <= 200
 * 1 <= N <= 1000
 *
 * Example:
 * Input:
 * 2
 * 56
 * 98
 * Output:
 * YES
 * NO
 */

#include <iostream>
#include <cmath>

// TODO write code with current task
int main(int, char **)
{
    uint16_t T = 0;
    uint16_t N = 0;

    std::cin >> T;
    if (T < 1 || T > 31) {
        std::cerr << "T must be in range [1; 31]\n";
        return 1;
    }

    for (uint16_t i = 0; i < T; ++i) {
        std::cin >> N;
        if (N < 100 || N > 999) {
            std::cerr << "N must be in range [100; 1000)\n";
            return 1;
        }

        uint64_t s = 0;
        auto x = N;
        while (x != 0) {
            s = s + static_cast<uint64_t>(std::pow(x % 10, 3));
            x = x / 10;
        }
        if (s == N)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }

    std::cout << std::endl;

    return 0;
}