class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int w = grid[0].size();
        const int h = grid.size();

        int p = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (!grid[y][x]) continue;

                if (y + 1 >= h || !grid[y + 1][x]) ++p;
                if (y - 1 < 0 || !grid[y - 1][x]) ++p;
                if (x + 1 >= w || !grid[y][x + 1]) ++p;
                if (x - 1 < 0 || !grid[y][x - 1]) ++p;
            }
        }
        return p;
    }
};