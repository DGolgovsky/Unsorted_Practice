/*
 * Given an array of integers, return indices of the two numbers
 * such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution,
 * and you may not use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9
 *
 * return [0, 1].
 */

#include <iostream>
#include <vector>

using std::vector;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> ret(2);
    for (auto i = nums.begin(); i != nums.end(); ++i)
        for (auto j = i + 1; j != end(nums); ++j)
            if (*i + *j == target) {
                ret[0] = i - begin(nums);
                ret[1] = std::distance(begin(nums), j);
                return ret;
            }
    return ret;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto ret_vector = twoSum(nums, target);

    std::cout << "[" << ret_vector.at(0) << ", "
        << ret_vector.at(1) << "]" << std::endl;

    return 0;
}
