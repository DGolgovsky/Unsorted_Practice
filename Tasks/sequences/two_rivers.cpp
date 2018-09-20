/*
 * A digital river is a sequence of numbers where
 * every number is followed by the same number plus the sum of its digits.
 * In such a sequence 123 is followed by 129 (since 1 + 2 + 3 = 6),
 * which again is followed by 141.
 *
 * We call a digital river river K, if it starts with the value K.
 *
 * For example, river 7 is the sequence
 * beginning with {7, 14, 19, 29, 40, 44, 52, ... }
 * and river 471 is the sequence
 * beginning with {471, 483, 498, 519, ... }.
 *
 * Digital rivers can meet.
 * This happens when two digital rivers share the same values.
 * River 32 meets river 47 at 47, while river 471 meets river 480 at 519.
 *
 * Given two meeting digital rivers print out the meeting point.
 */

#include <iostream>
#include <climits>
#include <set>
#include <algorithm>

/* Returns sum of digits*/
template<typename T>
unsigned split(T num)
{
    T sum = 0;
    while (num != 0) {
        sum = sum + num % 10;
        num = num / 10;
    }
    return sum;
}

int main()
{
    unsigned K1 = 32; // As default example: 32 && 47 = 47;
    unsigned K2 = 47;
    std::set<unsigned> set;

    while (std::cin >> K1 >> K2) {
        set.clear();
        auto max = std::max(K1, K2);
        auto min = std::min(K1, K2);

        while (min < max) {
            min += split(min);
        }
        set.insert(max);
        auto result = set.insert(min);
        if (result.second) { // Check for existance
            while (max < UINT_MAX) {
                max += split(max);
                result = set.insert(max);
                if (!result.second) // Check for existance/intersection
                    break;

                min += split(min);
                result = set.insert(min);
                if (!result.second) // Check for existance/intersection
                    break;
            }
        }
        
        std::cout << "Intersection of two sequences: " << std::min(min,max) << std::endl;
    }

    return 0;
}

/* Another (best) solution
 * #include <stdio.h>
 * // --------------------------------------------
 * int sum(int n) {
 *     return n ? n%10+sum(n/10) : 0 ;
 * }
 * // --------------------------------------------
 * int main() {
 *     int r1, r2;
 *     scanf("%d %d", &r1, &r2);
 *     while (r1 != r2) {
 *         while (r1 < r2) r1 += sum(r1);
 *         while (r2 < r1) r2 += sum(r2);
 *     }
 *     printf("%d", r1);
 * }
 */
