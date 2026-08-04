class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        const int h = grid.size();
        const int w = grid[0].size();

        grid[h - 1][w - 1] = !grid[h - 1][w - 1];

        for (int y = h - 1; y >= 0; --y) {
            for (int x = w - 1; x >= 0; --x) {
                if (x == w - 1 && y == h - 1) continue;
                if (!grid[y][x]) {
                    if (x + 1 < w) grid[y][x] += grid[y][x + 1];
                    if (y + 1 < h) grid[y][x] += grid[y + 1][x];
                } else {
                    grid[y][x] = 0;
                }
            }
        }
 
        return grid[0][0];
    }
};