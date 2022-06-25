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
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        int N = (int)s.size();
        vector<int> W (N, 0);
        W[0] = 1;
        for (int i=1; i < N; ++i){
            if (stoi(s.substr(i,1)) > 0)
                W[i] += W[i-1];
            if (s[i-1] != '0' and stoi(s.substr(i-1,2)) < 27)
                W[i] += (i>1)?W[i-2]:1;
        }
        return W.back();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.numDecodings("11106");

    cout << endl
         << res << endl;
    return 0;
}
