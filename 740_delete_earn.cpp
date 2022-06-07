#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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

    int deleteAndEarn(vector<int> &nums)
    {
        unordered_map<int, int> M;
        auto N{nums.size()};
        sort(nums.begin(), nums.end(), greater<int>());
        // Create (frequencies * value) Hash Map
        for (auto n : nums)
        {
            try
            {
                M.at(n) += n;
            }
            catch (...)
            {
                M[n] += n;
            }
        }

        int i = 0;

        for (auto &m : M)
        {
            int k{m.first}, v{m.second};
            cout << k << " -> " << v << endl;
        }

        int res = M.begin()->second;
        for (auto it = M.begin(); it != M.end(); ++it){
            int ki{it->first}, vi{it->second};
            for (auto jt = M.begin(); jt != it; ++jt){
                int kj{jt->first}, vj{jt->second};
                res = max(res, vj + ((kj != ki-1)?vi:0));
            }
            cout << res << "; ";
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{8,10,4,9,1,3,5,9,4,10};
    // vector<int> ins{3,4,2};
    auto res = s.deleteAndEarn(ins);

    cout << res << endl;
    return 0;
}
