/*
 * For a given 3 digit number, find whether it is armstrong number or not.
 * An Armstrong number of three digits is an integer such that the sum
 * of the cubes of its digits is equal to the number itself.
 * For example, 371 is an Armstrong number since 3^3 + 7^3 + 1^3 = 371
 *
 * Input:
 * First line contains an integer, the number of test cases 'T'.
 * T testcases follow. Each test case contains a positive integer N.
 *
 * Output:
 * For each testcase, in a new line, print "Yes" if it is a armstrong number
 * else print "No".
 *
 * Constraints:
 * 1 <= T <= 31
 * 100 <= N < 1000
 *
 * Example:
 * Input:
 * 1
 * 371
 * Output:
 * Yes
 */

#include <iostream>
#include <cmath>

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