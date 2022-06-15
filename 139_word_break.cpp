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
    vector<int> dp;

    int f(string &s, const int &idx, vector<string> &wordDict)
    {
        if (idx >= dp.size())
        {
            return 1;
        }
        if (dp[idx] != -1)
            return dp[idx];
        for (string w : wordDict)
        {
            if (s.find(w, idx) == idx)
            {
                dp[idx] = f(s, idx + w.size(), wordDict);
                if (dp[idx])
                    return dp[idx];
            }
        }
        return 0;
    }

public:
    bool wordBreak(string &s, vector<string> &wordDict)
    {
        dp = vector<int>(s.size(), -1);
        return f(s, 0, wordDict) > 0;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    string str = "catsandog";
    vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
    cout << s.wordBreak(str, wordDict);
    return 0;
}
