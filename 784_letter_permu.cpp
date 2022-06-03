#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void backtrack(vector<string>& res, string s, int l, int r) {
        if (l==r){
            res.push_back(s);
            // cout << s ;
        }
        else {
            
            backtrack(res, s, l+1,r);
            
            if (isalpha(s[l])){
                int modifer = (char(s[l])>='a')?-1:1;
                
                s[l]+=modifer*32;
                backtrack(res, s, l+1,r);
                s[l]-=modifer*32;
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtrack(res, s, 0, s.length());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.letterCasePermutation("A1b2");
    for (string s : res)
        cout << s << endl;
    return 0;
}
