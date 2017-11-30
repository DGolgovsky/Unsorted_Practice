/*
 * из цифр составить результат что-то типа 1?2?3?4?5=6
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums = {1,2,3,4,5};
    char const ops[] = {43,45,42,47}; // +, -, *, /
    size_t it[4] = {0,0,0,0};
    double result = 0;
    
    for (it[0] = 0; it[0] < 4; ++it[0]) {
        for (it[1] = 0; it[1] < 4; ++it[1]) {
            for (it[2] = 0; it[2] < 4; ++it[2]) {
                for (it[3] = 0; it[3] < 4; ++it[3]) {
                    int i = 0;
                    result = nums[0];
                    for (int KK = 1; KK < 5; ++KK) {
                        switch (it[i++]) {
                            case 0:
                                result+=nums[KK];
                                break;
                            case 1:
                                result-=nums[KK];
                                break;
                            case 2:
                                result*=nums[KK];
                                break;
                            case 3:
                                result/=nums[KK];
                                break;
                        }
                    }
                    if (result == 6)
                        std::cout << nums[0] << ops[it[0]]
                                  << nums[1] << ops[it[1]]
                                  << nums[2] << ops[it[2]]
                                  << nums[3] << ops[it[3]]
                                  << nums[4] << "=" << result
                                  <<std::endl;
                }
            }
        }
    }

    return 0;
}
