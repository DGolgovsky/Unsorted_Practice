#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>

bool HasPairWithSum(const std::vector<int>& data, int sum)
{
    int low = 0;
    int hi = data.size() - 1;
    while (low < hi) {
        int s = data[low] + data[hi];
        if (s == sum)
            return true;
        ++low;

    }
    return false;
}

bool HasPairWithSum_2(const std::vector<int>& data, int sum)
{
    std::unordered_set<int> comp;
    for (auto value : data) {
        if (comp.find(value) != comp.end())
            return true;
        comp.insert(sum - value);
    }
    return false;
}

int main()
{
    // [1,2,3,9] Sum = 8
    // [1,2,4,4] Sum = 8
    // [0,0,0,0,0,0,0,0,0,0]

    std::vector<int> ch1 = {1,2,3,9};
    int sum_ch1 = 8;
    std::vector<int> ch2 = {1,2,4,4};
    int sum_ch2 = 8;

    std::cout << HasPairWithSum(ch1, sum_ch1) << std::endl;
    std::cout << HasPairWithSum(ch2, sum_ch2) << std::endl;
    std::cout << HasPairWithSum_2(ch1, sum_ch1) << std::endl;
    std::cout << HasPairWithSum_2(ch2, sum_ch2) << std::endl;

    return 0;
}
