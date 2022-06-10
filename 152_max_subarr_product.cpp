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
    int maxProduct(vector<int> &nums)
    {
        int N = int(nums.size());
        if (N == 1)
            return nums[0];
        vector<int> bigs(nums);
        vector<int> smalls(nums);
        int _max = bigs[0];
        for (int i = 1; i < N; ++i)
        {
            bigs[i] = bigs[i - 1] * nums[i];
            smalls[i] = smalls[i - 1] * nums[i];
            if (smalls[i] > bigs[i])
                std::swap(smalls[i], bigs[i]);
            bigs[i] = max(nums[i], bigs[i]);
            smalls[i] = min(nums[i], smalls[i]);

            _max = max(_max, bigs[i]);
        }
        return _max;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{2, -5, -2, -4, 3};
    // vector<int> ins{3,4,2};
    auto res = s.maxProduct(ins);

    cout << endl
         << res << endl;
    return 0;
}
