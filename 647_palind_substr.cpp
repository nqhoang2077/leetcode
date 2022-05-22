#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
    using PosPair = std::pair<int, int>;

public:
    size_t palindromes;

    void growPalindromes(string str, PosPair pos)
    {
        int l, r;
        tie(l, r) = pos;
        // cout << "Growing palindromes: " << l << " " << r << endl;
        if (l < 0 || r >= str.size())
            return;
        do
        {
            // cout << "\tChecking pos: " << l << " " << r << endl;
            if (str[r] == str[l])
            {
                // cout << "Found palindromes: " << str.substr(l, r - l + 1) << endl;
                palindromes++;
            }
            else
                break;
        } while (--l >= 0 && ++r < str.length());
    }

    queue<PosPair> findStartPositions(string str)
    {
        queue<PosPair> result;
        for (int i = 0; i < str.size() - 1; ++i)
        {
            // search for size-3 positions
            if (i + 2 < str.size() && str[i + 2] == str[i])
            {
                result.push({i, i + 2});
            }
            // search for size-2 positions
            if (str[i + 1] == str[i])
            {
                result.push({i, i + 1});
            }
        }

        return result;
    }

    int countSubstrings(string s)
    {
        palindromes = 0;
        // Find all start positions
        auto startPositions = findStartPositions(s);

        // For each position, try grow the palindromes
        while (!startPositions.empty())
        {
            growPalindromes(s, startPositions.front());
            startPositions.pop();
        }

        // Add size-1 palindromes
        palindromes += s.length();

        return palindromes;
    }
};

int main(int argc, char const *argv[])
{
    string s{"aaaaa"};
    Solution solve;
    cout << solve.countSubstrings(s) << endl;
    return 0;
}
