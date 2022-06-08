#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = int(nums.size());
        if (N == 1)
            return nums[0];
        vector<int> s(nums);
        int _max = s[0];
        for (int i=1; i < N; ++i){
            s[i] += (s[i-1]+nums[i]>nums[i])?s[i-1]:0;
            _max = max(_max, s[i]);
            // cout << s[i] << ", " << endl;
        }
        return _max;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{-1,-2};
    // vector<int> ins{3,4,2};
    auto res = s.maxSubArray(ins);

    cout << endl
         << res << endl;
    return 0;
}
