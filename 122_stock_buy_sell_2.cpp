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
    int maxProfit(vector<int> &prices)
    {
        auto N {prices.size()};
        if (N < 2)
            return 0;
        int maxProfit{(prices[0] < prices[1]) ? prices[1] - prices[0] : 0};

        for (int i = 2; i < N; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                // SELL
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return max(0, maxProfit);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{1, 3, 5, 4, 3, 7, 6, 9, 2, 4};
    auto res = s.maxProfit(ins);

    cout << endl
         << res << endl;
    return 0;
}
