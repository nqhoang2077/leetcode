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
        auto N{prices.size()};
        auto &p = prices;
        if (N < 2)
            return 0;
        vector<int> profit(N, 0);
        int maxProfit{(prices[0] < prices[1]) ? prices[1] - prices[0] : 0};
        profit[1] = maxProfit;

        for (int i = 2; i < N; i++)
        {
            vector<int> comp{
                profit[i - 1],
                profit[i - 2],
                ((i > 2) ? profit[i - 3] : 0) + prices[i] - prices[i - 1],
                ((i > 2) ? profit[i - 3] : 0) + prices[i] - prices[i - 2]};
            if (i == N-1)
                for_each(comp.begin(), comp.end(), [](int p)
                         { cout << p << ".. "; });
            profit[i] = *max_element(comp.begin(), comp.end());
            maxProfit = max(maxProfit, profit[i]);
        }
        cout << endl;
        for_each(profit.begin(), profit.end(), [](int p)
                 { cout << p << "; "; });
        return max(0, maxProfit);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> tests{
        // {1, 2, 4},
        {6,1,3,2,4},
        // {6,1,3,2,4,7}
        };
    for (auto &ins : tests)
    {
        for_each(ins.begin(), ins.end(), [](int x)
                 { cout << x << ", "; });
        cout << endl;
        auto res = s.maxProfit(ins);
        cout << endl
             << " -> " << res << endl;
    }
    return 0;
}
