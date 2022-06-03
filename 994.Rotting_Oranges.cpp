#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
    using position = std::pair<int, int>;
    struct pos_hash
    {
        template <class T1, class T2>
        size_t operator()(std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };

public:
    int orangesRotting(vector<vector<int>> &mat)
    {
        auto rows{mat.size()}, cols{mat[0].size()};
        queue<position> exploreQ;
        int time = -1;
        unordered_set<position, pos_hash> visited;
        int rottenCounts = 0;
        int freshCounts = 0;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                switch (mat[r][c])
                {
                case 2:
                    exploreQ.push({r, c});
                    break;
                case 1:
                    freshCounts++;
                    break;
                }
            }
        }
        if (exploreQ.empty())
            return (freshCounts > 0) ? -1 : 0;
        vector<position> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!exploreQ.empty())
        {
            auto currentPosition = exploreQ.front();
            exploreQ.pop();
            int r, c;
            tie(r, c) = currentPosition;

            visited.insert(currentPosition);
            time = max(time, mat[r][c]);

            for (position p : dirs)
            {
                int dr, dc;
                tie(dr, dc) = p;
                int sr{r - dr}, sc{c - dc};
                if (sr >= 0 and sc >= 0 and sr < rows and sc < cols and mat[sr][sc] > 0 and mat[sr][sc] < 2 and visited.find({sr, sc}) == visited.end())
                {
                    ++rottenCounts;
                    mat[sr][sc] = mat[r][c] + 1;
                    exploreQ.push({sr, sc});
                }
            }
        }
        // cout << "Rotten Counts: " << rottenCounts << endl;
        // cout << "Fresh Counts: " << freshCounts << endl;
        return (rottenCounts == freshCounts) ? time - 2 : -1;
    }
};

int main(int argc, char const *argv[])
{
    auto printArray = [](vector<vector<int>> &M)
    {
        for (auto r : M)
        {
            for (auto c : r)
                cout << c << ", ";
            cout << endl;
        }
    };
    vector<vector<int>> test{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    // vector<vector<int>> answers{{2, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 2, 2, 1}, {1, 1, 1, 0, 0, 1, 2, 2, 1, 0}, {0, 1, 2, 1, 0, 1, 2, 3, 2, 1}, {0, 0, 1, 2, 1, 2, 1, 2, 1, 0}, {1, 1, 2, 3, 2, 1, 0, 1, 1, 1}, {0, 1, 2, 3, 2, 1, 1, 0, 0, 1}, {1, 2, 1, 2, 1, 0, 0, 1, 1, 2}, {0, 1, 0, 1, 1, 0, 1, 2, 2, 3}, {1, 2, 1, 0, 1, 0, 1, 2, 3, 4}};

    Solution solution;
    cout << "Input: " << endl;
    printArray(test);
    cout << "Output: " << endl;
    int time = solution.orangesRotting(test);
    printArray(test);
    cout << "Time: " << time << endl;

    // cout << "Answers: " << endl;
    // printArray(answers);
    return 0;
}
