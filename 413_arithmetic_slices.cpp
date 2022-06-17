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
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int N = (int)nums.size();
        if (N < 3)
            return 0;
        vector<int> A(N, 0);
        for (int i = 2; i < N; ++i)
        {
            A[i] = A[i - 1];
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                A[i] += (A[i - 1] - A[i - 2]) + 1;
        }
        return A.back();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{1,3,5,7,9};
    // vector<int> ins{1};
    auto res = s.numberOfArithmeticSlices(ins);

    cout << endl
         << res << endl;
    return 0;
}
