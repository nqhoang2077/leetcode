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
        int right{1}, left{0};
        int _max = INT_MIN;
        int sum = 0;
        for (int j = 0; j < N; ++j)
        {
            sum += nums[j];
            if (sum > _max)
            {
                _max = sum;
                right = j;
            }
        }
        cout << "maxR: " << _max << " at right " << right << endl;
        sum = _max;
        for (int i = 0; i <= right; ++i)
        {
            sum -= nums[i];
            if (sum > _max)
            {
                _max = sum;
                left = i + 1;
            }
        }

        cout << "maxL: " << _max << " at left " << left << endl;
        return _max;
    }
}

;

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{-2,-1};
    // vector<int> ins{3,4,2};
    auto res = s.maxSubArray(ins);

    cout << endl
         << res << endl;
    return 0;
}
