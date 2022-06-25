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
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = *max_element(matrix[0].begin(), matrix[0].end()) - 48;
        if (m == 1)
            return res;
        
        vector<vector<int>> M (m);
        for (int i=0;i<m;++i){
            M[i] = vector<int>(n, 0);
            for (int j=0; j < n; ++j)
                M[i][j] = matrix[i][j] - 48;
        }
        
        // for (int r=1;r<m;++r){
        //     for (int c=0; c < n; ++c){
        //         if (M[r][c] > 0 and c < n-1){
        //             int LT = M[r-1][c];
        //             int RT = M[r-1][c+1];
        //             int RB = M[r][c+1];
        //             if (LT * RT * RB > 0){                        
        //                 int maxAdd = min(LT, RT);
        //                 for (int d=c+1; M[r][c] <= maxAdd and d < n and M[r][d] > 0; ++d)
        //                     M[r][c] += 1;
        //             }
        //         }
        //         res = max(res, M[r][c]);
        //     }
        // }


        for (int r=1;r<m;++r){
            for (int c=0; c < n; ++c){
                if (M[r][c] > 0 and c > 0){
                    int LT = M[r-1][c-1];
                    int RT = M[r-1][c];
                    int RB = M[r][c-1];
                    M[r][c] = 1 + min(min(LT, RT), RB);
                }
                res = max(res, M[r][c]);
            }
        }


        // for (int i=0;i<m;++i){
        //     for (int j=0; j < n; ++j)
        //         cout << M[i][j] << ", ";
        //     cout << endl;
        // }
        return res*res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // vector<vector<char>> ins {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<vector<char>> ins {{'0','0','0','0','0'},{'1','0','0','0','0'},{'0','0','0','0','0'},{'0','0','0','0','0'}};
    // vector<int> ins{3,4,2};
    auto res = s.maximalSquare(ins);

    cout << endl
         << res << endl;
    return 0;
}
