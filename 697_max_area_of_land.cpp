#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

using Pos = std::pair<int, int>;

size_t exploreRegion(vector<vector<int>> &image, const Pos &start, bool (*isValid)(const int &))
{
    queue<Pos> exploreQ;
    exploreQ.push(start);
    int area = 0;
    int h = size(image);
    int w = size(image[0]);

    while (!exploreQ.empty())
    {
        Pos curPos = exploreQ.front();
        auto sr = curPos.first, sc = curPos.second;
        exploreQ.pop();

        if (image[sr][sc] < 1)
        {
            // Skip this position, already visited
            continue;
        }

        // Check Up
        if (sr > 0 && isValid(image[sr - 1][sc]))
            exploreQ.push(Pos({sr - 1, sc}));

        // Check Down
        if (sr < h - 1 && isValid(image[sr + 1][sc]))
            exploreQ.push(Pos({sr + 1, sc}));

        // Check Left
        if (sc > 0 && isValid(image[sr][sc - 1]))
            exploreQ.push(Pos({sr, sc - 1}));

        // Check Right
        if (sc < w - 1 && isValid(image[sr][sc + 1]))
            exploreQ.push(Pos({sr, sc + 1}));

        // }
        area++;
        image[sr][sc] = -1;
    }
    return area;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    size_t maxArea = 0;
    auto isValid = [](const int &val)
    { return val > 0; };

    size_t h{grid.size()}, w{grid[0].size()};
    for (size_t sr = 0; sr < h; sr++)
    {
        for (size_t sc = 0; sc < w; sc++)
        {
            // Skip if invalid or visited
            if (!isValid(grid[sr][sc]))
                continue;
            // Get current position
            Pos curPos{sr, sc};
            size_t area = exploreRegion(grid, curPos, isValid);
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
