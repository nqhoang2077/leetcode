#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> lookupMap;
        for (int i = 0; i < nums.size(); i++)
            lookupMap[nums[i]] = i;

        int i, n{int(nums.size())};
        for (i = 0; i < n - 1; ++i)
        {
            auto search = lookupMap.find(target - nums[i]);
            if (search != lookupMap.end() && search->second != i)
                return vector<int>{i, search->second};  
            lookupMap.erase(nums[i]);
        }
        return nums;
    }
};

int main(int argc, char const *argv[])
{
    Solution solve;
    vector<int> nums{0, 4, 3, 0};
    int target{0};
    auto ans = solve.twoSum(nums, target);
    for_each(ans.begin(), ans.end(), [&](const int x)
             { cout << x << ','; });
    return 0;
}
