#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution
{
public:
    void printArray(vector<int> array)
    {
        for_each(array.begin(), array.end(), [](int i)
                 { cout << i << "_"; });
        cout << endl;
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> comb;
        stack<int> explore;
        for (int i = 1; i <= n - k + 1; ++i)
            explore.push(i);
        
        while (!explore.empty())
        {
            int cur = explore.top();
            explore.pop();
            if (comb.size()>0 and cur < comb.back())
                comb.pop_back();
            comb.push_back(cur);
            if (comb.size() == k)
            {
                printArray(comb);
                result.push_back(comb);
                comb.pop_back();
            }
            else{

                for (int i = cur + 1; i <= n; ++i){

                    explore.push(i);
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.combine(4, 3);

    return 0;
}
