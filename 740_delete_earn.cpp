#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
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
        map<int, int> MP;
        auto N{nums.size()};
        // Create (frequencies * value) Hash Map
        for (auto n : nums)
        {
            try
            {
                MP.at(n) += n;
            }
            catch (...)
            {
                MP[n] += n;
            }
        }

        map<int, int> M(MP.begin(), MP.end());

        int res = M.begin()->second;
        unordered_map<int, int> A;

        
        for (auto it = M.begin(); it != M.end(); ++it){
            int ki{it->first}, vi{it->second};
            
            auto jt = it;
            jt --;
            int kj{jt->first}, vj{jt->second};
            
            if (kj != ki - 1)
                A[ki] = vi + A[kj];
            else{
                jt--;
                A[ki] = vi + A[jt->first];
            }

            
            res = max(res, A[ki]);
            A[ki] = res;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // vector<int> ins{};
    vector<int> ins{3,4,2};
    auto res = s.deleteAndEarn(ins);

    cout << res << endl;
    return 0;
}
