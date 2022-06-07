#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    template <typename T>
    void printArray(vector<T> array)
    {
        for_each(array.begin(), array.end(), [](int i)
                 { cout << i << ","; });
        cout << endl;
    }

    int rob(vector<int> &nums)
    {
        auto N{nums.size()};
        if (N == 0)
            return 0;
        if (N == 1)
            return nums[0];
        if (N == 2)
            return max(nums[0], nums[1]);
        vector<int> r{nums[0], max(nums[0], nums[1])};
        r.resize(N);

        vector<int> r_c(r);
        r_c[0] = 0;
        r_c[1] = nums[1];
        //
        vector<bool> hasFirst(N, false);
        bool hasLast = false;
        hasFirst[0] = true;
        hasFirst[1] = (nums[1] > nums[0]) ? false : true;

        for (int i = 2; i < N; ++i)
        {
            r_c[i] = max(r_c[i - 2] + nums[i], r_c[i - 1]);
        }
        for (int i = 2; i < N; ++i)
        {
            r[i] = max(r[i - 2] + nums[i], r[i - 1]);
            hasFirst[i] = (r[i - 2] + nums[i] > r[i - 1]) ? hasFirst[i - 2] : hasFirst[i - 1];
        }

        int i = N - 1;
        hasLast = (r[i - 2] + nums[i] > r[i - 1]) ? true : false;
        if (hasFirst[N - 1] and hasLast)
            return max(r_c[N - 1], r[N - 2]);

        return r[N - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{2, 1, 1, 2};
    auto res = s.rob(ins);

    cout << res << endl;
    return 0;
}
