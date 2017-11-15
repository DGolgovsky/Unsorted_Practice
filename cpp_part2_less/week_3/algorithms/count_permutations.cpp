#include <deque>
#include <array>
#include <iostream>

#include <algorithm>

template<class Iterator>
size_t count_permutations(Iterator p1, Iterator q1)
{
    if (p1 == q1) return 1;
    auto p = *reinterpret_cast<Iterator*>(&p1);
    auto q = *reinterpret_cast<Iterator*>(&q1);
    size_t count = 0;
    std::sort(p, q);
    do {
        auto i1 = std::adjacent_find(p, q);
        if (i1 == q)
            count++;
    } while (std::next_permutation(p, q));
    return count;
}

int main()
{
    std::array<int, 3> a1 = {3,2,1};
    size_t c1 = count_permutations(a1.begin(), a1.end()); // 6
    std::cout << c1 << '\n';
    std::array<int, 5> a2 = {1,2,3,4,4};
    size_t c2 = count_permutations(a2.begin(), a2.end()); // 36
    std::cout << c2 << '\n';
    std::deque<int> a3 = {1,2,2,3,4,4};
    size_t c3 = count_permutations(a3.begin(), a3.end()); // 36
    std::cout << c3 << '\n';

}

