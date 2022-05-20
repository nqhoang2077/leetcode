#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;
using Pos = std::pair<int, int>;

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

// Using queue instead of vector can triple the performance if we only care about the insertion and deletion of one element at a time
queue<Pos> getExplorable(vector<vector<int>> &image, Pos pos)
{
    queue<Pos> result;
    int sr = pos.first, sc = pos.second;
    int h = size(image);
    int w = size(image[0]);

    int color = image[sr][sc];
    // Check Up
    if (sr > 0 && image[sr - 1][sc] == color)
        result.push(Pos({sr - 1, sc}));

    // Check Down
    if (sr < h - 1 && image[sr + 1][sc] == color)
        result.push(Pos({sr + 1, sc}));

    // Check Left
    if (sc > 0 && image[sr][sc - 1] == color)
        result.push(Pos({sr, sc - 1}));

    // Check Right
    if (sc < w - 1 && image[sr][sc + 1] == color)
        result.push(Pos({sr, sc + 1}));

    return result;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    queue<Pos> exploreQ;
    unordered_set<Pos, pos_hash> visitedPos;
    Pos start{sr, sc};
    exploreQ.push(start);

    while (!exploreQ.empty())
    {
        Pos curPos = exploreQ.front();
        exploreQ.pop();

        if (visitedPos.find(curPos) != visitedPos.end())
            continue;

        auto newExplore = getExplorable(image, curPos);
        while (!newExplore.empty())
        {
            exploreQ.push(newExplore.front());
            newExplore.pop();
        }

        visitedPos.insert(curPos);
    }
    for (auto pos : visitedPos)
        image[pos.first][pos.second] = newColor;

    return image;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int newColor = 2;

    floodFill(image, sr, sc, newColor);

    for (auto r : image)
    {
        for (auto c : r)
        {
            cout << c << ", ";
        }
        cout << endl;
    }

    return 0;
}
