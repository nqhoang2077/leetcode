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
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        auto rows{mat.size()}, cols{mat[0].size()};
        vector<vector<int>> result{rows};
        queue<position> exploreQ;
        unordered_set<position, pos_hash> visited;

        for (int r = 0; r < rows; r++)
        {
            result[r] = vector<int>(cols, -1);
            for (int c = 0; c < cols; c++)
            {
                if (mat[r][c] == 0)
                {

                    exploreQ.push({r, c});
                    result[r][c] = 0;
                }
            }
        }
        vector<position> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!exploreQ.empty())
        {
            auto currentPosition = exploreQ.front();
            exploreQ.pop();
            int r, c;
            tie(r, c) = currentPosition;
            if (visited.find(currentPosition) != visited.end())
                continue;
            visited.insert(currentPosition);
            for (position p : dirs)
            {
                int dr, dc;
                tie(dr, dc) = p;
                int sr{r - dr}, sc{c - dc};
                if (sr >= 0 and sc >= 0 and sr < rows and sc < cols and result[sr][sc] == -1)
                {
                    result[sr][sc] = result[r][c] + 1;
                    exploreQ.push({sr, sc});
                }
            }
        }
        mat.swap(result);
        return mat;
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
    vector<vector<int>> test{{1, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 1, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1}, {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}, {0, 1, 0, 1, 1, 0, 1, 1, 1, 1}, {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};
    vector<vector<int>> answers{{2, 1, 0, 0, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 1, 0, 1, 1, 2, 2, 1}, {1, 1, 1, 0, 0, 1, 2, 2, 1, 0}, {0, 1, 2, 1, 0, 1, 2, 3, 2, 1}, {0, 0, 1, 2, 1, 2, 1, 2, 1, 0}, {1, 1, 2, 3, 2, 1, 0, 1, 1, 1}, {0, 1, 2, 3, 2, 1, 1, 0, 0, 1}, {1, 2, 1, 2, 1, 0, 0, 1, 1, 2}, {0, 1, 0, 1, 1, 0, 1, 2, 2, 3}, {1, 2, 1, 0, 1, 0, 1, 2, 3, 4}};

    Solution solution;
    cout << "Input: " << endl;
    printArray(test);
    cout << "Output: " << endl;
    solution.updateMatrix(test);
    printArray(test);

    cout << "Answers: " << endl;
    printArray(answers);
    return 0;
}
