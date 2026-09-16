class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int w = grid[0].size();
        const int h = grid.size();

        vis.resize(h, std::vector<bool>(w));

        int p = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (grid[y][x]) p += dfs(x, y, grid);
            }
        }
        return p;
    }

private:
    int dfs(int x, int y, const vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= grid[0].size() ||
            y >= grid.size() || !grid[y][x]) {
            return 1;
        }
        if (vis[y][x]) return 0;
        
        vis[y][x] = true;

        return dfs(x + 1, y, grid) + dfs(x, y + 1, grid) +
            dfs(x - 1, y, grid) + dfs(x, y - 1, grid);
    }

    std::vector<std::vector<bool>> vis;
};