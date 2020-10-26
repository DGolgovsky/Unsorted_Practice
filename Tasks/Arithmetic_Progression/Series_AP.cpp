/*
 * Given the first 2 terms A and B of an Arithmetic Series, tell the Nth term of the series.
 *
 * Input:
 * The first line of input contains an integer, the number of test cases T.
 * T testcases follow. Each testcase in its first line should contain
 * two positive integer A and B (First 2 terms of AP).
 * In the second line of every testcase it contains of an integer N.
 *
 * Output:
 * For each testcase, in a new line, print the Nth term of the
 * Arithmetic Progression.
 *
 * Constraints:
 * 1 <= T <= 100
 * -10^3 <= A <= 10^3
 * -10^3 <= B <= 10^3
 * 1 <= N <= 10^4
 *
 * Example:
 * Input:
 * 2
 * 2 3
 * 4
 * 1 2
 * 10
 *
 * Output:
 * 5
 * 10
 */

#include <iostream>
#include <vector>
#include <tuple>

int main(int, char **) {
    uint16_t T = 0, N = 0;
    int A = 0, B = 0;

    std::cin >> T;
    if (T < 1 || T > 100) {
        std::cerr <<
                  "T must be greater then 0 and lesser or equal then 100\n";
        return 1;
    }
    std::vector<std::tuple<int, int, uint16_t>> sequence(T);
    for (uint16_t i = 0; i < T; ++i) {
        std::cin >> A >> B >> N;
        sequence[i] = std::make_tuple(A, B, N);
    }
    for (uint16_t i = 0; i < T; ++i) {
        //auto [ A1, A2, N ] = sequence[i];
        auto An = std::get<0>(sequence[i]) + (std::get<2>(sequence[i]) - 1) * (std::get<1>(sequence[i]) - std::get<0>(sequence[i]));
        std::cout << An << std::endl;
    }

    return 0;
}