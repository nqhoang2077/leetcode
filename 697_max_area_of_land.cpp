#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

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

queue<Pos> getExplorable(vector<vector<int>> &image, const Pos &pos, bool (*isValid)(const int &))
{
    queue<Pos> result;
    int sr = pos.first, sc = pos.second;
    int h = size(image);
    int w = size(image[0]);

    // Check Up
    if (sr > 0 && isValid(image[sr - 1][sc]))
        result.push(Pos({sr - 1, sc}));

    // Check Down
    if (sr < h - 1 && isValid(image[sr + 1][sc]))
        result.push(Pos({sr + 1, sc}));

    // Check Left
    if (sc > 0 && isValid(image[sr][sc - 1]))
        result.push(Pos({sr, sc - 1}));

    // Check Right
    if (sc < w - 1 && isValid(image[sr][sc + 1]))
        result.push(Pos({sr, sc + 1}));

    return result;
}

size_t exploreRegion(vector<vector<int>> &image, const Pos &start, bool (*isValid)(const int &), void (*updateOperation)(int &old, const int &update))
{
    queue<Pos> exploreQ;
    unordered_set<Pos, pos_hash> visitedPos;
    exploreQ.push(start);

    while (!exploreQ.empty())
    {
        Pos curPos = exploreQ.front();
        exploreQ.pop();

        if (visitedPos.find(curPos) != visitedPos.end())
        {
            // Skip this position, already visited
            continue;
        }

        auto newExplore = getExplorable(image, curPos, isValid);
        while (!newExplore.empty())
        {
            exploreQ.push(newExplore.front());
            newExplore.pop();
        }
        // for (auto pos : newExplore)
        //     exploreQ.push(pos);

        visitedPos.insert(curPos);
    }
    size_t area = visitedPos.size();
    for (auto pos : visitedPos)
        updateOperation(image[pos.first][pos.second], -area);
    return area;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    size_t maxArea = 0;
    auto isValid = [](const int &val)
    { return val > 0; };

    auto updateOpr = [](int &old, const int &update)
    {old = update;};

    size_t h{grid.size()}, w{grid[0].size()};
    for (size_t sr = 0; sr < h; sr++)
    {
        for (size_t sc = 0; sc < w; sc++)
        {
            // Get current position
            Pos curPos{sr, sc};
            // Skip if invalid or visited
            if (!isValid(grid[sr][sc]))
                continue;
            size_t area = exploreRegion(grid, curPos, isValid, updateOpr);
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    // exploreRegion(grid, Pos{4, 9}, isValid, updateOpr);

    cout << maxAreaOfIsland(grid) << endl;


    for (size_t sr = 0; sr < grid.size(); sr++)
    {
        for (size_t sc = 0; sc < grid[sr].size(); sc++)
        {
            cout << grid[sr][sc] << "\t\t";
        }
        cout << endl;
    }

    return 0;
}
