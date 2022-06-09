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
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int N = int(nums.size());
        if (N == 1)
            return nums[0];
        vector<int> s(nums);
        vector<int> start(2 * N);
        start[0] = 0;
        s.resize(2 * N);
        int _max = s[0];
        for (int i = 1; i < 2 * N; ++i)
        {
            s[i] = nums[i % N];
            int startPrev{start[i - 1]}, maxSumPrev{s[i - 1]};

                int j = start[i - 1];
            // if (i == 10)
            //     cout << "cc0: " << maxSumPrev << endl;
            if (i >= start[i - 1] + N)
            {
                int tempSum = maxSumPrev;
                maxSumPrev= INT_MIN;
                do
                {
                    tempSum -= nums[j % N];
                    if (tempSum >= maxSumPrev)
                    {
                        maxSumPrev = tempSum;

                        startPrev = j + 1;
                    }
                    j++;
                } while (j % N != i % N  and nums[j % N] < 0);
            }
            // maxSumPrev = (i < start[i - 1] + N) ? s[i - 1] : (s[i - 1] - s[j - 1]);

            if (maxSumPrev + nums[i % N] > s[i])
            {
                s[i] += maxSumPrev;
                start[i] = startPrev;
            }
            else
                start[i] = i;
            _max = max(_max, s[i]);
            // cout << "i: " << i << " n[i]: " << nums[i % N] << " j: " << j << "\tmaxSumPrev: " << maxSumPrev << " startPrev: " << startPrev << "-> s[i]: " << s[i] << endl;
        }
        for (int i = 0; i < 2 * N; ++i)
        {
            cout << start[i] << "->" << i << "=" << s[i] << endl;
        }

        // for_each(s.begin(), s.end(),[](int x){cout << x << ", ";});
        return _max;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{-5,-2,5,6,-2,-7,0,2,8};
    // vector<int> ins{3,4,2};
    auto res = s.maxSubarraySumCircular(ins);

    cout << endl
         << res << endl;
    return 0;
}
