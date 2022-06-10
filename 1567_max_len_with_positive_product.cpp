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
    int getMaxLen(vector<int> &nums)
    {
        int N = int(nums.size());
        if (N == 1)
            return nums[0] > 0;
        vector<int> posProducts(nums);
        vector<int> posStart(N, -1);
        vector<int> negProducts(nums);
        vector<int> negStart(N, -1);

        for_each(posProducts.begin(), posProducts.end(), [](int &x)
                 { x = max(0, x); });
        for_each(negProducts.begin(), negProducts.end(), [](int &x)
                 { x = min(0, x); });

        posProducts[0] = max(posProducts[0], 0);
        posStart[0] = (nums[0] > 0) ? 0 : -1;

        negProducts[0] = min(negProducts[0], 0);
        negStart[0] = (nums[0] < 0) ? 0 : -1;

        int maxLen = 0;

        for (int i = 1; i < N; ++i)
        {
            auto ni = (nums[i] != 0) ? (nums[i] / abs(nums[i])) : 0;
            if (ni > 0)
            {
                posStart[i] = i;
                negStart[i] = -1;
                if (posProducts[i - 1] > 0)
                {
                    posProducts[i] = posProducts[i - 1] * ni;
                    posStart[i] = posStart[i - 1];
                }
                if (negProducts[i - 1] < 0)
                {
                    negProducts[i] = negProducts[i - 1] * ni;
                    negStart[i] = negStart[i - 1];
                }
            }
            else if (ni < 0)
            {
                posStart[i] = -1;
                negStart[i] = i;

                if (posProducts[i - 1] > 0)
                {
                    negProducts[i] = posProducts[i - 1] * ni;
                    negStart[i] = posStart[i - 1];
                }
                if (negProducts[i - 1] < 0)
                {
                    posProducts[i] = negProducts[i - 1] * ni;
                    posStart[i] = negStart[i - 1];
                }
            }
            if (posStart[i] > -1)
                maxLen = max(maxLen, i - posStart[i] + 1);
        }
        return maxLen;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{1000000000, 1000000000};
    // vector<int> ins{3,4,2};
    auto res = s.getMaxLen(ins);

    cout << endl
         << res << endl;
    return 0;
}
