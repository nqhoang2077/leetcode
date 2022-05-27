#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define VOCAB 128
#define A 'A'

class Solution
{
public:
    int *charPos(const string &str, int start, int end)
    {
        int *pos = new int[VOCAB]{0};
        for_each(pos, pos + VOCAB, [](int &i)
                 { i = -1; });
        for (int i = start; i < min(size_t(end), str.length()); i++)
        {
            int p = str[i];
            pos[p] = i;
        }

        return pos;
    }
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() < 2)
            return s.length();
        int slow{0}, fast{1}, maxLen{1}, N{static_cast<int>(s.length())};
        auto window = charPos(s, slow, fast);
        while (fast < N)
        {
            char cF = s[fast];
            // Check if new char is seen
            if (window[cF] < 0)
            {
                // Not seen, increase window size
                window[cF] = fast;
                maxLen = max(maxLen, fast - slow + 1);
                fast = fast + 1;
            }
            else
            {
                // Seen, move slow 1 position to right
                char cS = s[slow++];
                window[cS] = -1;
            }
        }
        delete[] window;
        return maxLen;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string s = "asjrgapa";
    cout << "Solving string: " << s << endl << "--------------------------------" << endl;
    cout << "Max Length: " << solution.lengthOfLongestSubstring(s) << endl;
    // solution.printArray(solution.charPos("ggububgvfk", 0, 9));
    return 0;
}
