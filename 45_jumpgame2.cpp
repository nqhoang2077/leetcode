#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int N = int(nums.size());
        if (N ==1)
            return 0;
        vector<int> dist(N,INT_MAX);
        dist[0] = 0;
        int lastFillPos = 0;
        for (int i=0; i < N; ++i){
            while (lastFillPos <=  min(N-1, i+nums[i])){
                // cout << "Last Fill Position: " << lastFillPos << endl;
                dist[lastFillPos] = min(dist[lastFillPos], dist[i]+1);
                lastFillPos++;
            }
        }
        // for_each(dist.begin(),dist.end(), [](int d){cout << d << ",";});

        return *(dist.end()-1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ins{1,1,1,1};
    // vector<int> ins{3,4,2};
    auto res = s.jump(ins);

    cout << endl << res << endl;
    return 0;
}
