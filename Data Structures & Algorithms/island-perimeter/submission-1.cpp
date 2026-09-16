class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int w = grid[0].size();
        const int h = grid.size();

        int p = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (!grid[y][x]) continue;

                p += 4;

                if (x && grid[y][x - 1]) p -= 2;
                if (y && grid[y - 1][x]) p -= 2;
            }
        }
        return p;
    }
};