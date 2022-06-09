#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int N = int(nums.size());
        if (N == 1)
            return nums[0];
        vector<int> s(nums);
        int _max = s[0];
        for (int i = 1; i < N; ++i)
        {
            s[i] += (s[i - 1] + nums[i] > nums[i]) ? s[i - 1] : 0;
            _max = max(_max, s[i]);
            // cout << s[i] << ", " << endl;
        }
        return _max;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int _max = maxSubArray(nums);
        // If Current Max is < 0, meaning there are only negative numbers in the array, and this sum is not a subarray but only 1 element which is the largest of the bunch. Since the length of the max-subarray is only 1 element, overlapping or non-overlapping does'nt matter anymore. That's why we return the value immediatly.
        if (_max < 0)
            return _max;
        int _sum = 0;
        for_each(nums.begin(), nums.end(), [&](int &v)
                 {_sum+=v;v=-v; });
        return max(_max, _sum + maxSubArray(nums));
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{-5, -2, 5, 6, -2, -7, 0, 2, 8};
    // vector<int> ins{3,4,2};
    auto res = s.maxSubarraySumCircular(ins);

    cout << endl
         << res << endl;
    return 0;
}
