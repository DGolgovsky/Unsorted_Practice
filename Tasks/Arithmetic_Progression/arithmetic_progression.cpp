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
 * -103 <= A <= 103
 * -103 <= B <= 103
 * 1 <= N <= 104
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

int main(int, char**)
{
    uint16_t T = 0, N = 0;
    int A = 0, B = 0;

    std::cin >> T;
    if (T < 0 || T > 100) {
        std::cerr <<
            "T must be greater then 0 and lesser or equal then 100\n";
        return 1;
    }
    std::vector<std::tuple<int,int,uint16_t>> sequence(T);
    for (unsigned int i = 0; i < T; ++i) {
    std::cin >> A >> B;
    if (A < -103 || A > 103 || B < -103 || B > 103) {
        std::cerr <<
            "A and B must be in [-103; 103] range.\n";
    }
    std::cin >> N;
    if (N < 0 || N > 104) {
        std::cerr <<
            "N must be greater then 0 and lesser or equal then 104\n";
        return 1;
    }
    sequence[i] = {A,B,N};
    }
    auto An = A + (N - 1) * (B - A);

    std::cout << An << std::endl;
    
    return 0;
}
