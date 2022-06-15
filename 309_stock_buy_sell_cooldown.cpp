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
private:
    vector<vector<int>> dp;
    int f(vector<int> &prices, int i, int canBuy)
    {
        if (i >= prices.size())
            return 0;
        if (dp[i][canBuy] != -1)
            return dp[i][canBuy];
        int x, y;
        if (canBuy)
        {
            x = f(prices, i + 1, 0) - prices[i];
            y = f(prices, i + 1, 1);
        }
        else
        {
            x = f(prices, i + 2, 1) + prices[i];
            y = f(prices, i + 1, 0);
        }
        return dp[i][canBuy] = max(x, y);
    }

public:
    // int maxProfit(vector<int> &prices)
    // {
    //     dp = vector<vector<int>>(prices.size());
    //     for (auto &r : dp)
    //         r = vector<int>(2, -1);
    //     return f(prices, 0, 1);
    // }
    int maxProfit(vector<int> &prices)
    {
        int N = (int)prices.size();
        if (N < 2)
            return 0;
        vector<int> buy(N), sell(N);
        buy[0] = -prices[0];
        buy[1] = max(-prices[0], -prices[1]);
        sell[0] = 0;
        sell[1] = max(prices[1] - prices[0], 0);
        for (int i = 2; i < N; i++)
        {
            buy[i] = max(sell[i - 2] - prices[i], buy[i - 1]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
        }
        return sell.back();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> tests{
        // {1, 2, 4},
        // {6, 1, 3, 2, 4},
        {6, 1, 3, 2, 4, 7}};
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
